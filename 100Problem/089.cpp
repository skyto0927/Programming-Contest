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
    vector<int> A(N);
    vector<int> B;
    REP(i,N){
        cin >> A[i];
    }
    int len = 1;
    REP(index, N){
        if (index == N-1){
            B.push_back(len);
            continue;
        }
        if(A[index] != A[index+1]){
            len++;
        }else{
            B.push_back(len);
            len = 1;
        }
    }

    if(B.size()==1 || B.size()==2){
        cout << N << endl;
    }else{
        int ans = 0;
        REP(i,B.size()-2){
            ans = max(ans, B[i]+B[i+1]+B[i+2]);
        }
        cout << ans << endl;
    }

    return 0;
}