#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    string S; cin >> S;
    FOR(i,1,S.size()/2){
        int N = (S.size()-2*i)/2;

        bool ok = true;
        REP(j,N){
            if(S[j] != S[N+j]) ok = false;
        }
        if(ok){
            cout << N*2 << endl;
            return 0;
        }
    }
    return 0;
}