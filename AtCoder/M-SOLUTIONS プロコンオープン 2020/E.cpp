#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int N;
ll S;

vector<ll> ans(16, 1e16);



struct Coord{
    ll x,y,p;
};

vector<Coord> C;

struct DP{
    vector<ll> x_line;
    vector<ll> y_line;
};

vector<DP> dp(1<<15);

DP rec(int bit){
    if(bit == 0){
        dp[0] = {{0}, {0}};
        return {{0}, {0}}; 
    }
    if(dp[bit].x_line.size() != 0){
        return dp[bit];
    }

    vector<ll> x_ans;
    vector<ll> y_ans;

    ll s = 1e15;

    REP(i,N){
        if(bit & (1<<i)){
            auto r = rec(bit&~(1<<i)); 
            //縦横どっちをふやすか
            vector<ll> xl1(r.x_line);
            vector<ll> yl1(r.y_line);

            vector<ll> xl2(r.x_line);
            vector<ll> yl2(r.y_line);

            xl1.push_back(C[i].y);
            yl2.push_back(C[i].x);

            ll sums1 = 0;
            ll sums2 = 0;
            REP(n,N){//Sの再計算
                ll num = 1e16;
                for(ll x: xl1){
                    num = min(num,C[n].p*abs(x-C[n].y));
                }
                for(ll y: yl1){
                    num = min(num,C[n].p*abs(y-C[n].x));
                }
                sums1 += num;
            }
            REP(n,N){//Sの再計算
                ll num = 1e16;
                for(ll x: xl2){
                    num = min(num,C[n].p*abs(x-C[n].y));
                }
                for(ll y: yl2){
                    num = min(num,C[n].p*abs(y-C[n].x));
                }
                sums2 += num;
            }

            int bp = __builtin_popcount(bit);
            ans[bp] = min({ans[bp], sums1, sums2});

            if(s > sums2){
                s = sums2;
                x_ans.resize(0);
                y_ans.resize(0);
                x_ans = xl2;
                y_ans = yl2;
            }
            
            if(s > sums1){
                s = sums1;
                x_ans.resize(0);
                y_ans.resize(0);
                x_ans = xl1;
                y_ans = yl1;
            }
        }
    }
    dp[bit] = {x_ans,y_ans};
    return {x_ans,y_ans};
}

int main() {
    cin >> N;
    Coord c;
    C.assign(N,c);
    REP(i,N){
        ll x,y,p; cin >> x >> y >> p;
        C[i] = {x,y,p};
    }

    S = 0;
    REP(i,N){
        S += C[i].p * min(abs(C[i].x), abs(C[i].y));
    }
    
    ans[0] = S;
    
    rec((1<<N)-1);

    REP(i,N+1){
        cout << ans[i] << endl;
    }

    return 0;
}