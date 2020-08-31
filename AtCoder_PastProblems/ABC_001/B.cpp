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
    int m; cin >> m;
    if(m<100){
        cout << "00" << endl;
    }else if(m<=999){
        cout << "0" << m/100 << endl;
    }else if(m<=5000){
        cout << m/100 << endl;
    }else if(m <= 30000){
        cout << m/1000 + 50 << endl;
    }else if(m <= 70000){
        cout << (m/1000 - 30)/5 + 80 << endl;
    }else{
        cout << 89 << endl;
    }
    return 0;
}