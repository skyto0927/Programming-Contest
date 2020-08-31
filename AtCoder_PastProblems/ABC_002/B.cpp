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
    string W; cin >> W;
    vector<char> v{'a','i','u','e','o'};
    REP(i,W.size()){
        bool ok = true;
        for(auto a: v){
            if(W[i] == a) ok = false;
        }
        if(ok) cout << W[i];
    }
    cout << endl;
    return 0;
}