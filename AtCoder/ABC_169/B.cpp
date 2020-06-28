#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<double> A_log(N);
    bool including_zero = false;
    for (int i=0; i<N; i++){
        cin >> A[i];
        A_log[i] = log10(A[i]);
        if (A[i] == 0){
            including_zero = true;
        }
    }
    if (including_zero){
        cout << 0 << endl;
        return 0;
    }

    float mul_log = 0;
    for (int j=0; j<N; j++){
        mul_log += A_log[j];
        if (mul_log > 19.0){
            cout << -1 << endl;
            return 0;
        }
    }
    

    long long int mul = 1;
    for (int j=0; j<N; j++){
        mul *= A[j];
    }
    if (mul > 1000000000000000000){
            cout << -1 << endl;
            return 0;
        }
    cout << mul << endl;
        return 0;
}
