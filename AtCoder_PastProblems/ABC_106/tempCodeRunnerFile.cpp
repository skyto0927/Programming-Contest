#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    string S; cin >> S;
    ll K; cin >> K;

    ll count = 0;
    char next;
    REP(i,S.size()){
        if(S[i] == '1'){
            count ++;
        }else{
            next = S[i];
            break;
        }
    }
    if(count >= K){
        cout << 1 << endl;
    }else{
        cout << next << endl;
    }
    
    return 0;
}