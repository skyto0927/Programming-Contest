#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    return 0;
}
///////////////////////////////////////////////////////
int gcd(int a, int b){
    if (a%b==0){
        return (b);
    }
    else{
        return (gcd(b,a%b));
    }
}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}