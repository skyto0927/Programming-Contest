#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    ll A,B,N;
    cin >> A >> B >> N;

    if(B-1 >= N){
        cout << (A*N)/B - (N/B)*A << endl;
    }else{
        ll ans = (N/B) * B + (B-1);
        if (ans > N){
            ans -= B;
        }
        cout << (A*ans)/B - (ans/B)*A << endl;
    }
    return 0;
}