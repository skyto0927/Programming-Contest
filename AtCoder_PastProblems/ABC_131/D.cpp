#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

typedef pair<int,int> P;

int main() {
    int N; cin >> N;
    vector<P> time(N);
    REP(i,N){
        int a,b; cin >> a >> b;
        time[i] = {b,a};
    }
    sort(ALL(time));

    int now = 0;
    REP(i,N){
        now += time[i].second;
        if(now > time[i].first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}