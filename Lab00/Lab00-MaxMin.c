//67070501064 Nakagamon Saengdara
#include <stdio.h>

int main(){
    long int max = -9999999;
    long int min = 9999999;
    int idxMax = 0, idxMin = 0;
    int num, idx = 1;

    while(1){
        scanf("%d",&num);
        if (num == -9999){
            break;
        }
        if (num > max)
        {
            max = num;
            idxMax = idx;
        }
        if (num < min)
        {
            min = num;
            idxMin = idx;
        }    
        idx++;
    }
    printf("%d %d\n%d %d", max, idxMax, min, idxMin);

}