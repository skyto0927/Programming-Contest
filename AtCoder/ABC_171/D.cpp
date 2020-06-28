#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int>A(N);
    ll sum = 0;
    vector<int> nums(10e5+1,0);
    REP(i,N){
        cin >> A[i];
        nums[A[i]]++;
        sum += A[i];

    }
    int Q;
    cin >> Q;
    vector<vector<int>> BC(Q, vector<int>(2));
    REP(i,Q) cin >> BC[i][0] >> BC[i][1];

    REP(i,Q){
        sum += (BC[i][1]-BC[i][0]) * nums[BC[i][0]];
        nums[BC[i][1]] += nums[BC[i][0]];
        nums[BC[i][0]] = 0;
        cout << sum << endl;
    }

    return 0;
}
