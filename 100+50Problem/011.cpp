#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin, (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> k(M);
    vector<vector<int>> s;
    REP(i,M){
         cin >> k[i];
         vector<int> ss(k[i]);
         REP(j,k[i]){
             cin >> ss[j];
             ss[j]--;
         }
         s.push_back(ss);
    }

    vector<int> p(M);
    REP(i,M) cin >> p[i];

    int ans = 0;

    for (int bit=0; bit<(1<<N); bit++){//bitで全探索
        bool flag = true;

        for (int i=0; i<M; i++){
            int count=0;
            for (int j=0; j<k[i]; j++){
                if((bit>>s[i][j]) & 1){//bitはN桁　ランプにつながるスイッチのインデックス分だけ右シフトすることで、1の桁がわかる
                    count++;
                }
            }
            if (count%2 != p[i]){
                flag = false;
            }
        }

        if(flag){
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
