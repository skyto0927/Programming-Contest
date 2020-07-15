#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18

vector<ll> a;
vector<pair<int,ll>> X,Y;
void make_array(int L, int R, vector<pair<int,ll>> &t){
    int w = R-L;
    REP(i,(1<<w)){
        ll sum=0;
        int cnt=0;
        REP(j,w){
            if(i&(1<<j)){
                sum += a[L+j];
                cnt++;
            }
        }
        t.push_back({cnt,sum});
    }
}

int main() {
    ll n,k,l,r; cin >> n >> k >> l >> r;
    a.assign(n,0); REP(i,n) cin >> a[i];
    
    make_array(0,n/2,X);
    make_array(n/2,n,Y);
    
    sort(ALL(X));
    sort(ALL(Y));
        
    ll ans = 0;

    REP(i,X.size()){
        int itr_R = upper_bound(ALL(Y), pair<int,ll>(k-X[i].first, r-X[i].second)) - Y.begin();
        int itr_L = lower_bound(ALL(Y), pair<int,ll>(k-X[i].first, l-X[i].second)) - Y.begin();
        ans += itr_R - itr_L;
    }

    cout << ans << endl;

    return 0;
}