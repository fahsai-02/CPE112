//67070501064 Nakagamon Saengdara
#include <stdio.h>
#include <math.h>

void findPrimeNum(long int a,long int b){
    int k = 0;  //amout of primeNum
    int c = sqrt(b);
    if(a < 2 && b > 2){
        printf("2 ");
        k++;
    }
    if(a < 3 && b >3){
        printf("3 ");
        k++;
    }
    for(long int i = a+1; i < b; i++){
        for(long int j = 2; j <= (long int)(sqrt(i)); j++){
            if(i%j == 0){
                break;
            }else if (j == (long int)(sqrt(i))){
                printf("%ld ",i);
                k++;
            }
        }
    }
    if(k == 0){
        printf("none");
    }
}

int main(){
    long int a, b;
    scanf("%ld %ld",&a, &b);
    findPrimeNum(a, b);

    return 0;
}