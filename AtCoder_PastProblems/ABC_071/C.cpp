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
    map<ll,int> A;
    REP(i,N){
        int a; cin >> a;
        A[a]++;
    }
    ll max1 = 0;
    ll max2 = 0;
    for(auto a: A){
        if(a.second>=2 && a.second<4){
            max2 = max1;
            max1 = a.first;
        }else if(a.second>=4){
            max1 = a.first;
            max2 = a.first;
        }
    }
    cout << max1*max2 << endl;
    return 0;
}