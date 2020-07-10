#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    string S; cin >> S;
    int y,m,d;
    y = 1000*(S[0]-'0') + 100*(S[1]-'0') + 10*(S[2]-'0') + (S[3]-'0');
    m = 10*(S[5]-'0') + (S[6]-'0');
    d = 10*(S[8]-'0') + (S[9]-'0');


    if(y<2019 || (y==2019&&m<4) || (y==2019&&m==4&&d<=30)){
        cout << "Heisei" << endl;
    }else{
        cout << "TBD" << endl;
    }
    return 0;
}