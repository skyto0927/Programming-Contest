#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N+1);
    vector<int> B(N+1);
    for (int i=0; i<=N; i++){
        cin >> A[i];
    }
    for (int i=0; i<N; i++){
        cin >> B[i];
    }

    long int count = 0;
    for (int i=0; i<N; i++){
        if (A[i] >= B[i]){
            count += B[i];
        }else{
            B[i] -= A[i];
            count += A[i];

            if (A[i+1] >= B[i]){
                count += B[i];
                A[i+1] -= B[i];
            }else{
                count += A[i+1];
                A[i+1] = 0;
                
            }
        }
    }

    cout << count;
}
