#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9


int main() {
    return 0;
}
///////////////////////////////////////////////////////
typedef pair<ll,ll> P;

P gcd(int a, int b){//(x,y)を返す
    if (a%b==0){
        return {0,1};
    }
    else{
        int k = a/b;
        P tmp = gcd(b,a%b);
        return {-tmp.second, tmp.first-k*tmp.second};
    }
}
