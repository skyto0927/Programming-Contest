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
    string S; cin >> S;
    reverse(ALL(S));
    int i = 0;
    int N = S.size();
    while(i<N){
        if(N-i >= 5){
            string s = S.substr(i,5);
            if(s=="maerd" || s=="esare"){
                i += 5;
                continue;
            }
        }
        if(N-i >= 6){
            string s = S.substr(i,6);
            if(s=="resare"){
                i += 6;
                continue;
            }
        }
        if(N-i >= 7){
            string s = S.substr(i,7);
            if(s=="remaerd"){
                i += 7;
                continue;
            }
        }
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}