#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

ll digit(ll b, ll n){
    ll num = n;
    ll ans = 0;
    while(num>0){
        ans += num%b;
        num /= b;
    }
    return ans;
}

int main() {
    ll n,s; cin >> n >> s;

    if(s==n){
        cout << n+1 << endl;
        return 0;
    }

    if(n<s){
        cout << -1 << endl;
        return 0;
    }

    FOR(b,2,sqrt(n)+1){
        if(digit(b,n)==s){
            cout << b << endl;
            return 0;
        }
    }

    for(ll p = sqrt(n)+1; p>=1; p--){
        if((n-s)%p == 0){
            ll b = (n-s)/p + 1;

            if(digit(b,n)==s){
                cout << b << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}