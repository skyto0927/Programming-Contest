#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int R, G, B, N;
    scanf("%d %d %d %d", &R, &G, &B, &N);

    int r, g, b;
    
    int count = 0;

    for (r=0; r*R<=N; r++){
        for (g=0; r*R + g*G<=N; g++){
            if( (N - r*R - g*G)%B == 0){

                count++;
            }
        }
    }

    printf("%d",count);
}