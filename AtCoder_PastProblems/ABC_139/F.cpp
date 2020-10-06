#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

const long double EPS = 1e-20;

int main() {
    int N; cin >> N;
    vector<pair<long double, pair<long double,long double>>> coord;
    REP(i,N){
        ll x,y; cin >> x >> y;
        if(x==0 && y==0) continue;
        coord.push_back({atan2(y,x), {x,y}});
    }
    sort(ALL(coord));
    // for(auto e: coord){
    //     cout << e.first << " " << e.second.first << ", " << e.second.second << endl;
    // }

    int s = coord.size();
    if(s==0){
        cout << 0 << endl;
        return 0;
    }

    REP(i,s){
        coord.push_back({coord[i].first+2*M_PI, coord[i].second});
    }  

    int l = 0;
    int r = 0;

    long double sum_max = 0;

    //cout << "[" << l << ", " << r << ")" << endl;

    while(l<s){
        ll X_sum = 0;
        ll Y_sum = 0;

        r = l;
        while(coord[r].first<coord[l].first +M_PI + EPS){
            X_sum += coord[r].second.first;
            Y_sum += coord[r].second.second;
            r++;
            sum_max = max(sum_max, (long double)sqrt(X_sum*X_sum + Y_sum*Y_sum));
        }
        //cout << "[" << l << ", " << r << ")" << endl;
        //cout << X_sum << ", " << Y_sum << endl;

        l++;
    }

    cout << fixed << setprecision(20) << sum_max << endl;
    return 0;
}