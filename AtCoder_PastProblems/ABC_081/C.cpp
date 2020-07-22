#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,K; cin >> N >> K;
    map<int,int> A;
    REP(i,N){
        int a; cin >> a;
        A[a]++;
    }

    priority_queue<int, vector<int>, greater<int>> ball;
    for(auto i: A){
        ball.push(i.second);
    }

    int ans = 0;
    if(ball.size() <= K){
        cout << 0 << endl;
    }else{
        REP(i,K-ball.size()){
            ans += ball.top(); ball.pop();
        }
        cout << ans << endl;
    }

    return 0;
}