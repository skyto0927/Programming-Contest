#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


void fall(vector<vector<int>>& board, int H, int W){
    REP(n,H){
        for(int i=H; i>=1; i--){
            REP(j,W){
                if(board[i][j]==0){
                    board[i][j]=board[i-1][j];
                    board[i-1][j]=0;
                }
            }
        }
    }
}

int main() {
    
    int H,W,K; cin >> H >> W >> K;

    vector<vector<int>> board_origin(H+1, vector<int>(W, 0));
    vector<vector<int>> board(H+1, vector<int>(W, 0));
    FOR(i,1,H+1){
        string S;
        cin >> S;
        REP(j,W){
            
            board_origin[i][j] = S[j] - '0';
        }
    }

    int ans_max = 0;

    FOR(i,1,H+1){
        REP(j,W){//はじめに消すモノを全探索

            FOR(x,0,H+1){
                REP(y,W){
                    board[x][y] = board_origin[x][y];
                }
            }

            board[i][j] = 0;
            fall(board,H,W);

            int counter = 1;
            int ans = 0;
            int ans_before = 0;


            while(1){
                FOR(i,1,H+1){
                    int num = 0;
                    int count = 0;
                    REP(j,W){
                        if(num == board[i][j]){
                            count++;
                            if(count >= K && j==W-1){
                                ans += pow(2,counter-1) * count * num;
                                for(int k= j; k>=j-count+1; k--){
                                    board[i][k] = 0;
                                }
                            }
                        }else{
                            if(count >= K){
                                ans += pow(2,counter-1) * count * num;
                                for(int k= j-1; k>=j-count; k--){
                                    board[i][k] = 0;
                                }
                            }
                            num = board[i][j];
                            count = 1;
                        }
                    }  
                }
                fall(board,H,W);

                if(ans == ans_before){
                    ans_max = max(ans_max, ans);
                    break;
                }
                ans_before = ans;
                counter ++;

                // FOR(i,1,H+1){
                //     REP(j,5){
                //         cout << board[i][j] << " ";
                //     }
                //     cout << endl;
                // }
            }
        }
    }
    cout << ans_max << endl;
    return 0;
}