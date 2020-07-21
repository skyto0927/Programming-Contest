#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


vector<vector<int>> circle(12,vector<int>(4,0));

struct Play{
    string s;
    int x,y;
};
deque<Play> ans;

int M,N;

void rotate(int x, int y){
    vector<int> num(12,0);
    REP(i,12) num[i] = circle[i][x];//別配列に保持
    REP(i,12) circle[(i+y)%12][x] = num[i];//反時計周りに回転
}

void rotate_reverse(int x, int y){
    vector<int> num(12,0);
    REP(i,12) num[i] = circle[i][x];//別配列に保持
    REP(i,12) circle[(12+i-y)%12][x] = num[i];//反時計周りに回転
}

void slide(int x, int y){
    vector<int> num(8,0);
    REP(i,4) num[i] = circle[(x+6)%12][3-i];
    REP(i,4) num[i+4] = circle[x][i];

    REP(i,4) circle[(x+6)%12][3-i] = num[(i+y)%8];
    REP(i,4) circle[x][i] = num[(i+y+4)%8];
}

void slide_reverse(int x, int y){
    vector<int> num(8,0);
    REP(i,4) num[i] = circle[(x+6)%12][3-i];
    REP(i,4) num[i+4] = circle[x][i];

    REP(i,4) circle[(x+6)%12][3-i] = num[(8+i-y)%8];
    REP(i,4) circle[x][i] = num[(8+i-y+4)%8];
}

void output(){
    REP(i,M){
        auto a = ans.front(); ans.pop_front();
        if(a.s == "rotate"){
            cout << "内側から" << a.x+1 << "マス目のリングを";
            if(a.y<=6)  cout << " 反時計回りに" << a.y << "マス回転" << endl;
            else cout << " 時計回りに" << 12-a.y << "マス回転" << endl;
        }else{
            cout << "" << a.x+1 << "列目を ";
            if(a.y<=4) cout << a.y << "マス内側にスライド" << endl;
            else cout << 8-a.y << "マス外側にスライド" << endl;
        }
        ans.push_back(a);
    }
    cout << endl;
}

void solve(int m){

    if(m==0){
        int cnt = 0;

        REP(i,12){
            bool ok = true;
            REP(j,4){
                if(circle[i][j] == 0) ok = false;
            }
            if(ok){
                cnt++;
            }
        }

        REP(i,12){
            bool ok = true;
            REP(j,2){
                REP(k,2){
                    if(circle[(i+j)%12][k] == 0) ok = false;
                    if(circle[(i+j)%12][k+2] == 1) ok = false;
                }
            }
            if(ok){
                cnt++;
                i++;
            }
        }

        if(cnt == N/4){
            output();
            return;
        }
    }else{


        REP(i,4){//内側から何列目
            FOR(j,1,12){//何回転

                bool is_empty = true;
                REP(x,12) if(circle[x][i]==1) is_empty = false;
                if(is_empty)continue;

                ans.push_back({"rotate", i,j});
                rotate(i,j);
                solve(m-1);

                ans.pop_back();
                rotate_reverse(i,j);
            }
        }

        REP(i,6){//どの列を
            FOR(j,1,8){//どれだけスライド

                bool is_empty = true;
                REP(x,4) if(circle[i][x]==1) is_empty = false;
                REP(x,4) if(circle[(i+6)%12][x]==1) is_empty = false;
                if(is_empty){
                    continue;
                }

                ans.push_back({"slide", i,j});    
                slide(i,j);
                solve(m-1);

                ans.pop_back();
                slide_reverse(i,j);
            }
        }
    }
}


int main() {

    cin >> M;//操作回数
    cin >> N;//敵の数
    REP(i,N){
        int a,b; cin >> a >> b;//1-indexed
        a--;
        b--;
        circle[a][b] = 1;//a...theta b...abs
    }

    solve(M);


    return 0;
}