#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,K;
    cin >> N >> K;
    string S;
    cin >> S;

    if(S[K-1] == 'A'){
        S[K-1] = 'a';
    }
    if(S[K-1] == 'B'){
        S[K-1] = 'b';
    }
    if(S[K-1] == 'C'){
        S[K-1] = 'c';
    }

    cout << S << endl;
    return 0;
}
