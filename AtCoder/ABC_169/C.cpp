#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9

int main() {
    long long int A;
    string B_str;
    cin >> A >> B_str;


    int B = 100*(B_str[0]-'0') + 10*(B_str[2]-'0') + (B_str[3]-'0');

    if(A==0 || B==0){
        cout << 0 << endl;
        return 0;
    }

    cout << (long long int)((A*B)/100) << endl;
}
