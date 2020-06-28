#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


void fill_board(vector<vector<char> > &board, int x_init, int y_init){//配列と最初の座標
    vector<int> dx{-1,0,1};
    vector<int> dy{-1,0,1};
    board[x_init][y_init] = 'Q';
    REP(a,3){
        REP(b,3){
            int x = x_init;
            int y = y_init;
            if (a==1 && b==1)continue;//{0,0}だけ除外
            x += dx[a];
            y += dy[b];
            while(0<=x && x<8 && 0<=y && y<8){
                board[x][y] = 'X';
                x += dx[a];
                y += dy[b];
            }
        }
    }
}

bool check_board(vector<vector<char> > &board, int x_init, int y_init){
    vector<int> dx{-1,0,1};
    vector<int> dy{-1,0,1};
    REP(a,3){
        REP(b,3){
            int x = x_init;
            int y = y_init;
            if (a==1 && b==1)continue;//{0,0}だけ除外
            x += dx[a];
            y += dy[b];
            while(0<=x && x<8 && 0<=y && y<8){
                if (board[x][y] == 'q' || board[x][y] == 'Q'){
                    return false;
                }
                x += dx[a];
                y += dy[b];
            }
        }
    }
    return true;
}

void solve(vector<vector<char> > &board, int x, int y, int queen_num, bool &finished){

    if (queen_num == 0){//全部配置終わったらテスト
        REP(i,8){
            REP(j,8){
                if (board[i][j]=='q'){
                    if(! check_board(board,i,j)){
                        return;
                    }
                }
            }
        }
        finished = true;
        return;
    }

    if (y == 8){
        x++;
        y=0;
    }

    if (x==8 && y==0)return;
    //cout << "{" << x << ", " <<  y << "}" << endl;

    if(board[x][y] == '.'){
        board[x][y] = 'q';
        solve(board, x, y+1, queen_num-1, finished);

        if(finished) return;
        board[x][y] = '.';
        solve(board, x, y+1, queen_num, finished);
    }else{
        solve(board, x, y+1, queen_num, finished);
    }
}

int main() {
    int k;
    cin >> k;
    vector<int> r(k);
    vector<int> c(k);
    REP(i,k){
        cin >> r[i] >> c[i];
    }

    vector<vector<char> > board(8, vector<char>(8,'.'));

    REP(i,k){
        fill_board(board, r[i], c[i]);
    }

    int queen_num = 8-k;
    bool finished = false;
    solve(board, 0, 0, queen_num, finished);


    REP(i,8){
        REP(j,8){
            if(board[i][j] == '.' || board[i][j] == 'X'){
                cout << '.';
            }
            if(board[i][j] == 'q' || board[i][j] == 'Q'){
                cout << 'Q';
            }
        }
        cout << endl;
    }
        
    

    

    return 0;
}
