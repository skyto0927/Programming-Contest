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
    ll N,M; cin >> N >> M;
    vector<int> A(N);
    REP(i,N) cin >> A[i];
    sort(ALL(A));

    map<ll,int> op;
    REP(i,M){
        int b,c; cin >> b >> c;
        op[-c] += b;
    }
    ll cnt = 0;
    ll ans = 0;
    int itr = 0;
    for(auto o: op){
        int i = o.second;
        while(i > 0){
            if(-o.first <= A[itr]){
                ans += A[itr];
            }else{
                ans += -o.first;
                i--;
            }
            itr++;
            if(itr==N) break;
        }
        if(itr==N) break;
    }
    FOR(i,itr,N){
        ans += A[i];
    }

    cout << ans << endl;

    return 0;
}