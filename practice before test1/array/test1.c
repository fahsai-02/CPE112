//เครื่องพิมพ์หมึกหมด
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width; //ความกว้าง
    int height; //ความสูง
    int bitDepth; //จำนวนบิตต่อพิกเซล
    unsigned char header[54]; //ข้อมูลส่วนหัวไฟล์
    unsigned char ***data; //ข้อมูลภาพเป็น matrix 3D
} BMPImage;

unsigned char*** allocateImage(int height, int width) {
    unsigned char ***image = malloc(height * sizeof(unsigned char**));
    for (int i = 0; i < height; i++) {
        image[i] = malloc(width * sizeof(unsigned char*));
        for (int j = 0; j < width; j++) {
            image[i][j] = malloc(3 * sizeof(unsigned char)); //จอง 3 ช่อง สำหรับ RGB
        }
    }
    return image;
}

void freeImage(unsigned char ***image, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            free(image[i][j]); //พิกเซล
        }
        free(image[i]); //แถว
    }
    free(image); //อาร์เรย์หลัก
}

BMPImage readBMP(const char *filename) {
    BMPImage img;
    FILE *fIn = fopen(filename, "rb"); //อ่านไฟล์แบบ binary
    if (fIn == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fread(img.header, sizeof(unsigned char), 54, fIn); //อ่าน header 54 bite

    img.width = *(int*)&img.header[18];
    img.height = *(int*)&img.header[22];
    img.bitDepth = *(int*)&img.header[28];

    printf("Reading Image: %s\n", filename);
    printf("Width: %d, Height: %d, Bit Depth: %d\n", img.width, img.height, img.bitDepth);

    int row_padded = (img.width * 3 + 3) & (~3); //ปรับขนาดแถวให้หารด้วย 4 ลง
    unsigned char *row = (unsigned char *)malloc(row_padded * sizeof(unsigned char));

    img.data = allocateImage(img.height, img.width); //จองหน่วยความจำ

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
    FILE *fOut = fopen(filename, "wb"); //เขียนไฟล์แบบ binary
    if (fOut == NULL) {
        printf("Error: Unable to create file.\n");
        exit(1);
    }

    fwrite(img.header, sizeof(unsigned char), 54, fOut); //เขียน header

    int row_padded = (img.width * 3 + 3) & (~3);
    unsigned char *row = (unsigned char *)malloc(row_padded * sizeof(unsigned char));

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

void convertToGrayscale(BMPImage *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            unsigned char red = img->data[i][j][0];
            unsigned char green = img->data[i][j][1];
            unsigned char blue = img->data[i][j][2];

            // คำนวณค่า Gray ตามสูตร
            unsigned char gray = (red + green + blue) / 3;

            // กำหนดค่า Gray ให้ทุกช่อง RGB เพื่อให้เป็นขาวดำ
            img->data[i][j][0] = gray;
            img->data[i][j][1] = gray;
            img->data[i][j][2] = gray;
        }
    }
}

void extractColorChannel(BMPImage img, const char *filename, char channel) {
    // สร้างภาพใหม่โดยคัดลอก header และข้อมูลขนาดภาพ
    BMPImage newImg;
    newImg.width = img.width;
    newImg.height = img.height;
    newImg.bitDepth = img.bitDepth;
    memcpy(newImg.header, img.header, 54); // คัดลอก header
    // จองหน่วยความจำใหม่สำหรับข้อมูลภาพ
    newImg.data = allocateImage(newImg.height, newImg.width);
    // คัดลอกข้อมูลพิกเซลและกำจัดสีที่ไม่ต้องการ
    for (int i = 0; i < newImg.height; i++) {
        for (int j = 0; j < newImg.width; j++) {
            newImg.data[i][j][0] = (channel == 'R') ? img.data[i][j][0] : 0; // Red
            newImg.data[i][j][1] = (channel == 'G') ? img.data[i][j][1] : 0; // Green
            newImg.data[i][j][2] = (channel == 'B') ? img.data[i][j][2] : 0; // Blue
        }
    }
    // บันทึกไฟล์
    writeBMP(filename, newImg);
    // คืนหน่วยความจำของภาพใหม่
    freeImage(newImg.data, newImg.height, newImg.width);
}

void addFrame(BMPImage *img, int xMin, int yMin, int xMax, int yMax, unsigned char r, unsigned char g, unsigned char b) {
    if (xMin < 0 || xMax >= img->width || yMin < 0 || yMax >= img->height || xMin >= xMax || yMin >= yMax) {
        printf("Invalid frame dimensions.\n");
        return;
    }
    
    int adjusted_yMin = img->height - yMax - 1;
    int adjusted_yMax = img->height - yMin - 1;

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            if (j < xMin || j > xMax || i < adjusted_yMin || i > adjusted_yMax) {
                img->data[i][j][0] = r;     
                img->data[i][j][1] = g; 
                img->data[i][j][2] = b; 
            }
        }
    }

    // Add labels to corners
    img->data[adjusted_yMin][xMin][0] = 255; // Red label for xMin, yMin
    img->data[adjusted_yMin][xMin][1] = 0;
    img->data[adjusted_yMin][xMin][2] = 0;

    img->data[adjusted_yMin][xMax][0] = 255; // Red label for xMax, yMin
    img->data[adjusted_yMin][xMax][1] = 0;
    img->data[adjusted_yMin][xMax][2] = 0;

    img->data[adjusted_yMax][xMin][0] = 255; // Red label for xMin, yMax
    img->data[adjusted_yMax][xMin][1] = 0;
    img->data[adjusted_yMax][xMin][2] = 0;

    img->data[adjusted_yMax][xMax][0] = 255; // Red label for xMax, yMax
    img->data[adjusted_yMax][xMax][1] = 0;
    img->data[adjusted_yMax][xMax][2] = 0;
}

int main() {
    int xMin, yMin, xMax, yMax;
    unsigned char r, g, b;

    printf("Enter xMin, yMin, xMax, yMax, r, g, b: ");
    scanf("%d %d %d %d", &xMin, &yMin, &xMax, &yMax);
    scanf(" %hhu %hhu %hhu", &r, &g, &b);

    BMPImage img = readBMP("trump.bmp");
    
    printf("Image Size: Width=%d, Height=%d\n", img.width, img.height);
    printf("Using frame: xMin=%d, yMin=%d, xMax=%d, yMax=%d\n", xMin, yMin, xMax, yMax);
    
    addFrame(&img, xMin, yMin, xMax, yMax, r, g, b);
    
    writeBMP("output.bmp", img);
    freeImage(img.data, img.height, img.width);
    
    return 0;
}

    


// int main() {

//     BMPImage img = readBMP("trump.bmp"); //อ่านBMP

//     // สร้างภาพที่มีเฉพาะแต่ละสี
//     extractColorChannel(img, "red_output.bmp", 'R');   // รูปเฉพาะสีแดง
//     extractColorChannel(img, "green_output.bmp", 'G'); // รูปเฉพาะสีเขียว
//     extractColorChannel(img, "blue_output.bmp", 'B');  // รูปเฉพาะสีน้ำเงิน
//     convertToGrayscale(&img);
    
//     writeBMP("output5.bmp", img); //บันทึกภาพใหม่
//     freeImage(img.data, img.height, img.width); //คืนความจำ
//     return 0;

// }
