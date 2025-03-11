// 67070501064 Nakagamon Saengs
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, index;   //index = 0,1   n = size of array
    scanf("%d",&n);
    int *num = calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", num+i);
    }
    scanf("%d", &index);

    if(index == 1){
        if(n <= 1){
            printf("none");
        }
        for(int i = 1; i < n; i += 2){
            printf("%d ", *(num+i));
        }
    }
    else if (index == 0)
    {
        for(int i = 0; i < n; i += 2){
            printf("%d ", *(num+i));
        }
    }
    else{
        printf("none");
    }
    
    free(num);
    return 0;
}