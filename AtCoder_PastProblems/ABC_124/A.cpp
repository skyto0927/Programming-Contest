#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int A ,B;
    cin >> A >> B;
    if(A>B){
        cout << 2*A-1 << endl;
    }else if(A<B){
        cout << 2*B-1 << endl;
    }else if(A==B){
        cout << A+B << endl;
    }

    return 0;
}