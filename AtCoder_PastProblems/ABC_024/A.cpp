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
    int a,b,c,k,s,t; cin>>a>>b>>c>>k>>s>>t;
    cout << (s+t>=k?s*(a-c)+t*(b-c):s*a+t*b) << endl;
    return 0;
}