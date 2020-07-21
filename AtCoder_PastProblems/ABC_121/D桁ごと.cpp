#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    ll A,B; cin >> A >> B;

    ll A_sum=0, B_sum=0;
    REPR(digit,45){
        ll beki_low = 1LL<<digit;
        ll beki_high = 1LL<<(digit+1);

        if(digit!=0){
            A_sum += (max(0LL, A % beki_high - beki_low)%2) << digit;
            B_sum += (max(0LL, (B+1) % beki_high - beki_low)%2) << digit;

        }else {
            A_sum += (A/2)%2;
            B_sum += ((B+1)/2)%2;
        }
    }
    cout << (A_sum^B_sum) << endl;
    return 0;
}