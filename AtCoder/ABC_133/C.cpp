#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;


int main(){
    int L,R;

    int l,r;
    scanf("%d %d", &L, &R);
    if((R-L)>=2019){
        printf("0");
        return 0;
    }

    l = L%2019;
    r = R%2019;

    if((l-r)>=0){
        printf("0");
        return 0;
    }
    
    int min = 2018;
    int cal;
    for(int i=l; i<=r-1; i++){
        for(int j=l+1; j<=r; j++){
            cal = (i*j)%2019;
            if (min > cal){
                min = cal;
            }
        }
    }
    printf("%d",min);
    return 0;
}