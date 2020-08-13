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
    ll N; cin >> N;
    string d;
    while(N>0){
        d += (to_string(N%2));
        N /= 2;
    }
    reverse(ALL(d));
    int k = d.size();
    REP(i,k){
        if(i==0) continue;
        if(d[i] == '0' && (k-i)%2 == 0){//
            cout << (i%2==0?"Aoki":"Takahashi") << endl;
            return 0;
        }else if(d[i] == '1' && (k-i)%2 == 1){
            cout << (i%2==0?"Aoki":"Takahashi") << endl;
            return 0;
        }
    }
    cout << (k%2==1?"Aoki":"Takahashi") << endl;
    return 0;
}