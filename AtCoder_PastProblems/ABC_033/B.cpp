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
    int N; cin >> N;
    vector<pair<int,string>> T(N);
    ll sum = 0;
    REP(i,N){
        string s;
        int p;
        cin >> s >> p;
        T[i] = {p,s};
        sum += p;
    }
    sort(ALL(T), greater<pair<int,string>>());
    if(T[0].first*2 > sum) cout << T[0].second << endl;
    else cout << "atcoder" << endl;
    return 0;
}