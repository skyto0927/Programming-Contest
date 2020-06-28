#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

struct JOI
{
    int j,o,i;
};


int main() {
    int M, N; cin >> M >> N;
    int K; cin >> K;
    vector<vector<JOI>> region(M+1,vector<JOI>(N+1, {0,0,0}));
    FOR(i,1,M+1){
        string S;
        cin >> S;
        FOR(j,1,N+1){
            switch (S[j-1]){
                case 'J':
                    region[i][j].j++;
                    break;
                case 'O':
                    region[i][j].o++;
                    break;
                case 'I':
                    region[i][j].i++;
                    break;  
            }    
        }
    }

    REP(i,M+1){
        REP(j,N){
            region[i][j+1].j += region[i][j].j;
            region[i][j+1].o += region[i][j].o;
            region[i][j+1].i += region[i][j].i;
        }
    }
    REP(i,M){
        REP(j,N+1){
            region[i+1][j].j += region[i][j].j;
            region[i+1][j].o += region[i][j].o;
            region[i+1][j].i += region[i][j].i;
        }
    }

    REP(k,K){
        int a,b,c,d; cin >> a >> b >> c >> d;
        cout << region[c][d].j - region[c][b-1].j - region[a-1][d].j + region[a-1][b-1].j << " ";
        cout << region[c][d].o - region[c][b-1].o - region[a-1][d].o + region[a-1][b-1].o << " ";
        cout << region[c][d].i - region[c][b-1].i - region[a-1][d].i + region[a-1][b-1].i << endl;
    }
    return 0;
}