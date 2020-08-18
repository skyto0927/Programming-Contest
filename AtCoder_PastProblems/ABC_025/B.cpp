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
    int N,A,B; cin >> N >> A >> B;
    int x=0;

    REP(i,N){
        string s;
        int d;
        cin >> s >> d;
        if(d<A) x += (s=="East"?A:-A);
        else if(A<=d && d<=B) x += (s=="East"?d:-d);
        else x += (s=="East"?B:-B);  
    }
    if(x > 0) cout << "East " << x << endl;
    else if(x < 0) cout << "West " << -x << endl;
    else cout << 0 << endl;
    
    return 0;
}