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
    string s; cin >> s;
    string ans;
    int itr = 0;
    REP(i,s.size()){
        if(s[i] == 'B'){
            itr = max(0,itr-1);
        }else{
            ans[itr] = s[i];
            itr++;
        }
    }
    REP(i,itr){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}