#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

int score(int left, int N, int center){
    int l = left - center;
    if(l > 0){
        return N*(N-1)/2 + l*N;
    }else if(l+N-1 < 0){
        return N*(N-1)/2 + (-l - N + 1)*N;
    }else{
        return l*l + l*(N-1) + N*(N-1)/2;
    }
}

int main() {
    int A,B,C; cin >> A >> B >> C;

    int ans = INF;
    FOR(i,-500,500){
        FOR(j,i+A, 500){
            int tmp = score(i,A,-100) + score(j,B,0);
            int l = max(100-(C-1)/2, j+B);
            tmp += score(l, C, 100);
            ans = min(ans,tmp);
        }
    }

    cout << ans << endl;
    return 0;
}