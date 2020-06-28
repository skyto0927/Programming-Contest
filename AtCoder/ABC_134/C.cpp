#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> A(N);
    int max = 0;
    int second = 0;
    int index = 0;
    for(int i=0; i<N; i++){
        cin >> A[i];
        if (max < A[i]){
            max = A[i];
            index = i;
        }
    }
    for(int i=0; i<N; i++){
        if (i != index && second < A[i]){
            second = A[i];
        }
    }
    for(int i=0; i<N; i++){
        if (i == index){
            printf("%d\n",second);
        }else{
            printf("%d\n",max);
        }
    }

}
