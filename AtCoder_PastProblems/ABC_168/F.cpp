#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


template<typename T> vector<T> compress(vector<T> &C1, vector<T> &C2, vector<T> &C3){
    vector<T> vals;
    REP(i,C1.size()){
        vals.push_back(C1[i]);
        vals.push_back(C1[i]+1);
    }
    REP(i,C2.size()){
        vals.push_back(C2[i]);
        vals.push_back(C2[i]+1);
    }
    REP(i,C3.size()){
        vals.push_back(C3[i]);
        vals.push_back(C3[i]+1);
    }

    sort(ALL(vals));
    vals.erase(unique(ALL(vals)), vals.end());

    REP(i,C1.size()) C1[i] = lower_bound(ALL(vals), C1[i]) - vals.begin();
    REP(i,C2.size()) C2[i] = lower_bound(ALL(vals), C2[i]) - vals.begin();
    REP(i,C3.size()) C3[i] = lower_bound(ALL(vals), C3[i]) - vals.begin();

    return vals;
}

vector<int> dx{1,0,-1,0};
vector<int> dy{0,-1,0,1};

int main(){

    int N,M; cin >> N >> M;
    vector<ll> A,B,C,D,E,F;
    REP(i,N){
        ll a,b,c; cin >> a >> b >> c;
        A.push_back(2LL*a);
        B.push_back(2LL*b);
        C.push_back(2LL*c);
    }
    REP(i,M){
        ll a,b,c; cin >> a >> b >> c;
        D.push_back(2LL*a);
        E.push_back(2LL*b);
        F.push_back(2LL*c);
    }

    vector<ll> X = compress(A,B,D);
    vector<ll> Y = compress(C,E,F);

    vector<vector<int>> G(X.size()+2, vector<int>(Y.size()+2, 2));
    REP(i,X.size()){
        REP(j,Y.size()){
            G[i+1][j+1] = 0;
        }
    }

    REP(i,N){
        FOR(x,A[i],B[i]+1){
            G[x+1][C[i]+1] = 1;
        }
    }
    REP(i,M){
        FOR(y,E[i],F[i]+1){
            G[D[i]+1][y+1] = 1;
        }
    }
    pair<ll,ll> s;
    s.first = upper_bound(ALL(X), 0) - X.begin();
    s.second = upper_bound(ALL(Y), 0) - Y.begin();
    // cout << X[s.first-1] << ", " << Y[s.second-1] << endl;
    G[s.first][s.second] = 8;

    // REP(i,X.size()+2){
    //     REP(j,Y.size()+2){
    //         cout << G[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = 0;
    queue<pair<ll,ll>> q;
    q.push(s);
    while(!q.empty()){
        auto pos = q.front(); q.pop();
        int x = pos.first;
        int y = pos.second;
        if(x%2==0 && y%2==0){
            ans += ((X[x]-X[x-2])/2) * ((Y[y]-Y[y-2])/2);
            //cout << X[x] << ", " << X[x-2]<< ", " << Y[y] << ", " << Y[y-2] << endl;
        }
        REP(i,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(G[nx][ny] == 2){
                cout << "INF" << endl;
                return 0;
            }else if(G[nx][ny] == 0){
                G[nx][ny] = 1;//到達済みに更新
                q.push({nx,ny});
            }
        }
    }

    cout << ans << endl;
    return 0;
}