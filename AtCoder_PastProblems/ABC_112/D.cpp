#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

vector<int> div(int n){
    vector<int> a;
    FOR(i,1,sqrt(n)+1){
        if(n%i == 0){
            a.push_back(i);
            if(i*i!=n) a.push_back(n/i);
        }
    }
    sort(ALL(a));
    return a;
}

int main() {
    int N,M; cin >> N >> M;
    vector<int> a = div(M);

    auto itr = upper_bound(ALL(a), M/N);
    itr--;
    cout << *itr << endl;

    return 0;
}