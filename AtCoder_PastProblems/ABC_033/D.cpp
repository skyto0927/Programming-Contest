#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

const double EPS = 1e-10;

int main() {
    ll N; cin >> N;
    vector<pair<ll,ll>> C(N);
    REP(i,N) cin >> C[i].first >> C[i].second;

    ll cnt_r = 0;
    ll cnt_o = 0;


    REP(i,N){
        vector<double> angle;
        REP(j,N){
            if(i!=j){
                ll x = C[j].first - C[i].first;
                ll y = C[j].second - C[i].second;
                double theta = atan2(y,x);
                angle.push_back(theta);
                angle.push_back(theta + 2*M_PI);
            }
        }
        sort(ALL(angle));

        REP(j,N-1){
            cnt_r += upper_bound(ALL(angle), angle[j]+M_PI/2+EPS) - lower_bound(ALL(angle), angle[j]+M_PI/2-EPS);
            cnt_o += lower_bound(ALL(angle), angle[j]+M_PI) - upper_bound(ALL(angle), angle[j]+M_PI/2+EPS);
        }
    }

    ll sum = N*(N-1)*(N-2)/6;

    cout << sum-cnt_r-cnt_o << " " << cnt_r << " " << cnt_o << endl;
    return 0;
}