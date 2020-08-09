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
    vector<int> A(N);
    REP(i,N) cin >> A[i];

    A.push_back(-1);

    ll ans = 0;
    ll l=0, r=0;
    while(l<N){
        //ここではl==r
        while(r<N){
            if(A[r] < A[r+1]){
                r++;
            }
            else break;
        }
        ans += (r-l+1)*(r-l+2)/2;
        l = r;
        l++;
        r++;
    }

    cout << ans << endl;

    return 0;
}