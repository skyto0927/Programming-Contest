#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    string S,T; cin >> S >> T;
    if(S.size() < T.size()){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    vector<string> ans;
    REP(i,S.size() - T.size()+1){
        bool ok = true;
        REP(j,T.size()){
            if(S[i+j]!='?'){
                if(S[i+j] != T[j]) ok = false;
            }
        }
        if(ok){
            string s = S;
            
            REP(j,T.size()){
                s[i+j] = T[j];
            }
            REP(k,s.size()){
                if(s[k]=='?') s[k] = 'a';
            }
            ans.push_back(s);
        }
    }
    if(ans.size() == 0){
        cout << "UNRESTORABLE" << endl;
    }else{
        sort(ALL(ans));
        cout << ans[0] << endl;
    }
    return 0;
}