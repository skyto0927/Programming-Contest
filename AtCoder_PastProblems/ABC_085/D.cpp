#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,H; cin >> N >> H;
    priority_queue<pair<int,int>> k;
    REP(i,N){
        int a,b; cin >> a >> b;
        k.push({a,0});
        k.push({b,1});
    }

    int ans = 0;
    while(H>0){
        auto sword = k.top(); k.pop();
        if(sword.second == 1){
            H -= sword.first;
            ans++;
        }else{
            ans += (H-1)/sword.first + 1;
            H = 0;
        }
    }

    cout << ans << endl;


    return 0;
}