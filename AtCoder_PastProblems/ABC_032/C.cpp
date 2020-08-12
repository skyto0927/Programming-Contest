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
    int N,K; cin >> N >> K;
    vector<ll> S(N);
    REP(i,N) cin >> S[i];
    REP(i,N){//コーナーケースを先に処理
        if(S[i] == 0){
            cout << N << endl;
            return 0;
        }
    }
    int left = 0;
    int right = 0;
    int ans = 0;
    ll pro = 1;
    while(left < N){
        while(pro*S[right]<=K && right<N){
            pro *= S[right];
            right++;
        }
        ans = max(ans, right-left);
        //cout << left << " " << right << endl;
        if(left == right){
            left++;
            right++;
        }else{
            pro /= S[left];
            left++;
        }
    }
    cout << ans << endl;
    return 0;
}