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
    vector<int> a(N);
    REP(i,N){
        cin >> a[i];
    }

    sort(ALL(a));

    int ng = -1;
    int ok = N-1;
    while(abs(ok-ng)>1){
        int mid = (ok+ng)/2;
        if(2*a[mid] > a[N-1]){//ここに条件をかく
            ok = mid;
        }else{
            ng = mid;
        }
    }

    int ok_d = abs(a[N-1]-a[ok]*2);
    int ng_d = abs(a[N-1]-a[ng]*2);

    if(ok_d<ng_d) cout << a[N-1] << " " << a[ok] << endl;
    else cout << a[N-1] << " " << a[ng] << endl;

    return 0;
}