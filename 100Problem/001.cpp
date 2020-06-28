#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9

int main() {
    int n,x;
    while (1){
        cin >> n >> x;
        if (n==0 && x==0){
            return 0;
        }
        
        int count = 0;

        FOR(i,1,n+1){
            FOR(j,i+1,n+1){
                FOR(k,j+1,n+1){
                    if (i+j+k == x){
                        count ++;
                    }
                }
            }
        }
        cout<< count << endl;
    }
}
