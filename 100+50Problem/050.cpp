#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000000000
typedef long long ll;

int N_MAX = 16;
int N;
ll M;

struct edge{
    ll d, time;
};

vector<vector<edge>> G(N_MAX,vector<edge>(N_MAX,{INF,0}));

vector<vector<ll>> dp((1<<N_MAX), vector<ll>(N_MAX, -1));
vector<vector<ll>> num((1<<N_MAX), vector<ll>(N_MAX,0));

void rec(int bit, int v){
    if (dp[bit][v] != -1) return;//メモ化により計算量削減

    if(bit == 0){//端のケース
        if(v == 0){
            dp[0][0] = 0;
            num[0][0] = 1;
        }else{
            dp[0][v] = INF;
            num[0][v] = 0;
        }
    }

    dp[bit][v] = INF;//捜査済のINF

    if ((bit&(1<<v)) == 0)return; //存在しない移動経路については無視

    //ここからdp開始
    REP(i,N){
        rec(bit^(1<<v), i);
        if (dp[bit^(1<<v)][i] + G[i][v].d <= G[i][v].time){
            if(dp[bit][v] == dp[bit^(1<<v)][i] + G[i][v].d){
                num[bit][v] += num[bit^(1<<v)][i];
            }else if(dp[bit][v] > dp[bit^(1<<v)][i] + G[i][v].d){
                dp[bit][v] = dp[bit^(1<<v)][i] + G[i][v].d;
                num[bit][v] = num[bit^(1<<v)][i];
            }
        }
    }

}

int main() {
    cin >> N >> M;
    REP(i, M){
        ll s,t,d,time;
        cin >> s >> t >> d >> time;
        G[s-1][t-1] = {d, time};
        G[t-1][s-1] = {d, time};
    }


    dp[0][0] = 0;
    num[0][0] = 1;

    rec((1<<N)-1, 0);//ここで計算！！！！！！！！！

    if(dp[(1<<N)-1][0] == INF){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << dp[(1<<N)-1][0] << " " << num[(1<<N)-1][0] << endl;
    }

    return 0;
}