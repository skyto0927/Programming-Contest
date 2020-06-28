#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    int N; 
    cin >> N;
    vector<vector <int>> xy(N, vector<int>(2));


    vector<int> P(N);
    REP(i,N){
        cin >> xy[i][0] >> xy[i][1];
        P[i] = i;
    }

    double sum = 0.0;
    int count = 0;
    do{ // do-while で変化する条件の繰り返しを「後」に書ける！！
        FOR(i,0,N-1){
            sum += sqrt(pow((xy[P[i]][0] - xy[P[i+1]][0]),2) + pow((xy[P[i]][1] - xy[P[i+1]][1]),2));
        }
        count ++;
    }while (next_permutation(ALL(P)));//next_permutationで順列の全探索できる


//fixed ...小数点以下指定
//setprecision ...何桁表示するか(fixedがあれば小数以下の)
    cout << fixed << setprecision(10) << sum/count << endl;


    return 0;
}
