#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

const int MOD = 1e9+7;

int main() {
    int N; cin >> N;
    string s1,s2; cin >> s1 >> s2;

    vector<int> m;//0で縦、1で横
    REP(i,s1.size()-1){
        if(s1[i] != s1[i+1]){
            m.push_back(0);
        }else{
            m.push_back(1);
            i++;
        }
    }
    if(s1[N-1] == s2[N-1]) m.push_back(0);

    ll ans = 1;
    REP(i,m.size()){
        if(i==0){
            if(m[0]==0){
                ans = 3;
            }else{
                ans = 6;
            }
        }else{
            if(m[i-1]==1 && m[i]==0){
                ans *= 1;
                ans %= MOD;
            }else if(m[i-1]==1 && m[i]==1){
                ans *= 3;
                ans %= MOD;
            }else{
                ans *= 2;
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;

    return 0;
}