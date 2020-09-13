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
    string S; cin >> S;
    map<char,int> A;
    REP(i,4){
        A[S[i]]++;
    }

    int cnt = 0;
    for(auto a:A){
        if(a.second == 2)cnt++;
    }
    
    cout << (cnt==2?"Yes":"No") << endl;
    return 0;
}