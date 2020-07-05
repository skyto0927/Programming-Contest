#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    ll N; cin >> N;
    vector<ll> A(N);
    REP(i,N){
        cin >> A[i];
    }
    sort(ALL(A), greater<ll>());

    ll ans = 0;

    ans += A[0];
    int count = N-2;
    int itr = 1;

    while(count>0){
        if(count == 1){
            ans += A[itr];
            count --;
        }else{
            ans += 2*A[itr];
            itr++;
            count -= 2;
        }   
    }
    cout << ans << endl;

    return 0;
}