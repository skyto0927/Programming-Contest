#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

void dfs(int pos, int from, vector<vector<int>>& G, vector<int>& A, vector<int>& dp, stack<pair<int,int>>& dpr, vector<int>& ans){
    auto itr = lower_bound(ALL(dp), A[pos]);
    int it = itr - dp.begin();
    dpr.push(make_pair(it, *itr));
    dp[it] = A[pos];

    auto lis = lower_bound(ALL(dp), INF);
    int ls = lis - dp.begin();
    ans[pos] = ls;

    for(auto next: G[pos]){
        if (next == from){
            continue;
        }else{
            dfs(next, pos, G, A, dp, dpr, ans);
            auto p = dpr.top();
            dpr.pop();
            dp[p.first] = p.second;
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i,N){
        cin >> A[i];
    }

    vector<vector<int>> G(N);
    REP(i,N-1){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> ans(N,0);
    vector<int> dp(N, INF);
    stack<pair<int,int>> dpr;
    dfs(0, -1, G, A, dp, dpr, ans);

    REP(i,N){
        cout << ans[i] << endl;
    }
    return 0;
}