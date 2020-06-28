#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int n; cin >> n;
    //0 -> white, 1 -> black
    stack<pair<int,int>> stone;
    FOR(i,1,n+1){
        int color; cin >> color;
        if(stone.empty()){//初手だけ警戒
            stone.push(make_pair(color,1));
            continue;
        }
        auto t = stone.top();
        stone.pop();
        if(i%2 == 1){//odd
            if(t.first == color){
                stone.push(make_pair(color,t.second+1));
            }else{
                stone.push(t);
                stone.push(make_pair(color,1));
            }

        }else{//even
            if(t.first == color){
                stone.push(make_pair(color,t.second+1));
            }else{
                if(stone.empty()){
                    stone.push(make_pair(color,t.second+1));
                    continue;
                }
                auto u = stone.top();
                stone.pop();
                stone.push(make_pair(u.first,u.second + t.second + 1));
            }
        }
    }
    int ans = 0;
    while(!stone.empty()){
        auto t = stone.top();
        stone.pop();
        if(t.first == 0){
            ans += t.second;
        }
    }

    cout << ans << endl;

    return 0;
}