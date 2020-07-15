#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

using Graph = vector<vector<int>>;
int W,H;

int main() {
    cin >> W >> H;

    H+=2;
    W+=2;
    Graph building(H, vector<int>(W, 0));
    REP(i,H-2){
        REP(j,W-2){
            cin >> building[i+1][j+1];
        }
    }

    vector<vector<vector<pair<int, int>>>> G(H,vector<vector<pair<int, int>>>(W, vector<pair<int, int>>()));
    REP(i,H){
        REP(j,W){
            if (j != W-1){//右端以外なら
                G[i][j].push_back(make_pair(i,j+1));
                G[i][j+1].push_back(make_pair(i,j));
            }

            if (i != H-1){//下端以外なら
                G[i][j].push_back(make_pair(i+1,j));
                G[i+1][j].push_back(make_pair(i,j));
            }

            if (i%2==1 && j!=W-1 && i!=H-1){//奇数列目、右端以外、下端以外
                G[i][j].push_back(make_pair(i+1,j+1));
                G[i+1][j+1].push_back(make_pair(i,j));
            }else if (i%2==0 && j!=0 && i!=H-1){//偶数列目、左端以外、下端以外
                G[i][j].push_back(make_pair(i+1,j-1));
                G[i+1][j-1].push_back(make_pair(i,j));
            }
        }
    }

    queue<pair<int,int>>q;
    q.push(make_pair(0,0));
    building[0][0] = -1;

    while(!q.empty()){
        auto v = q.front();
        q.pop();
        

        for (auto next: G[v.first][v.second]){
            if (building[next.first][next.second]==0){
                q.push(next);
                building[next.first][next.second] = -1;
            }
        }
    }


    int sum = 0;
    REP(i,H){
        REP(j,W){

            if(building[i][j] == -1){
                for (auto n: G[i][j]){
                    if (building[n.first][n.second]==1) sum ++;
                }
            }
        }
    }

    cout << sum << endl;
    return 0;



    // cin >> W >> H;
    // Graph building(H, vector<int>(W));
    // REP(i,H){
    //     REP(j,W){
    //         cin >> building[i][j];
    //     }
    // }

    // vector<vector<vector<pair<int, int>>>> G(H,vector<vector<pair<int, int>>>(W, vector<pair<int, int>>()));
    // REP(i,H){
    //     REP(j,W){
    //         if (j != W-1){//右端以外なら
    //             G[i][j].push_back(make_pair(i,j+1));
    //             G[i][j+1].push_back(make_pair(i,j));
    //         }

    //         if (i != H-1){//下端以外なら
    //             G[i][j].push_back(make_pair(i+1,j));
    //             G[i+1][j].push_back(make_pair(i,j));
    //         }

    //         if (i%2==0 && j!=W-1 && i!=H-1){//奇数列目、右端以外、下端以外
    //             G[i][j].push_back(make_pair(i+1,j+1));
    //             G[i+1][j+1].push_back(make_pair(i,j));
    //         }else if (i%2==1 && j!=0 && i!=H-1){//偶数列目、左端以外、下端以外
    //             G[i][j].push_back(make_pair(i+1,j-1));
    //             G[i+1][j-1].push_back(make_pair(i,j));
    //         }
    //     }
    // }


    // REP(i,H){//囲われた部分を塗り潰し
    //     REP(j,W){
    //         if (building[i][j] == 0){
    //             bool surrounded = true;

    //             if(i==0 || i==H-1 || j==0 || j==W-1){
    //                 surrounded = false;
    //             }else{

    //                 queue<pair<int,int>> q0;
    //                 q0.push(make_pair(i,j));

    //                 while(!q0.empty()){
    //                     auto v0 = q0.front();
    //                     q0.pop();
    //                     building[v0.first][v0.second] = -1;

    //                     if(v0.second==0 || v0.second==W-1 || v0.first==0 || v0.first==H-1){
    //                         surrounded = false;
    //                         break;
    //                     }

    //                     for (auto next: G[v0.first][v0.second]){//pair
    //                         int next_x = next.second;
    //                         int next_y = next.first;
    //                         if (building[next_y][next_x]==0){
    //                             q0.push(next);
    //                         }
                            
    //                     }
    //                 }
    //             }
                
    //             REP(i,H){
    //                 REP(j,W){
    //                     if (surrounded && building[i][j] == -1){
    //                         building[i][j] = 1;
    //                     }else if (!surrounded && building[i][j] == -1){
    //                         building[i][j] = 0;
    //                     }
    //                 }
    //             }
    //         }
            
    //     }
    // }

    // // REP(i,H){
    // //     REP(j,W){
    // //         cout << building[i][j] << " ";
    // //     }
    // //     cout << endl;
    // // }



    // vector<vector<bool>> checked(H, vector<bool>(W,false));

    // int v_sum = 0;
    // int building_sum = 0;

    // REP(i,H){
    //     REP(j,W){
    //         if (!checked[i][j]){
    //             checked[i][j] = true;

    //             if(building[i][j] == 1){
    //                 queue<pair<int,int>> q;
    //                 q.push(make_pair(i,j));
                    

    //                 building_sum ++;
                    

    //                 while(!q.empty()){

    //                     auto v = q.front();
    //                     q.pop();

    //                     for (auto next: G[v.first][v.second]){//pair
    //                         int next_x = next.second;
    //                         int next_y = next.first;
    //                         if (building[next_y][next_x]==1){
    //                             v_sum ++;
    //                             if (!checked[next_y][next_x]){
    //                                 q.push(next);
    //                                 checked[next_y][next_x] = true;
    //                                 building_sum ++;
    //                             }
    //                         }
                            
    //                     }
    //                 }
    //             }
    //         }
            
    //     }
    // }
    
    //cout << 6*building_sum - v_sum << endl;

    //return 0;
}