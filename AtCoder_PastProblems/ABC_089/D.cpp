#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

struct Coord{
    int x,y;
};

int main() {
    ll H,W,D; cin >> H >> W >> D;

    vector<Coord> A(H*W+1);
    REP(i,H){
        REP(j,W){
            int a; cin >> a;
            A[a].x = i;
            A[a].y = j;
        }
    }

    vector<ll> cost(H*W+1,0);

    FOR(i,1,H*W){
        if(i+D<=H*W){
            cost[i+D] += cost[i] + abs(A[i+D].x - A[i].x) + abs(A[i+D].y - A[i].y);
        }
    }

    int Q; cin >> Q;
    REP(i,Q){
        int L,R; cin >> L >> R;
        cout << cost[R] - cost[L] << endl;
    }

    return 0;
}