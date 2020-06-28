
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9


int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<long int>> ar(N, vector<long int>(M));
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> ar[i][j];
        }
    }
    long int max_sum = 0;
    long int sum = 0;
    for (int i=0; i<M-1; i++){
        for (int j=i+1; j<M; j++){

            for(int k=0; k<N; k++){
                sum += max(ar[k][i], ar[k][j]);
            }

        if (max_sum < sum){
            max_sum = sum;
        }
        sum = 0;
        }
    }
    cout << max_sum << endl;

}
