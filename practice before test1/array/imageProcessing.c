#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    int bitDepth;
    unsigned char header[54];
    unsigned char ***data;
} BMPImage;

unsigned char*** allocateImage(int height, int width) {
    unsigned char ***image = malloc(height * sizeof(unsigned char**));
    for (int i = 0; i < height; i++) {
        image[i] = malloc(width * sizeof(unsigned char*));
        for (int j = 0; j < width; j++) {
            image[i][j] = malloc(3 * sizeof(unsigned char));
        }
    }
    return image;
}

void freeImage(unsigned char ***image, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            free(image[i][j]);
        }
        free(image[i]);
    }
    free(image);
}

BMPImage readBMP(const char *filename) {
    BMPImage img;
    FILE *fIn = fopen(filename, "rb");
    if (fIn == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fread(img.header, sizeof(unsigned char), 54, fIn);
    
    img.width = *(int*)&img.header[18];
    img.height = *(int*)&img.header[22];
    img.bitDepth = *(int*)&img.header[28];

    printf("Reading Image: %s\n", filename);
    printf("Width: %d, Height: %d, Bit Depth: %d\n", img.width, img.height, img.bitDepth);

    int row_padded = (img.width * 3 + 3) & (~3); 
    unsigned char row[row_padded];

    img.data = allocateImage(img.height, img.width);

    for (int i = 0; i < img.height; i++) {
        fread(row, sizeof(unsigned char), row_padded, fIn);
        for (int j = 0; j < img.width; j++) {
            img.data[i][j][2] = row[j * 3];     
            img.data[i][j][1] = row[j * 3 + 1]; 
            img.data[i][j][0] = row[j * 3 + 2]; 
        }
    }

    fclose(fIn);
    return img;
}

void writeBMP(const char *filename, BMPImage img) {
    FILE *fOut = fopen(filename, "wb");
    if (fOut == NULL) {
        printf("Error: Unable to create file.\n");
        exit(1);
    }

    fwrite(img.header, sizeof(unsigned char), 54, fOut);

    int row_padded = (img.width * 3 + 3) & (~3);
    unsigned char row[row_padded];

    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            row[j * 3] = img.data[i][j][2];     // Blue
            row[j * 3 + 1] = img.data[i][j][1]; // Green
            row[j * 3 + 2] = img.data[i][j][0]; // Red
        }
        fwrite(row, sizeof(unsigned char), row_padded, fOut);
    }

    fclose(fOut);
    printf("Image saved: %s\n", filename);
}

void flipImageHorizontally(BMPImage *img) {     //flipImageHor(&img);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width / 2; j++) {
            // สลับพิกเซลฝั่งซ้ายกับฝั่งขวาของแถว
            unsigned char temp[3];
            temp[0] = img->data[i][j][0]; // Red
            temp[1] = img->data[i][j][1]; // Green
            temp[2] = img->data[i][j][2]; // Blue

            img->data[i][j][0] = img->data[i][img->width - j - 1][0];
            img->data[i][j][1] = img->data[i][img->width - j - 1][1];
            img->data[i][j][2] = img->data[i][img->width - j - 1][2];

            img->data[i][img->width - j - 1][0] = temp[0];
            img->data[i][img->width - j - 1][1] = temp[1];
            img->data[i][img->width - j - 1][2] = temp[2];
        }
    }
}


int main() {
    BMPImage img = readBMP("trump.bmp"); // อ่านภาพต้นฉบับ

    flipImageHorizontally(&img); // กลับภาพในแนวนอน

    writeBMP("output.bmp", img); // บันทึกภาพใหม่
    freeImage(img.data, img.height, img.width); // คืนหน่วยความจำ
    return 0;
}
