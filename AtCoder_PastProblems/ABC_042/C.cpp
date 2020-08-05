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
    int N,K; cin >> N >> K;
    vector<char> D(K);
    REP(i,K) cin >> D[i];
    FOR(i,N,100000){
        string s = to_string(i);
        bool ok = true;
        REP(j,s.size()){
            REP(k,K){
                if(D[k]==s[j]) ok = false;
            }
        }
        if(ok){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}