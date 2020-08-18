#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    ll N,K; cin >> N >> K;
    vector<int> P(N);
    vector<ll> C(N);
    REP(i,N){
        cin >> P[i];
        P[i]--;
    }
    REP(i,N) cin >> C[i];


    
    ll ans = -LINF;

    REP(i,N){//全ての点を始点として考える
        ll loop_sum = 0;
        int pos = i;
        ll cnt = 0;

        REP(j,N){//ループの周期を求める cnt
            pos = P[pos];
            loop_sum += C[pos];
            if(i==pos){
                cnt = j+1;
                break;
            }
        }

        ll tmp = -LINF;
        ll sum = 0;
        pos = i;//1周して戻ってきてるけど一応

        if(K <= cnt){//Kが1周にみたないなら
            REP(j,K){
                pos = P[pos];
                sum += C[pos];
                tmp = max(tmp,sum);
            }

            ans = max(ans,tmp);

        }else{//1周以上できるなら

            if(loop_sum <= 0){//1周しても得がない場合は最初の1周だけかんがえればよい
                REP(j,cnt){
                    pos = P[pos];
                    sum += C[pos];
                    tmp = max(tmp,sum);
                }
                ans = max(ans, tmp);
            }else{//得する場合はガンガン回す →これは嘘で1とあまりを考える

                ll K2 = K%cnt+cnt;//周回後のあまり
                ll k = K/cnt-1;//何周できるか

                tmp = 0;//k周したあとは1回も動かなくても良いので
                REP(j,K2){
                    pos = P[pos];
                    sum += C[pos];
                    tmp = max(tmp,sum);
                }
                tmp += loop_sum*k;

                ans = max(ans, tmp);
            }
        }


    }
    cout << ans << endl;


    return 0;
}