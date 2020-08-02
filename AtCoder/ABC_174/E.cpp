#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N,K; cin >> N >> K;
    vector<int> A(N);
    REP(i,N){     
        cin >> A[i];
    }
    sort(ALL(A));

    int ng = 0;
    int ok = A[N-1];
    while(abs(ok-ng)>1){
        int mid = (ok+ng)/2;
        ll cnt = 0;
        REP(i,N){
            cnt += (A[i]-1)/mid;
        }
        if(cnt <= K){//ここに条件をかく
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;
    

    return 0;
}