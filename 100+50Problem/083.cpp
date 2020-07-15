#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,M; cin >> N >> M;
    vector<int> P(M+1);
    REP(i,M){
        int p;
        cin >> p;
        p--;
        P[i] = p;//0-indexed
    }
    vector<int> way(N,0);
    REP(i,M-1){
        if (P[i] < P[i+1]){
            way[P[i]] ++;
            way[P[i+1]] --;
        }else{
            way[P[i+1]] ++;
            way[P[i]] --;
        }
    }
    REP(i,N-1){
        way[i+1] += way[i];
    }

    ll ans = 0;
    REP(i,N-1){
        ll A,B,C; cin >> A >> B >> C;
        if(way[i]*A > way[i]*B + C){
            ans += way[i]*B + C;
        }else{
            ans += way[i]*A;
        }
    }

    cout << ans << endl;

    return 0;
}