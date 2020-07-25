#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<vector<pair<int,int>>> A(N, vector<pair<int,int>>(N));
    REP(i,N){
        REP(j,N){
            int a; cin >> a;
            A[i][j] = {a,0};
        }
    }

    REP(i,N-1){
        FOR(j,i+1,N){
            REP(k,N){
                if(i==k || j==k) continue;
                if(A[i][k].first+A[k][j].first < A[i][j].first){
                    cout << -1 << endl;
                    return 0;
                }else if(A[i][k].first+A[k][j].first == A[i][j].first){
                    A[i][j].second = 1;
                }
            }
        }
    }

    ll ans = 0;
    REP(i,N-1){
        FOR(j,i+1,N){
            if(A[i][j].second==0) ans += A[i][j].first;
        }
    }
    cout << ans << endl;
    return 0;
}