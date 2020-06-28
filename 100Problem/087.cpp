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

int main() {
    ll N,M; cin >> N >> M;
    vector<int> A(M);
    vector<int> B(M);
    REP(i,M){
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    vector<ll> ans(M+1,0);
    UnionFind uf(N);
    ans[M] = N*(N-1)/2;

    REPR(i,M-1){
        if (uf.find_set(A[i],B[i])){
            ans[i] = ans[i+1];
        }else{
            ll A_size = uf.size(A[i]);
            ll B_size = uf.size(B[i]);
            ans[i] = ans[i+1] - A_size*B_size;
        }
        uf.union_set(A[i], B[i]);
    }

    FOR(i,1,M+1){
        cout << ans[i] << endl;
    }
    

    return 0;
}