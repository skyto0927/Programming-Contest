#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<int> X(N), Y(N);
    REP(i,N){
        cin >> X[i] >> Y[i];
        X[i]--;
        Y[i]--;
    }
    vector<pair<int,int>> P(N);
    REP(i,N){
        P[i] = {X[i], Y[i]};
    }
    sort(ALL(P));


    dsu d(N);//xでやる

    stack<int> S;
    S.push(P[0].second);

    FOR(i,1,N){
        int y = S.top();
        if(y < P[i].second){
            d.merge(y,P[i].second);
        
            S.pop();
            while(!S.empty() && S.top() < P[i].second){
                d.merge(S.top(),P[i].second);
                S.pop();
            }
            S.push(y);
        }else{
            S.push(P[i].second);
        }
    }

    REP(i,N){
        cout << d.size(Y[i]) << endl;
    }

    return 0;
}