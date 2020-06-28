#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<pair<ll,ll>> HS;

    ll max_H = 0;
    ll max_S = 0;
    REP(i,N){
        ll S,H;
        cin >> H >> S;
        max_H = max(max_H, H);
        max_S = max(max_S, S);
        HS.push_back(make_pair(H,S));
    }

    vector<ll> limit(N);

    ll left = max_H-1;
    ll right = max_H + (N-1)*max_S;//考えうる範囲を指定

    ll mid;

    while(right - left > 1){//二分探索、leftは常に成り立たずrightは常に成り立つため、差が1のときrightが答え
        mid = (left+right)/2;
        //cout << left <<", "<< mid << ", "<<right << endl;
        REP(i,N){
            limit[i] = (mid-HS[i].first)/HS[i].second;
        }
        sort(ALL(limit));

        bool ok = true;
        REP(i,N){
            if(i>limit[i]){
                left = mid;
                ok = false;
                break;
            }
        }
        if (ok){//成り立つ場合、もっと小さい場合が考えられるので下へ
            right = mid;
        }

    }

    cout << right << endl;

    return 0;
}
