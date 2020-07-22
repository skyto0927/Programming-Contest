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
    int a = count(ALL(S), '1');
    int b = count(ALL(S), '0');

    int N = S.size();

    int num0 = N;
    int num1 = N;
    REP(i,N){
        if(S[i]=='0') num0 = min(num0, max(i,N-i-1));
        else num1 = min(num1, max(i,N-i-1));
    }
    bool same = true;
    REP(i,N){
        if(S[i]!='0') same = false;
    }
    if(same){
        cout << N << endl;
        return 0;
    }

    same = true;
    REP(i,N){
        if(S[i]!='1') same = false;
    }
    if(same){
        cout << N << endl;
        return 0;
    }

    cout << max(num0, num1) << endl;
    
    return 0;
}