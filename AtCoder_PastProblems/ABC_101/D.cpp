#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

ll pows(ll b, ll n){
    return n==0? 1: b*pows(b,n-1);
}

ll S(ll n){//各桁の和
    ll N = n;
    ll SN = 0;
    while(N>0){
        SN += N%10;
        N /= 10;
    }
    return SN;
}

ll snuke(ll n){
    priority_queue< pair<double,ll>, vector<pair<double,ll>>, greater<pair<double,ll>> > val;

    ll digit = 0;

    while(pows(10,digit) <= n){
        FOR(i,1,10){//上位の桁を固定して、末尾を1-9で回す
            ll v = n - n%pows(10,digit+1) + i*pows(10,digit) - 1;

            if(v >= n){
                val.push({(double)v/S(v), v});
            }

        }
        digit++;
    }
    digit--;

    FOR(i,1,101){//100個先のやつは流石にでかい
        ll v = i*pows(10,digit) - 1;
        if(v>=n){
            val.push({(double)v/S(v), v});
        }
    }

    auto ret = val.top();
    return ret.second;

}

int main() {
    ll K; cin >> K;

    ll n = 1;

    REP(i,K){
        cout << n << endl;
        n = snuke(n+1);

    }
    return 0;
}