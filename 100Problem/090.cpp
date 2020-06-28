#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

struct Coord{
    int x,y,r;
};

int main() {
    int N,M; cin >> N >> M;
    vector<Coord> A(N);
    vector<Coord> B(M);

    REP(i,N){
        int x,y,r;
        cin >> x >> y >> r;
        A.push_back({x,y,r});
    }
    REP(i,M){
        int x,y;
        cin >> x >> y;
        B.push_back({x,y,0});

    }
    return 0;
}