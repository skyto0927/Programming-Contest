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
    vector<int> a(N);
    int sum = 0;
    REP(i,N){
        cin >> a[i];
        sum += a[i];
    }
    if(sum%N!=0){
        cout << -1 << endl;
        return 0;
    }
    int h = sum/N;
    int cnt = 0;
    int itr = 0;
    sum = 0;
    REP(i,N){
        sum += a[i];
        if(sum == h * (i-itr+1)){
            cnt += i-itr;
            itr = i+1;
            sum = 0;
        }
    }
    cout << cnt << endl;
    return 0;
}