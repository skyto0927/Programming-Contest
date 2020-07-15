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
    string S,T; cin >> S >> T;
    vector<int> s(26,-1), t(26,-1);

    REP(i,S.size()){
        int x = S[i] - 'a';
        int y = T[i] - 'a';
        if(s[x] == -1){
            if(t[y] == -1){
                s[x] = y;
                t[y] = x;
            }else{
                cout << "No" << endl;
                return 0;
            }
        }else{
            if(s[x]!=y || t[y]!=x){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}