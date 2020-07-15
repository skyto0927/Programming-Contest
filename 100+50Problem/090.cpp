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

double dist(Coord a, Coord b){
    return sqrt(pow((a.x-b.x),2) + pow((a.y-b.y),2));
}

int main() {
    int N,M; cin >> N >> M;
    vector<Coord> A;

    REP(i,N){
        Coord c;
        cin >> c.x >> c.y >> c.r;
        A.push_back(c);
    }
    REP(i,M){
        Coord c;
        cin >> c.x >> c.y;
        c.r = -1;
        A.push_back(c);
    }

    double ans = 10000.0;
    REP(i,N+M){
        REP(j,N+M){
            if (i == j){
                continue;
            }
            if (A[i].r>0 && A[j].r>0){
                continue;
            }else if(A[i].r==-1 && A[j].r==-1){
                ans = min(ans, dist(A[i], A[j])/2);
            }else if(A[i].r>0 && A[j].r==-1){
                ans = min(ans, dist(A[i], A[j]) - A[i].r);
            }else if(A[i].r==-1 && A[j].r>0){
                ans = min(ans, dist(A[i], A[j]) - A[j].r);
            }
        }
    }
    REP(i,N){
        ans = min(ans, (double)A[i].r);
    }
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}