#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    ll X,Y; cin >> X >> Y;
    if(abs(X-Y) <= 1) cout << "Brown" << endl;
    else cout << "Alice" << endl;
    return 0;
}

//テスト

// int main(){
//     vector<vector<int>> G(50,vector<int>(50,-1));
//     G[0][0] = 0;
//     G[0][1] = 0;
//     G[1][0] = 0;
//     G[2][0] = 1;
//     G[0][2] = 1;
//     G[1][1] = 0;

//     FOR(i,3,21){
//         int x = i, y = 0;
//         while(x>=0){
//             int xx = x;
//             int yy = y;
//             bool ok = false;
//             while(yy-2>=0){
//                 xx+=1;
//                 yy-=2;
//                 if(G[xx][yy] == 0){
//                     G[x][y] = 1;
//                     ok = true;
//                     break;
//                 }
//             }

//             xx = x;
//             yy = y;
//             while(xx-2>=0){
//                 xx-=2;
//                 yy+=1;
//                 if(G[xx][yy] == 0){
//                     G[x][y] = 1;
//                     ok = true;
//                     break;
//                 }
//             }
//             if(!ok) G[x][y] = 0;

//             x--;
//             y++;
//         }
//     }

//     REP(i,11){
//         REP(j,11){
//             cout << G[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }