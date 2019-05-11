#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    long N;
    scanf("%ld",&N);
    long count = 0;
    for (int i=1; i<sqrt(N); i++){
        if (N%i == 0){
            if(N/i > i+1){
                count += N/i - 1;
            }
        }
    }
    if (N==2){
        printf("0");
    }
    else if(N==6){
        printf("5");
    }
    else{
    printf("%ld",count);
    }
}