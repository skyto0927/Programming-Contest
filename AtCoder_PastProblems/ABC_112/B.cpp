#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,T; cin >> N >> T;
    vector<pair<int,int>> way(N);
    REP(i,N){
        int c,t; cin >> c >> t;
        way[i] = {c,t};
    }
    sort(ALL(way));

    REP(i,N){
        if(way[i].second <= T){
            cout << way[i].first << endl;;
            return 0;
        }
    }
    cout << "TLE" << endl;
    return 0;
}