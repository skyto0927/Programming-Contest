#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,M,X; cin >> N >> M >> X;

    int l=0, r=0;
    REP(i,M){
        int a; cin >> a;
        if(a<X) l++;
        else r++;
    }

    cout << min(l,r) << endl;
    return 0;
}