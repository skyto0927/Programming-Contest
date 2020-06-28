#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

struct UnionFind{
    vector<int> data;
    //data[i] = -x ... iが根であり、サイズがx
    //data[i] = x ... iの親がx

    //最初は全員根
    UnionFind(int size): data(size,-1){}

    bool union_set(int x, int y){//サイズがx>yになるようにしてから、xにyをつなげる
        x=root(x);
        y=root(y);
        if(x != y){
            if(data[y] < data[x]) swap(x,y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool find_set(int x, int y){//ルートが一致するかどうかを返す
        return root(x) == root(y);
    }
    int root(int x){//根を見つける。ついでに深さ2にしちゃう
        return data[x]<0 ? x : data[x]=root(data[x]);
    }
    int size(int x){
        return -data[root(x)];
    }
};

struct Edge{
    int s,t,cost;
    bool operator<(const Edge &o) const{
        return cost < o.cost;
    }
};

int dfs(vector<vector<int>>& g, vector<pair<int,int>>& res, int v, 
    int& count, int from, vector<int>& low, vector<int>& pre){
    pre[v] = count++;
    low[v] = pre[v];

    //無向グラフでも最初に選択した向きのみの有向として考えてる
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


int main() {
    int N,M; cin >> N >> M;
    vector<vector<int>> G(N);

//DFS
    REP(i,M){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector <pair<int,int>> bridge_num = bridges(G,N);
    cout << bridge_num.size() << endl;

//UnionFind
    // int ans = 0;
    // REP(i,M){
    //     UnionFind uf(N);
    //     REP(j,M){
    //         if(i!=j){
    //             uf.union_set(a[j], b[j]);
    //         }
    //     }
    //     if(!uf.find_set(a[i],b[i])){
    //         ans++;
    //     }
    // }
    // cout << ans << endl;
    // return 0;




    return 0;
}