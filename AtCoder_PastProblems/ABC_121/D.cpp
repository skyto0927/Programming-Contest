#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    ll A,B; cin >> A >> B;
    if(A%2==0 && B%2!=0){
        if((B-A+1)%4 == 0){
            cout << 0 << endl;
        }else{
            cout << 1 << endl;
        }
    }else if(A%2==0 && B%2==0){
        if((B-A)%4 == 0){
            cout << B << endl;
        }else{
            cout << (B^1) << endl;
        }
    }else if(A%2!=0 && B%2!=0){
        if((B-A)%4 == 0){
            cout << A << endl;
        }else{
            cout << (A^1) << endl;
        }
    }else if(A%2!=0 && B%2==0){
        if((B-A-1)%4 == 0){
            cout << (A^B) << endl;
        }else{
            cout << ((A^B)^1) << endl;
        }
    }
    return 0;
}