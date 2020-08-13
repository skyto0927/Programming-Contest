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
    vector<int> sa;
    int sum = 0;
    REPR(i,S.size()-1){
        if(S[i]=='+'){
            sum++;
        }else if(S[i]=='-'){
            sum--;
        }else{
            sa.push_back(sum);
        }
    }
    sort(ALL(sa));
    ll ans = 0;
    REP(i,sa.size()){
        if(i < sa.size()/2){
            ans -= sa[i];
        }else{
            ans += sa[i];
        }
    }cout << ans << endl;
    return 0;
}