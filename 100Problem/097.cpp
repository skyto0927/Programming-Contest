#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

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

int main() {
    int N,M; cin >> N >> M;
    vector<int> A(N);
    REP(i,N){
        cin >> A[i];
    }

    int a = A[0];
    int p = 0;
    while (a%2 == 0){
        a/=2;
        p++;
    }

    int evens = pow(2,p);

    REP(i,N){
        if(A[i]%evens!=0 || A[i]%(evens*2)==0){
            cout << 0 << endl;
            return 0;
        }
    }

    ll L = A[0];

    REP(i,N-1){
        L = lcm(L,A[i+1]);
    }

    L/=2;

    ll ans = M/L;
    if(ans%2 == 0){
        cout << ans/2 << endl;
    }else{
        cout << ans/2+1 << endl;
    }

    
    return 0;
}