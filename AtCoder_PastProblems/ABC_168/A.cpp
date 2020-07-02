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
    N %= 10;
    if(N==2 || N==4 || N==5 || N==7 || N==9){
        cout << "hon" << endl;
    }else if(N==0 || N==1 || N==6 || N==8){
        cout << "pon" << endl;
    }else if(N==3){
        cout << "bon" << endl;
    }
    return 0;
}