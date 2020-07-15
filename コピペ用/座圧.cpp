#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


int main() {
    return 0;
}
///////////////////////////////////////////////////////

template<typename T>
vector<T> compress(vector<T> &C1, vector<T> &C2){
    vector<T> vals;
    int N = (int)C1.size();
    REP(i,N){
        vals.push_back(C1[i]);
        vals.push_back(C1[i]+1);

        vals.push_back(C2[i]);
        vals.push_back(C2[i]+1);
    }

    sort(ALL(vals));
    vals.erase(unique(ALL(vals)), vals.end());

    REP(i,N){
        C1[i] = lower_bound(ALL(vals), C1[i]) - vals.begin();
        C2[i] = lower_bound(ALL(vals), C2[i]) - vals.begin();
    }

    return vals;
}