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
    int N; cin >> N;
    ll ans1 = 0;
    ll num1 = 0;

    ll ans2 = 0;
    ll num2 = 0;
    REP(i,N){
        ll a; cin >> a;
        num1 += a;
        if(i%2==0 && num1 <= 0){
            ans1 += 1-num1;
            num1 = 1;
        }else if(i%2==1 && num1 >= 0){
            ans1 += num1+1;
            num1 = -1;
        }

        num2 += a;
        if(i%2==1 && num2 <= 0){
            ans2 += 1-num2;
            num2 = 1;
        }else if(i%2==0 && num2 >= 0){
            ans2 += num2+1;
            num2 = -1;
        }
    }
    cout << min(ans1,ans2) << endl;
    return 0;
}