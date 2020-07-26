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
    int two = 0;
    int four = 0;
    int odd = 0;
    REP(i,N){
        int a; cin >> a;
        if(a%2==1) odd++;
        else if(a%4==2) two++;
        else if(a%4==0) four++;
    }
    if(odd<=four || (odd==four+1 && two==0)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}