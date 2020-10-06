#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    string S; cin >> S;
    vector<string> W{"Sunny", "Cloudy", "Rainy"};
    REP(i,3){
        if(S==W[i]){
            cout << W[(i+1)%3] << endl;
            return 0;
        }
    }
    return 0;
}