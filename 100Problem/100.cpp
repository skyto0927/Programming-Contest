#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<int> table(101000,0);
    int index = 1;
    int d = 2;
    while (index<=100000){
        table[index] = d;
        index += d;
        d++;
    }

    if(table[N] > 0){
        int h = table[N];
        cout << "Yes" << endl;
        vector<vector<int>> ans(h);

        REP(i,h){
            ans[i].push_back(h-1);
        }

        int n = 1;
        FOR(i,0,h-1){
            FOR(j,i+1,h){
                ans[i].push_back(n);
                ans[j].push_back(n);
                n++;
            }
        }

        cout << h << endl;
        REP(i,h){
            REP(j, h){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }

     }else{
         cout << "No" << endl;
     }
    return 0;
}