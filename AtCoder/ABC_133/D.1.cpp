#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;


int main(){
    int N;
    scanf("%d", &N);
    long int a[N];
    long int ans=0;

    for(int i=0; i<N-1; i++){
        scanf("%ld ",&a[i]);
    }
    scanf("%ld",&a[N-1]);
    
    int flag=0;
    for(int i=0; i<N; i++){
        flag = 0;
        ans = 0;
        for(int j=i; j<i+N; j++){
            switch (flag){
            case 0:
                ans += a[j%N];
                flag = 1;
                break;
            case 1:
                ans -= a[j%N];
                flag =0;
                break;
            }
        
        }
        printf("%ld",ans);
        if(i!=N-1){
            printf(" ");
        }
    }
    
}