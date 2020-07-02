#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int K; cin >> K;
    string S; cin >> S;

    if(S.size() <= K){
        cout << S << endl;
    }else{
        REP(i,K){
            cout << S[i];
        }
        cout << "..." << endl;
    }
    return 0;
}