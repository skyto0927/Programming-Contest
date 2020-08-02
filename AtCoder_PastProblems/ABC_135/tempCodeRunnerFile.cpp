#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

const int MOD = 1000000007;

int main() {
    int K; cin >> K;
    int X,Y; cin >> X >> Y;

    bool xm=false,ym=false,xy=false;
    if(X<0) X = -X, xm=true;
    if(Y<0) Y = -Y, ym=true;

    if(X<Y) swap(X,Y), xy=true;
    vector<pair<int,int>> ans;

    if((X+Y)%2==1 && K%2==0){
        cout << -1 << endl;
        return 0;
    }else if(X+Y==K){
        ans.push_back({X,Y});
    }else if((X+Y)%2==0 && X+Y<K){
        int n = 2;
        int y = 0;
        REP(i,n){
            y += K;
            if(y<= (n*K-X+Y)/2){
                ans.push_back({0,y});
            }else if((n*K-X+Y)/2 < y && y<= (n*K+X+Y)/2){
                ans.push_back({y-(n*K-X+Y)/2, (n*K-X+Y)/2});
            }else{
                ans.push_back({X, (n*K-X+Y)/2-y+(n*K+X+Y)/2});
            }
        }
    }else if(X<K){
        ans.push_back({X,X-K});
        ans.push_back({(K+3*X-Y)/2, (-K+X+Y)/2});
        ans.push_back({X,Y});
    }else if(X >= K){
        int n = (X+Y-1)/K + 1;
        if(n*K%2 != (X+Y)%2){
            n++;
        }
        int x=0,y=0;
        REP(i,n){
            y += K;
            if(y<= (n*K-X+Y)/2){
                ans.push_back({0,y});
            }else if((n*K-X+Y)/2 < y && y<= (n*K+X+Y)/2){
                ans.push_back({y-(n*K-X+Y)/2, (n*K-X+Y)/2});
            }else{
                ans.push_back({X, (n*K-X+Y)/2-y+(n*K+X+Y)/2});
            }
        }
    }
    cout << ans.size() << endl;
    REP(i,ans.size()){
        int x = ans[i].first;
        int y = ans[i].second;
        if(xy) swap(x,y);
        if(xm) x = -x;
        if(ym) y = -y;
        cout << x << " " << y << endl;
    }



    
    return 0;
}