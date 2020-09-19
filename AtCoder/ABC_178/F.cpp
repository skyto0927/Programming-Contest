#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N,0), B(N,0);

    REP(i,N) cin >> A[i];
    REP(i,N) cin >> B[i];
    sort(ALL(B), greater<int>());

    int itr = 0;
    REP(i,N){
        if(A[i] == B[i]){
            while(A[itr]==B[i] || B[itr]==B[i]){
                if(itr == N-1){
                    cout << "No" << endl;
                    return 0;
                }
                itr++;
            }
            swap(B[i],B[itr]);
        }
    }
    cout << "Yes" << endl;
    REP(i,N) cout << B[i] << " ";
    cout << endl;
    return 0;
}