// 67070501064 Nakagamon Saengdara
#include <stdio.h>
#include <stdlib.h>

void printArrray(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr+i));
    }
}

int *insertArray(int* arr, int *size, int index, int value){
    if(index <= *size){
        *size += 1;
        arr = realloc(arr, (*size)*sizeof(int));
        for(int i = *size-1; i > index; i--){
            *(arr+i) = *(arr+i-1);
        }
        *(arr+index) = value;
        printArrray(arr, *size);
        return arr;
    }
    else{
        printf("Index out of bounds");
        return arr;
    }
}

int *deleteArray(int *arr, int *size, int index){
    if(index < *size){
        *size -= 1;
        for(int i = index; i < *size; i++){
            *(arr+i) = *(arr+i+1);
        }
        arr = realloc(arr, (*size)*sizeof(int));
        printArrray(arr, *size);
        return arr;    
        }
    else{
        printf("Index out of bounds");
        return arr;
    }
}

int *mergeArrary(int *arr1, int size1, int* arr2, int size2){
    arr1 = realloc(arr1, (size1+size2-1)*sizeof(int));
    int j=0;
    for(int i = size1; i <= size1+size2-1; i++){
        *(arr1+i) = *(arr2+j);
        j++;
    }
    return arr1;
}

int main(){
    int n1, n2, i, numi, j;
    scanf("%d", &n1);
    int *arr1 = calloc(n1, sizeof(int));
    for(int k = 0; k < n1; k++){
        scanf("%d", (arr1+k));
    }
    scanf("%d", &n2);
    int *arr2 = calloc(n2, sizeof(int));
    for(int k = 0; k < n2; k++){
        scanf("%d", (arr2+k));
    }
    scanf("%d", &i);
    scanf("%d", &numi);
    scanf("%d", &j);

    arr1 = insertArray(arr1, &n1, i, numi);
    // for(int i = 0; i < n1; i++){
    //         printf("%de ", *(arr1+i));
    //     }
    printf("\n");
    arr1 = deleteArray(arr1, &n1, j);
    printf("\n");
    arr1 = mergeArrary(arr1, n1, arr2, n2);
    printArrray(arr1, n1+n2);

    free(arr1);
    free(arr2);
    return 0;
}