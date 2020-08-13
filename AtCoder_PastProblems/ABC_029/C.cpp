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
    vector<char> c{'a','b','c'};
    REP(bit,pow(3,N)){
        int num = bit;
        string ans;
        REP(i,N){
            ans.push_back(c[num%3]);
            num /= 3;
        }
        reverse(ALL(ans));
        cout << ans << endl;
    }
    return 0;
}