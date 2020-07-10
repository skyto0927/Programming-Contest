#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    string N; cin >> N;
    
    if(N.size()<=2){
        cout << 0 << endl;
        return 0;
    }

    int dp[12][2][2][2][2];
    REP(i,12){
        REP(k,2){
            REP(l,2){
                REP(m,2){
                    REP(n,2){
                        dp[i][k][l][m][n] = 0;
                    }
                }
            }
        } 
    }

    dp[0][0][0][0][0] = 1;
    FOR(i,1,N.size()-2){
        dp[i][1][0][0][0] = 1;
    }

    REP(i,N.size()){//何桁目
        REP(smaller,2){//Smaller？
            REP(three,2){
                REP(five,2){
                    REP(seven,2){
                        REP(x, (smaller?10:(N[i]-'0')+1) ){
                            if(x!=3 && x!=5 && x!=7) continue;
                            //x=3,5,7のみ考慮
                            

                            //N[i]の値で変わっていく
                            dp[i+1][smaller || x<(N[i]-'0')][three || x==3][five || x==5][seven || x==7] += dp[i][smaller][three][five][seven];
                        }
                    }
                }
            }
        }           
    }

    
    cout << dp[N.size()][0][1][1][1] + dp[N.size()][1][1][1][1] << endl;


    return 0;
}