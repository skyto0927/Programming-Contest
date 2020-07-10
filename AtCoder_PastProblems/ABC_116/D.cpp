#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    ll N,K; cin >> N >> K;
    vector<pair<ll,ll>> sushi(N);
    REP(i,N){
        ll t,d; cin >> t >> d;
        sushi[i] = make_pair(d,t-1);
    }
    sort(ALL(sushi), greater<pair<ll,ll>>());

    map<ll,ll> num;
    priority_queue<pair<ll,ll>> S;
    ll ans = 0;
    FOR(i,K,N){
        S.push(sushi[i]);
    }

    REP(i,K){
        num[sushi[i].second]++;
        ans += sushi[i].first;
    }

    ll f = ans;

    ans += (ll)num.size()*(ll)num.size();

    REPR(i,K-1){
        if(S.empty()) break;
        if(num[sushi[i].second]> 1){//2種のやつなら  
            while(!S.empty()){
                auto top_sushi = S.top(); S.pop();
                if(!num.count(top_sushi.second)){//交換対象なら
                    f = f - sushi[i].first + top_sushi.first;

                    num[top_sushi.second]++;
                    num[sushi[i].second]--;

                    ll next_ans = f + (ll)num.size() * (ll)num.size();



                    sushi[i] = top_sushi;
                    ans = max(ans, next_ans);
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}