#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    string S[N];
    int len[N];

    for (int i=0; i<N; i++){
        cin >> S[i];
        len[i] = (int)S[i].length();
    }

    int topB=0;
    int bottomA=0;
    int middle=0;
    int both = 0;
    int bothFlag = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<len[i]; j++){
            if(j==0 && S[i][j]=='B'){
                topB++;
                bothFlag = 1;
            }
            if(S[i][j]=='A' && j<len[i]-1){
                if(S[i][j+1]=='B'){
                middle++;
            }
            }
            if(j==len[i]-1 && S[i][j]=='A'){
                bottomA++;
                if (bothFlag == 1) both++;
            }

        }
        bothFlag = 0;
    }

    //printf("B:%d, A:%d, mid:%d, both:%d\n",topB,bottomA,middle,both);
    if (topB == bottomA && topB == both && topB != 0){
        printf("%d", middle + both - 1);
    }
    else if(topB < bottomA){
        printf("%d", middle + topB);
    }
    else if(topB >= bottomA){
        printf("%d", middle + bottomA);
    }


}