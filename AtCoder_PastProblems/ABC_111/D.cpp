#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

typedef pair<ll,ll> P;

int main() {
    int N; cin >> N;
    vector<P> coord(N);
    REP(i,N){
        ll x,y; cin >> x >> y;
        coord[i] = {x,y};
    }
    int p = (abs(coord[0].first) + abs(coord[0].second))%2;
    REP(i,N){
        if(p != (abs(coord[i].first) + abs(coord[i].second))%2){
            cout << -1 << endl;
            return 0;
        }
    }

    vector<ll> D(39);
    REP(i,39){
        D[i] = (1LL<<(38-i));
    }
    if(p%2 == 0) D.push_back(1);

    cout << D.size() << endl;
    REP(i,D.size()){
        cout << D[i];
        if(i!=D.size()-1) cout << " ";
    }
    cout << endl;

    REP(i,N){
        ll X = coord[i].first, Y = coord[i].second;
        ll x=0, y=0;
        REP(i,D.size()){
            ll d = D[i];
            ll dx = X-x, dy = Y-y;

            if(abs(dx) > abs(dy)){
                if(dx>0){
                    cout << "R";
                    x += d;
                }else{
                    cout << "L";
                    x -= d;
                }
            }else{
                if(dy>0){
                    cout << "U";
                    y += d;
                }else{
                    cout << "D";
                    y -= d;
                }
            }
        }
        cout << endl;
        //cout << "(" << x << ", " << y << ")" << endl;
    } 

    return 0;
}