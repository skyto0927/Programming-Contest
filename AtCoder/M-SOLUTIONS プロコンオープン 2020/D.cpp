#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<ll> A;
    ll before = 0;
    A.push_back(INF);
    REP(i,N){
        ll a; cin >> a;
        if(a != before) A.push_back(a);
        before = a;
    }
    A.push_back(0);
    ll ans = 1000;
    ll stock = 0;
    FOR(i,1,A.size()-1){
        if(A[i-1]>A[i] && A[i]<A[i+1]){
            stock = ans/A[i];
            ans = ans - stock*A[i];
        }
        if(A[i-1]<A[i] && A[i]>A[i+1]){
            ans = ans + stock*A[i];
            stock = 0;
        }
    }
    cout << ans << endl;
    


    return 0;
}