#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    char b;
    cin >> b;
    if(b=='A'){
        cout << "T" << endl;
    }else if(b=='T'){
        cout << "A" << endl;
    }else if(b=='C'){
        cout << "G" << endl;
    }else if(b=='G'){
        cout << "C" << endl;
    }

    return 0;
}