#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9

int main() {
    int N;
    cin >> N;
    int div = 0;
    int count = 0;
    for(int i=1; i<=N; i+=2){
        for (int j=1; j<=i; j++){
            if (i%j == 0){
                div ++;
            }
        }
        if (div == 8){
            count ++;
        }
        div = 0;

    }
    cout << count << endl;
    return 0;
}
