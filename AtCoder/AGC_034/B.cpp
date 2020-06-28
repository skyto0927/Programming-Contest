#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;


int main(){
    const int N = 200000;
    char S[N];
    scanf("%s", S);

    int a_count = 0;
    long int sum = 0;
    int flag = 0;

    for (int i=0; i<N; i++){
        if (S[i] == 'A'){
            switch(flag){
                case 0:
                    flag = 1;
                    a_count++;
                    break;
                case 1:
                    a_count++;
                    break;
                case 2:
                    a_count = 1;
                    flag = 1;
                    break;
                case 3:
                    flag = 1;
                    a_count++;
                    break;
            }
        }
        else if (S[i] == 'B'){
            switch(flag){
                case 0:
                    break;
                case 1:
                    flag = 2;
                    break;
                case 2:  
                    a_count = 0;
                    flag=0;
                    break;
                case 3:
                    flag = 2;
                    break;
            }
        }
        else if (S[i] == 'C'){
            switch(flag){
                case 0:
                    break;
                case 1:
                    a_count = 0;
                    flag = 0;
                    break;
                case 2:
                    sum += a_count;
                    flag = 3;  
                    break;
                case 3:
                    a_count = 0;
                    flag = 0;
                    break;
            }
        }
        else{
            a_count = 0;
            flag = 0;
        };
    }
    printf("%ld", sum);
    return 0;
}