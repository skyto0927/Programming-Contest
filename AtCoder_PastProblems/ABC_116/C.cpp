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
    vector<int> H(N); REP(i,N) cin >> H[i];
    int ans = 0;
    while(1){
        bool flag = false;
        int zeros = 0;
        REP(i,N){
            if(H[i]==0 && flag==true){//0以外が続いた後に0が来た場合
                ans ++;
                flag = false;
            }
            if(H[i]==0) zeros++;
            
            if(H[i]!=0){
                H[i]--;
                flag = true;
            }
        }
        if(flag==true) ans++;
        if(zeros==N) break;
    }

    cout << ans << endl;
    return 0;
}