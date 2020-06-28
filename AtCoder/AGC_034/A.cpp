#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;

int main(){
    int N,A,B,C,D;
    scanf("%d %d %d %d %d", &N, &A, &B, &C, &D);

    char S[N];
    scanf("%s", S);

    if(C<D && B<C){
        for(int i=A; i<=D-1; i++){
            if (S[i] == '#'){
                if (S[i+1] == '#'){
                    printf("No");
                    return 0;
                }
            }
        }
        printf("Yes");
        return 0;
    }
    else if(D<C && B<D){
        for(int i=A; i<=C-1; i++){
            if (S[i] == '#'){
                if (S[i+1] == '#'){
                    printf("No");
                    return 0;
                }
            }
        }
        for(int i=B-2; i<=D-2; i++){
            if (S[i] == '.'){
                if (S[i+1] == '.'){
                    if (S[i+2] == '.'){
                        printf("Yes");
                        return 0;
                    }
                }
            }
        }
        printf("No");
        return 0;
    }
    else if(C<D && C<B){
        for(int i=A; i<=C-1; i++){
            if (S[i] == '#'){
                if (S[i+1] == '#'){
                    printf("No");
                    return 0;
                }
            }
        }
        for(int i=B; i<=D-1; i++){
            if (S[i] == '#'){
                if (S[i+1] == '#'){
                    printf("No");
                    return 0;
                }
            }
        }
        printf("Yes");
        return 0;
    }
}