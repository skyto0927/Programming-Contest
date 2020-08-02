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
    string s; cin >> s;
    int a=0;
    int z=0;
    REP(i,s.size()){
        if(s[i] == 'A'){
            a=i;
            break;
        }
    }
    REP(i,s.size()){
        if(s[i] == 'Z') z=i;
    }

    cout << z-a+1 << endl;
    return 0;
}