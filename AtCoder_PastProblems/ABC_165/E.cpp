#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,M;
    cin >> N >> M;
    if(N%2 == 1){
        REP(i,M){
            cout << i+1 << " " << N-i << endl;
        }

    }else{
        int sa = N-1;
        int c = 0;
        REP(i,M){
            if(sa==N/2 || sa==N/2-1){
                c = 1;
            }
            cout << i+1 << " " << N-i-c << endl;
            sa -= 2;
        }
    }
    return 0;
}