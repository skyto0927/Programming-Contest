#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,D;
    scanf("%d %d",&N, &D);

    int width;
    width = D*2 + 1;
    if(N%width == 0){
        printf("%d",N/width);
    }else{
        printf("%d", N/width + 1);
    }
    
}