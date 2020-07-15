#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


vector<int> dx{1,0,-1,0};
vector<int> dy{0,1,0,-1};

struct Coord{
    int x1,y1,x2,y2;
};

int main() {
    int H,W; cin >> H >> W;
    vector<vector<int>> A(H+2, vector<int>(W+2,0));
    REP(i,H){
        REP(j,W){
            cin >> A[i+1][j+1];
        }
    }

    vector<Coord> ans;

    FOR(i,1,H+1){
        FOR(j,1,W+1){
            if(A[i][j]%2 == 1){
                REP(n,4){
                    if(A[i+dy[n]][j+dx[n]]%2 == 1){
                        A[i+dy[n]][j+dx[n]]++;
                        A[i][j]--;
                        ans.push_back({i,j,i+dy[n],j+dx[n]});
                        break;
                    }else if(A[i+dy[n]][j+dx[n]]%2==0 && n==3){
                        if(i!=H){
                            A[i+1][j]++;
                            A[i][j]--;
                            ans.push_back({i,j,i+1,j});
                        }else if(i==H && j!=W){
                            A[i][j+1]++;
                            A[i][j]--;
                            ans.push_back({i,j,i,j+1});
                        }else if(i==H && j==W){
                            continue;
                        }
                    }
                }
            }
        }
    }

    cout << ans.size() << endl;
    REP(i,ans.size()){
        cout << ans[i].x1 << " " << ans[i].y1 << " " << ans[i].x2 << " " << ans[i].y2 << endl;
    }


    return 0;
}