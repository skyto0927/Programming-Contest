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
    map<int,int> l;
    REP(i,3){
        int x; cin >> x;
        l[x]++;
    }
    for(auto a: l){
        if(a.second == 1 || a.second==3){
            cout << a.first << endl;
            return 0;
        }
    }
    return 0;
}