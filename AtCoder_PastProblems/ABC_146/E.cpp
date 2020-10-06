#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

int main() {
    int N, K; cin >> N >> K;
    modint::set_mod(K);
    vector<modint> A(N);
    REP(i,N){
        int a; cin >> a;
        A[i] = a;
    }
    vector<modint> sum(N+1,0);
    REP(i,N){
        sum[i+1] = sum[i] + A[i];
    }

    //REP(i,N+1) cout << (sum[i]-i).val() << " ";
    //cout << endl;
    vector<int> cnt(K,0);

    int l = 0;
    int r = 0;
    ll ans = 0;
    while(l<N){
        if(r-l < K-1 && r!=N){//右を動かせるなら動かす
            r++;
            cnt[(sum[r]-r).val()] ++;
        }else{//ダメなら処理して左を1動かす
        cout << l << "," << r << " " << cnt[(sum[l]-l).val()] << endl;
            ans += cnt[(sum[l]-l).val()];
            l++;
            cnt[(sum[l]-l).val()]--;
        }
    }
    cout << ans << endl;
    return 0;
}