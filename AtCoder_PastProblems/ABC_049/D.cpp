#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
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

int main() {
    int N,K,L; cin >> N >> K >> L;
    UnionFind uf1(N);
    REP(i,K){
        int a,b; cin >> a >> b;
        a--;
        b--;
        uf1.union_set(a,b);
    }

    UnionFind uf2(N);
    REP(i,L){
        int a,b; cin >> a >> b;
        a--;
        b--;
        uf2.union_set(a,b);
    }

    vector<int> A(N);
    vector<int> B(N);
    map<pair<int,int>,int> C;
    REP(i,N){
        A[i] = uf1.root(i);
        B[i] = uf2.root(i);
        C[{A[i], B[i]}] ++;
    }

    REP(i,N){
        cout << C[{A[i], B[i]}] << " ";
    }
    cout << endl;

    return 0;
}