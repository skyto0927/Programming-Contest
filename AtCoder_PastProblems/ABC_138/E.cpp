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
    string s,t; cin >> s >> t;
    vector<vector<int>> alpha(26);
    REP(i,s.size()){
        alpha[s[i]-'a'].push_back(i);
    }

    vector<int> t_num(t.size());

    if(alpha[t[0]-'a'].size() == 0){
        cout << -1 << endl;
        return 0;
    }
    t_num[0] = alpha[t[0]-'a'][0];
    FOR(i,1,t.size()){
        int n = t[i] - 'a';
        if(alpha[n].size() == 0){
            cout << -1 << endl;
            return 0;
        }
        auto itr = upper_bound(ALL(alpha[n]), t_num[i-1]);//一つ前より大きい最小の数字
        if(itr == alpha[n].end()) itr = alpha[n].begin();
        t_num[i] = *itr;
    }
    
    ll ans = 0;
    int num = -1;
    REP(i,t.size()){
        //cout << t_num[i] << endl;
        if(num < t_num[i]) num = t_num[i];
        else{
            ans += s.size();
            num = t_num[i];
        }
    }
    ans += num + 1;
    cout << ans << endl;
    return 0;
}