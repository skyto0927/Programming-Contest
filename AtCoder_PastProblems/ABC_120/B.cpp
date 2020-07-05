#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int A,B,K; cin >> A >> B >> K;
    int count = 0;
    REPR(i,101){
        if(A%i==0 && B%i==0){
            count ++;
            if(count == K){
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}