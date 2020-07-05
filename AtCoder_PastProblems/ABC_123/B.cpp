#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {

    vector<pair<int,int>>dish(5);
    REP(i,5){
        int x;
        cin >> x;
        dish[i] = make_pair((x-1)%10, x);
    }
    sort(ALL(dish));
    int ans = dish[0].second;
    FOR(i,1,5){
        ans += ((dish[i].second-1)/10 + 1)*10;
    }

    cout << ans << endl;
    return 0;
}