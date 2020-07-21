#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,K; cin >> N >> K;

    vector<vector<pair<int,int>>> G(2*K,vector<pair<int,int>>(2*K,{0,0}));
    REP(i,N){
        int x,y;
        char c;
        cin >> x >> y >> c;
        if(c=='B') G[x%(2*K)][y%(2*K)].first ++;//first : B
        else if(c=='W') G[x%(2*K)][y%(2*K)].second ++;// second : W
    }

    vector<vector<pair<int,int>>> sum(2*K+1,vector<pair<int,int>>(2*K+1,{0,0}));

    REP(i,2*K){
        FOR(j,1,2*K+1){
            sum[i+1][j].first += sum[i][j].first + G[i][j-1].first;
            sum[i+1][j].second += sum[i][j].second + G[i][j-1].second;
        }
    }

    FOR(i,1,2*K+1){
        REP(j,2*K){
            sum[i][j+1].first += sum[i][j].first;
            sum[i][j+1].second += sum[i][j].second;
        }
    }

    // REPR(j,2*K){
    //     REP(i,2*K+1){       
    //         cout << sum[i][j].second << " ";
    //     }cout << endl;
    // }

    vector<int> XY{-K,0,K,2*K};

    int ans = 0;

    REP(i,K){
        REP(j,K){
            int ans1=0, ans2=0;
            REP(x,3){
                REP(y,3){
                    if((x+y)%2==0){
                        ans1 += sum[min(2*K, XY[x+1]+i)][min(2*K, XY[y+1]+j)].first
                        + sum[max(0,XY[x]+i)][max(0,XY[y]+j)].first
                        - sum[max(0,XY[x]+i)][min(2*K, XY[y+1]+j)].first
                        - sum[min(2*K, XY[x+1]+i)][max(0,XY[y]+j)].first;

                        ans2 += sum[min(2*K, XY[x+1]+i)][min(2*K, XY[y+1]+j)].second
                        + sum[max(0,XY[x]+i)][max(0,XY[y]+j)].second
                        - sum[max(0,XY[x]+i)][min(2*K, XY[y+1]+j)].second
                        - sum[min(2*K, XY[x+1]+i)][max(0,XY[y]+j)].second;
                    }else{
                        ans2 += sum[min(2*K, XY[x+1]+i)][min(2*K, XY[y+1]+j)].first
                        + sum[max(0,XY[x]+i)][max(0,XY[y]+j)].first
                        - sum[max(0,XY[x]+i)][min(2*K, XY[y+1]+j)].first
                        - sum[min(2*K, XY[x+1]+i)][max(0,XY[y]+j)].first;

                        ans1 += sum[min(2*K, XY[x+1]+i)][min(2*K, XY[y+1]+j)].second
                        + sum[max(0,XY[x]+i)][max(0,XY[y]+j)].second
                        - sum[max(0,XY[x]+i)][min(2*K, XY[y+1]+j)].second
                        - sum[min(2*K, XY[x+1]+i)][max(0,XY[y]+j)].second;
                    }
                }
            }
            ans = max(ans, ans1);
            ans = max(ans, ans2);
        }
    }

    cout << ans << endl;

    return 0;
}