#include <bits/stdc++.h>
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
    string S; cin >> S;
    int N = S.size();
    ll sum = 0;
    ll d = 1;
    map<int,int> A;
    A[0]++;
    REPR(i,N-1){
        sum = (sum + (S[i]-'0')*d)%2019;
        A[sum] ++;

        d *= 10;
        d %= 2019;
    }
    ll ans = 0;
    for(auto a: A){
        //cout << a.first << " " << a.second << endl;
        ans += a.second*(a.second-1)/2;
    }
    cout << ans << endl;
    return 0;
}