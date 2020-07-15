#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> A(R, vector<int>(C));
    vector<vector<int>> a(R, vector<int>(C));
    REP(i,R){
        REP(j,C){
            cin >> A[i][j];
        }
    }

    int maxSum = 0;
    for (int bit=0; bit<(1<<R); bit++){//行は全探索
        int sum = 0;
        for (int i=0; i<R; i++){
            if(bit & (1<<i)){
                REP(j,C){
                    a[i][j] = 1 ^ A[i][j];//XORでひっくり返す
                }
            }else{
                REP(j,C){
                    a[i][j] = A[i][j];
                }
            }
        }
        
        REP(j,C){
            int cSum = 0;
            REP(i,R){
                cSum += a[i][j];
            }
            sum += max(cSum, R-cSum);//列はひっくり返すかどうかで多い方を採用
        }
        maxSum = max(maxSum, sum);
    }

    cout << maxSum << endl;

    return 0;
}
