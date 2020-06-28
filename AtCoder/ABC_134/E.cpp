#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> A(N);
    vector<int> B;
    for(int i=0; i<N; i++){
        cin >> A[i];
        if (i==0){
            B.append(A[i]);
        }
        if(i!=0 && A[i-1]>=A[i]){
            
        }
    }
}
