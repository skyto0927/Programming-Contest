#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

typedef pair<ll,ll> P;

struct Baggage{
    ll v,w;
};

int main() {
    int N,W; cin >> N >> W;
    vector<Baggage> baggage(N);
    ll max_v = 0;
    ll max_w = 0;
    REP(i,N){
        cin >> baggage[i].v >> baggage[i].w;
        max_v = max(max_v, baggage[i].v);
        max_w = max(max_w, baggage[i].w);
    }

    if(N<=30){
        vector<P> L,R;

        REP(bit,1<<N/2){
            P p = {0,0};
            REP(i,N/2){
                if(bit & (1<<i)){
                    p.first += baggage[i].w;
                    p.second += baggage[i].v;
                }
            }
            L.push_back(p);
        }

        REP(bit,1<<(N-N/2)){
            P p = {0,0};
            REP(i,(N-N/2)){
                if(bit & (1<<i)){
                    p.first += baggage[i+N/2].w;
                    p.second += baggage[i+N/2].v;
                }
            }
            R.push_back(p);
        }
        
        sort(ALL(R));
        REP(i,R.size()-1){
            if(R[i].second > R[i+1].second) R[i+1].second = R[i].second;
        }
        ll ans = 0;
        for(auto cur: L){
            if(W < cur.first) continue;
            P p = {W-cur.first, LINF};
            auto itr = upper_bound(ALL(R), p);
            itr--;
            ans = max(ans, (*itr).second + cur.second);
        }

        cout << ans << endl;

    }else if(max_w <= 1000){
        int w_max = 3e5;
        vector<vector<ll>> dp(N+1, vector<ll>(w_max+1, 0));
        REP(i,N){
            REP(j,w_max){
                if(baggage[i].w + j <= min(W,w_max)){
                    dp[i+1][j+baggage[i].w] = max(dp[i+1][j+baggage[i].w], dp[i][j]+baggage[i].v);
                }
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            }
        }
        ll ans = 0;
        REP(j,min(W+1,w_max+1)){
            ans = max(ans, dp[N][j]);
        }
        cout << ans << endl;

    }else if(max_v <= 1000){
        int v_max = 3e5;
        vector<vector<ll>> dp(N+1, vector<ll>(v_max+1, 2*W));
        dp[0][0] = 0;
        REP(i,N){
            REP(j,v_max){
                if(baggage[i].v + j <= v_max){
                    dp[i+1][j+baggage[i].v] = min(dp[i+1][j+baggage[i].v], dp[i][j]+baggage[i].w);
                }
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            }
        }

        int ans = 0;
        REP(j,v_max+1){
            if(W >= dp[N][j]){
                ans = j;
            }
        }
        cout << ans << endl;

    }
    return 0;
}