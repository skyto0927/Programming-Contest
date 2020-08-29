#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

const int MOD = 1e9+7;

int main() {
    int N,M; cin >> N >> M;
    vector<int> F(N);
    REP(i,N){
        cin >> F[i];
        F[i]--;
    }

    vector<ll> sum(N+2,0);
    sum[1] = 1;
    set<int> cnt;
    int j = 0;
    REP(i,N){        
        if(cnt.find(F[i]) != cnt.end()){ //要素が重複する場合
            while(1){
                if(F[j] == F[i]){
                    j++;
                    break;
                }else{
                    cnt.erase(F[j]);
                    j++;
                }
            }
        }else{
            cnt.insert(F[i]);
        }

        sum[i+2] = 2*sum[i+1] - sum[j];
        sum [i+2] %= MOD;

    }

    cout << (sum[N+1] - sum[N] + MOD)%MOD << endl;

    return 0;
}