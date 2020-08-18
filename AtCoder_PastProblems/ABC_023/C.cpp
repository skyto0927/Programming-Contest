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
    int R,C,K; cin >> R >> C >> K;
    int N; cin >> N;

    vector<int> row(N), col(N);
    REP(i,N){
        cin >> row[i] >> col[i];
        row[i]--;
        col[i]--;
    }

    vector<int> rsum(R,0), csum(C,0);
    REP(i,N){
        rsum[row[i]]++;
        csum[col[i]]++;
    }

    vector<int> rcnt(K,0), ccnt(K,0);
    REP(i,R){
        
    }


    return 0;
}