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
    string S;
    S.push_back('+');
    string s; cin >> s;
    S += s;
    S.push_back('+');
    int ans = 0;
    bool flag = false;
    for(int i=1; i<=S.size(); i+=2){
        if(S[i-1]=='+' && S[i+1]=='+'){
            if(S[i]!='0') ans++;
        }
        else if(S[i-1]=='+' && S[i+1]=='*'){
            if(S[i]=='0') flag = true;
        }else if(S[i-1]=='*' && S[i+1]=='*'){
            if(S[i]=='0') flag = true;
        }else if(S[i-1]=='*' && S[i+1]=='+'){
            if(S[i]=='0') flag = true;
            if(!flag) ans++;
            flag = false;
        }
    }
    cout << ans << endl;
    return 0;
}