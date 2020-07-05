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
    int a = 0;
    int w= 0;
    int t=0;
    int r =0;
    REP(i,N){

        
        string S; cin >> S;
        if(S[0] == 'A'){
            a++;
        }else if(S[0] == 'W'){
            w++;
        }else if(S[0] == 'T'){
            t++;
        }else if(S[0] == 'R'){
            r++;
        }
    }
    cout << "AC x " << a << endl;
    cout << "WA x " << w << endl;
    cout << "TLE x " << t << endl;
    cout << "RE x " << r << endl;
    return 0;
}