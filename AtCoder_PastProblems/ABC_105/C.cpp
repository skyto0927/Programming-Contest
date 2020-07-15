#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


int main() {
    int N; cin >> N;
    string S;
    if(N==0){
        cout << 0 << endl;
        return 0;
    }
    while(N!=0){
        if(N>0){
            if(N%2==0) S.push_back('0');
            else S.push_back('1');

            N/=2;
            N = -N;
        }else{
            N = -N;
            N++;
            if(N%2==0) S.push_back('1');
            else S.push_back('0');

            N/=2;
        }
    }
    reverse(ALL(S));
    cout << S << endl;

    return 0;
}