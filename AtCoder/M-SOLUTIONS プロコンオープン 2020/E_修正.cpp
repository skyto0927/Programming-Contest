#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e15
typedef long long ll;

int N;
vector<ll> ans(16,LINF);

vector<vector<ll>> h_dist;
vector<vector<ll>> v_dist;

struct Coord{
    ll x,y,p;
};

void solve(vector<int> h, vector<int> v, int k){
    if(k == N){
        int bp = h.size() + v.size();
        
        if(bp > N) return;
        
        int x_num = 0;
        int y_num = 0;

        for(int hh: h) x_num += (1<<hh);
        for(int vv: v) y_num += (1<<vv);
        ll a = 0;
        REP(i,N){
            a += min(h_dist[x_num][i], v_dist[y_num][i]);
        }
        ans[bp] = min(ans[bp], a);


    }else{
        vector<int>h2(h);
        h2.push_back(k);
        vector<int>v2(v);
        v2.push_back(k);

        solve(h2,v,k+1);
        solve(h,v2,k+1);
        solve(h,v,k+1);

    }
    return;
}

int main() {
    cin >> N;
    vector<Coord> C(N);
    REP(i,N){
        ll x,y,p; cin >> x >> y >> p;
        C[i] = {x,y,p};
    }

    h_dist.assign(1<<N, vector<ll>(N,LINF));//縦のみ
    REP(bit,1<<N){
        vector<ll> s{0};
        REP(i,N){
            if(bit & (1<<i)) s.push_back(C[i].x);
        }
        REP(i,N){
            for(auto x: s){
                h_dist[bit][i] = min(h_dist[bit][i], C[i].p * abs(x-C[i].x));
            }
        }
    }

    v_dist.assign(1<<N, vector<ll>(N,LINF));//横のみ
    REP(bit,1<<N){
        vector<ll> s{0};
        REP(i,N){
            if(bit & (1<<i)) s.push_back(C[i].y);
        }
        REP(i,N){
            for(auto y: s){
                v_dist[bit][i] = min(v_dist[bit][i], C[i].p * abs(y-C[i].y));
            }
        }
    }

    solve({},{},0);

    REP(i,N+1){
        cout << ans[i] << endl;
    }
    
    return 0;
}