#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;


int main(){

    int N, D;
    scanf("%d %d",&N,&D);
    int X[N][D];
    for(int i=0; i<N; i++){
        for(int j=0; j<D-1; j++){
            scanf("%d ",&X[i][j]);
        }
        scanf("%d",&X[i][D-1]);
    }

    int count = 0;
    int sum = 0;
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            for(int k=0; k<D; k++){
                sum += (int)pow((X[i][k]-X[j][k]),2);
            }
            for(int l=0; l<=sqrt(sum); l++){
                if ((int)pow(l,2) == sum){
                    count ++;
                    break;
                }
            }
            sum = 0;
        }
    }
    printf("%d", count);
}