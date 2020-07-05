#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;

    int count = 0;
    ll sum = 0;
    ll min_a = INF;
    REP(i,N){
        ll a;
        cin >> a;
        if (a<0){
            count++;
            a = -a;
        }
        sum += a;
        min_a = min(min_a, a);
    }
    if(count%2 == 0){
        cout << sum << endl;
    }else{
        cout << sum - 2*min_a << endl;
    }
    return 0;
}