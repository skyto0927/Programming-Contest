#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


int main() {
    int N; cin >> N;
    vector<string> W(N);
    REP(i,N){
        cin >> W[i];
    }

    FOR(i,1,N){
        if(W[i][0] != W[i-1][W[i-1].size()-1]){
            cout << "No" << endl;
            return 0;
        }
        REP(j,i){
            if(W[j] == W[i]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}