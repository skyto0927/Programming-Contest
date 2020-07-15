#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

struct Pyramid{
    ll x,y,h;
};

int main() {
    ll N; cin >> N;
    vector<Pyramid> pyramid;
    REP(i,N){
        Pyramid p;
        cin >> p.x >> p.y >> p.h;
        if(p.h == 0)continue;
        pyramid.push_back(p);
    }

    if(pyramid.size() == 1){
        cout << pyramid[0].x << " " << pyramid[0].y << " " << pyramid[0].h << endl;
        return 0;
    }

    REP(x, 101){
        REP(y,101){
            ll H = pyramid[0].h + abs(x-pyramid[0].x) + abs(y-pyramid[0].y);
            bool ok = true;
            FOR(i,1,pyramid.size()){
                if(H != pyramid[i].h + abs(x-pyramid[i].x) + abs(y-pyramid[i].y)){
                    ok = false; 
                    break;
                }
            }
            if(ok){
                cout << x << " " << y << " " << H << endl;
                return 0;
            }
        }
    }
    return 0;
}