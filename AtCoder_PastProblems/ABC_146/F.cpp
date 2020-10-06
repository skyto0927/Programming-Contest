#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N,M; cin >> N >> M;
    string S; cin >> S;
    reverse(ALL(S));

    vector<int> ans;
    int l = 0;
    while(l!=N){
        int r = min(N, l+M);
        while(1){
            if(l==r){
                cout << -1 << endl;
                return 0;
            }
            if(S[r]=='0'){
                ans.push_back(r-l);
                break;
            }
            r--;
        }
        l = r; 
    }

    reverse(ALL(ans));
    for(auto a: ans){
        cout << a << " ";
    }
    cout<< endl;
    return 0;
}