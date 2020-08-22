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
    int n = s.size();
    string ans;
    char cur = s[0];
    int cnt = 0;
    REP(i,n){
        if(s[i] == cur) cnt++;
        else{
            ans.push_back(cur);
            ans += to_string(cnt);
            cur = s[i];
            cnt = 1;
        }
    }
    ans.push_back(cur);
    ans += to_string(cnt);
    cout << ans << endl;
    return 0;
}