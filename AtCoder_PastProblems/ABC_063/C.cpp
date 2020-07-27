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
    vector<int> s(N);
    int sum = 0;
    REP(i,N){
        cin >> s[i];
        sum += s[i];
    }
    sort(ALL(s));
    if(sum%10 != 0){
        cout << sum << endl;
        return 0;
    }else{
        REP(i,N){
            if(s[i]%10 != 0){
                cout << sum - s[i] << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}