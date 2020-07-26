#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int H,W; cin >> H >> W;
    int N; cin >> N;
    vector<int> a(N);
    REP(i,N) cin >> a[i];

    vector<vector<int>> G(H,vector<int>(W,0));

    int h=0,w=0;
    REP(i,N){
        while(a[i]>0){
            G[h][w] = i+1;
            a[i]--;
            if(h%2==0){
                if(w!=W-1) w++;
                else h++;
            }else{
                if(w!=0) w--;
                else h++;
            }
        }
    }

    REP(i,H){
        REP(j,W){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}