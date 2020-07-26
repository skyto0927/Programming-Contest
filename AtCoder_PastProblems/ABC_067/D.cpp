#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

vector<vector<int>> G;
vector<int> way;
int N;

bool dfs(int from, int pos){
    if(pos == N-1){
        way.push_back(N-1);
        return true;
    }
    
    for(auto next: G[pos]){
        if(next == from) continue;

        if(dfs(pos,next)){
            way.push_back(pos);
            return true;
        }
    }
    return false;
}

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

int main() {
    cin >> N;
    G.assign(N,{});
    vector<int> A(N-1);
    vector<int> B(N-1);
    REP(i,N-1){
        int a,b; cin >> a >> b;
        a--;
        b--;
        A[i] = a;
        B[i] = b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(-1,0);
    
    int n = way.size();
    reverse(ALL(way));
    UnionFind uf(N);
    if(n%2==0){
        REP(i,N-1){
            if(min(A[i],B[i])==min(way[n/2-1],way[n/2]) && max(A[i],B[i])==max(way[n/2-1],way[n/2])) continue;
            uf.union_set(A[i],B[i]);
        }
    }else{
        REP(i,N-1){
            if(min(A[i],B[i])==min(way[n/2],way[n/2+1]) && max(A[i],B[i])==max(way[n/2],way[n/2+1])) continue;
            uf.union_set(A[i],B[i]);
        }
    }
    if(uf.size(0) > uf.size(N-1)) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    
    return 0;
}