#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,M; cin >> N >> M;
    vector<vector<int>> triangle(N+3,vector<int>(N+3,0));
    REP(i,M){
        int A,B,X; cin >> A >> B >> X;
        A--;
        B--;
        triangle[A][B] ++;
        triangle[A][B+1] --;
        triangle[A+X+1][B] --;
        triangle[A+X+1][B+X+2] ++;
        triangle[A+X+2][B+1] ++;
        triangle[A+X+2][B+X+2] --;
    }

    REP(i,N-1){
        REP(j,N){
            triangle[i+1][j] += triangle[i][j];
        }
    }
    REP(i,N){
        REP(j,N-1){
            triangle[i][j+1] += triangle[i][j];
        }
    }
    REP(i,N-1){
        REP(j,N-1){
            triangle[i+1][j+1] += triangle[i][j];
        }
    }

    int ans = 0;

    REP(i,N){
        REP(j,i+1){
            if (triangle[i][j] > 0){
                ans ++;
            }
        }
    }

    

    cout << ans << endl;


    return 0;
}