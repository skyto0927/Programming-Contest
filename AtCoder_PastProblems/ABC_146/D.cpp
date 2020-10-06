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

struct Edge{
    ll to, color;
};

int main() {
    int N; cin >> N;
    vector<vector<Edge>> G(N);
    vector<int> A(N),B(N);
    REP(i,N-1){
        int a,b; cin >> a >> b;
        a--;
        b--;
        G[a].push_back({b,i});
        G[b].push_back({a,i});
        A[i] = a;
        B[i] = b;
    }

    vector<int> color(N-1,0);//辺ごとに
    int k = 0;
    REP(i,N){
        k = max(k,(int)G[i].size());
    }
    cout << k << endl;

    queue<pair<int,int>> q;
    q.push({0,0});

    while(!q.empty()){
        auto p = q.front(); q.pop();
        int pos = p.first;
        int used = p.second;

        int c = 1;
        for(auto next: G[pos]){
            if(color[next.color] != 0) continue;
            if(c == used) c++;

            color[next.color] = c;
            q.push({next.to, c});
            c++;
        }
    }

    REP(i,N-1) cout << color[i] << endl;


    return 0;
}