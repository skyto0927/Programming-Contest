#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N,M; cin >> N >> M;
    vector<pair<int,int>> pos(N);
    vector<pair<int,int>> point(M);
    REP(i,N){
        cin >> pos[i].first >> pos[i].second;
    }
    REP(i,M){
        cin >> point[i].first >> point[i].second;
    }

    REP(i,N){
        int dis = INF;
        int cp;
        REP(j,M){
            if(abs(pos[i].first-point[j].first) + abs(pos[i].second-point[j].second) < dis){
                dis = abs(pos[i].first-point[j].first) + abs(pos[i].second-point[j].second);
                cp = j+1;
            }
        }
        cout << cp << endl;
    }


    return 0;
}