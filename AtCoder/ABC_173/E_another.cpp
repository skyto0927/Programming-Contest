#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

//////////////////ここの値は必ず確認！！！！！////////////////////
//---------------------------------------------------------//
const int MOD = 1e9+7;
const int MAXR = 510000;
//---------------------------------------------------------//


int main() {
    ll N,K; cin >> N >> K;

    vector<ll> A_p;
    vector<ll> A_m;

    int minus_count = 0;
    REP(i,N){
        ll a; cin >> a;
        if(a>=0){
            A_p.push_back(a);
        }else if (a<0){
            A_m.push_back(a);
            minus_count++;
        }
    }

    sort(ALL(A_p), greater<pair<ll,ll>>());

    ll ans = 1;

    if(N==K){
        REP(i,A_p.size()){
            ans *= A_p[i];
            ans %= MOD;
        }
        REP(i,A_m.size()){
            ans *= A_m[i];
            ans %= MOD;
        }
    }else if(A_p.size()==0 && K%2==1){
        REP(i,K){
            sort(ALL(A_m), greater<pair<ll,ll>>());
            ans *= A_m[i];
            ans %= MOD;
        }
    }else{
        sort(ALL(A_m));
        int itr = 0;
        while(itr < K){

        }
    }

    

    return 0;
}