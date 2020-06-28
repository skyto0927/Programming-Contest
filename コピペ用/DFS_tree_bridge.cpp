#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    return 0;
}
///////////////////////////////////////////////////////

int dfs(vector<vector<int>>& g, vector<pair<int,int>>& res, int v, 
    int& count, int from, vector<int>& low, vector<int>& pre){
    pre[v] = count++;
    low[v] = pre[v];

    for(auto to: g[v]){
        if(pre[to] == -1){//未到達なら
            low[v] = min(low[v], dfs(g,res,to,count,v,low,pre));
            if(low[to] == pre[to]){
                res.push_back(make_pair(v,to));
            }
        }else{
            if(from == to){//来た道にはもどらない
                continue;
            }
            low[v] = min(low[v], low[to]);
        }
    }
    return low[v];
}

vector<pair<int,int>> bridges(vector<vector<int>>& g, int V){
    vector<pair<int,int>> res;
    if(V>0){
        vector<int> pre(V,-1);
        vector<int> low(V,-1);
        int count = 0;
        dfs(g,res,0,count,-1,low,pre);
    }
    return res;
}