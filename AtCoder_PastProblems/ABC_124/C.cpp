#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    string S;
    cin >> S;

    int a = 0;
    REP(i,S.size()){
        if(i%2 == S[i]-'0'){
            a++;
        }
    }

    cout << min(a, (int)(S.size()-a)) << endl;

    return 0;
}