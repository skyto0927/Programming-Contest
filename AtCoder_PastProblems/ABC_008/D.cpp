#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

typedef tuple<int,int,int,int> key;

map<key,ll> memo;

vector<int> X, Y;
int N;

int dfs(ll l,ll r,ll u,ll d){
    if(l>r || u>d) return 0;
    key k = {l,r,u,d};
    if(memo.find(k) != memo.end()) return memo[k];

    memo[k] = 0;
    REP(i,N){
        if(l<=X[i] && X[i]<=r && u<=Y[i] && Y[i]<=d){
            memo[k] = max(memo[k], r-l+d-u+1 
                                + dfs(l,X[i]-1,u,Y[i]-1)
                                + dfs(X[i]+1,r,u,Y[i]-1)
                                + dfs(l,X[i]-1,Y[i]+1,d)
                                + dfs(X[i]+1,r,Y[i]+1,d));
        }
    }
    return memo[k];
}


int main() {
    int W,H; cin >> W >> H;
    cin >> N;
    X.assign(N,0);
    Y.assign(N,0);
    REP(i,N){
        cin >> X[i] >> Y[i];
    }

    cout << dfs(1,W,1,H) << endl;
    return 0;
}