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
    int N; cin >> N;
    vector<int> a(N);
    vector<int> sum(N+2,0);
    REP(i,N){
        cin >> a[i];
    }
    REP(i,N){
        sum[i+2] = sum[i] + a[i];
    }
    

    int ans = -INF;
    REP(a,N){
        int aoki = -INF;
        int takahashi = 0;
        REP(b,N){
            if(a==b) continue;
            int i = a;
            int j = b;
            if(i>j) swap(i,j);
            if(i%2 == j%2){
                if(aoki < sum[j+1]-sum[i+1]){
                    aoki = sum[j+1]-sum[i+1];
                    takahashi = sum[j+2]-sum[i];
                }
            }else{
                if(aoki < sum[j+2]-sum[i+1]){
                    aoki = sum[j+2]-sum[i+1];
                    takahashi = sum[j+1]-sum[i];
                }
            }
        }
        ans = max(ans, takahashi);
        //cout << takahashi << " " << aoki << endl;
    }
    cout << ans << endl;
    return 0;
}