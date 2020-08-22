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
    int N; cin >> N;
    int a = 0;
    int b = 0;
    int l = 0;
    FOR(i,1,N){
        int dist;
        cout << "? " << a+1 << " " << i+1 << endl;
        cin >> dist;
        if(l<dist){
            l = dist;
            b = i;
        }
    }
    l = 0;
    REP(i,N){
        if(i==b) continue;
        int dist;
        cout << "? " << b+1 << " " << i+1 << endl;
        cin >> dist;
        if(l<dist){
            l = dist;
        }
    }
    cout << "! " << l << endl;
    return 0;
}