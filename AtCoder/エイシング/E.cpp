#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;



int main() {
    int T; cin >> T;
    while(T>0){
        int N; cin >> N;
        vector<vector<int>> fr(N+1);
        vector<vector<int>> bc(N+1);

        ll ans = 0;
        REP(i,N){
            int k,l,r; cin >> k >> l >> r;
            ans += min(l,r);
            if(l-r>0) fr[k].push_back(l-r);
            else bc[N-k].push_back(r-l);
        }

        priority_queue<int, vector<int>, greater<int>> q_fr;
        priority_queue<int, vector<int>, greater<int>> q_bc;
        FOR(i,1,N+1){
            for(auto j: fr[i]) q_fr.push(j);
            while(q_fr.size()>i) q_fr.pop();

            for(auto j: bc[i]) q_bc.push(j);           
            while(q_bc.size()>i) q_bc.pop();
        }

        while(!q_fr.empty()){
            ans += q_fr.top(); q_fr.pop();
        }
        while(!q_bc.empty()){
            ans += q_bc.top(); q_bc.pop();
        }

        cout << ans << endl;       

        T--;
    }
    return 0;
}