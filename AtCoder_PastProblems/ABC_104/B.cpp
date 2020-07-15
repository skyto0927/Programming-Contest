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
    string S; cin >> S;
    if(S[0] == 'A'){
        if(count(S.begin()+2, S.end()-1, 'C') == 1){
            int cnt = 0;
            REP(i,S.size()){
                if(isupper(S[i])) cnt++;
            }
            if(cnt == 2){
                cout << "AC" << endl;
                return 0;
            }
        }
    }
    cout << "WA" << endl;
    return 0;
}