#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int H,W,K; cin >> H >> W >> K;

    vector<vector<int>> M_origin(H, vector<int>(W));


    int b_count = 0;
    REP(i,H){
        string S; cin >> S;
        REP(j,W){
            if(S[j] == '.'){
                M_origin[i][j] = 0;
            }else if(S[j] == '#'){
                M_origin[i][j] = 1;
                b_count ++;
            }
        }
    }

    

    int ans = 0;

    REP(bit_h,1<<H){
        vector<int> h;
        REP(x,H){
            if(bit_h & 1<<x){
                h.push_back(x);
            }
        }
        REP(bit_w, 1<<W){
            vector<int> w;
            REP(y,W){
                if(bit_w & 1<<y){
                    w.push_back(y);
                }
            }

            //ここに処理
            vector<vector<int>> M(M_origin);
            
            for(auto hh: h){
                REP(j,W){
                    M[hh][j] = 0;
                }
            }
            for(auto ww: w){
                REP(j,H){
                    M[j][ww] = 0;
                }
            }

            int count = 0;
            REP(i,H){
                REP(j,W){
                    if(M[i][j] == 1)count ++;
                }
            }


            if(count == K) {
                ans ++;
                // REP(i,H){
                //     REP(j,W){
                //         cout << M[i][j];
                //     }
                //     cout << endl;
                // }
                // cout << endl;

            }

        }
    }
    cout << ans << endl;


    return 0;
}