#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

using mint = modint1000000007;

int dfs(vector<vector<int>> &G, vector<int> &cnt, int from, int pos){
    int ans = 1;
    for(auto next: G[pos]){
        if(next==from) continue;
        ans += dfs(G,cnt,pos,next);
    }
    return cnt[pos] = ans;
}

int main() {
    int N; cin >> N;
    vector<vector<int>> G(N);
    REP(i,N-1){
        int a,b; cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> cnt(N,0);
    dfs(G,cnt,-1,0);

    mint ans = 0;
    REP(i,N){
        mint sum = mint(2).pow(N-1);
        sum -= 1;
        for(int to: G[i]){
            int c = (cnt[i]>cnt[to]?cnt[to]:N-cnt[i]);
            sum -= mint(2).pow(c)-1;
        }
        ans += sum;
        //cout << sum.val() << endl;
    }
    
    cout << (ans/mint(2).pow(N)).val() << endl;
    return 0;
}