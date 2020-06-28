#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;


int main(){
    int N;
    scanf("%d", &N);
    long int a[N];
    long int sum=0;

    for(int i=0; i<N-1; i++){
        scanf("%ld ",&a[i]);
        sum += a[i];
    }
    scanf("%ld",&a[N-1]);
    sum += a[N-1];
    sum /= 2;

    long int ans=0;
    for (int i=0; i<N; i++){
        ans = sum;
        for(int j=0; j<(N-1)/2; j++){
            ans -= a[(1+i+2*j)%N];
        }
        printf("%ld",2*ans);
        if(i != N-1){
            printf(" ");
        }
    }
    
}