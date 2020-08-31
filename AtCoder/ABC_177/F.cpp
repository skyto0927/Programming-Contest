#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

typedef pair<int,int> P;

int main() {
    int H,W; cin >> H >> W;
    vector<int> A(H), B(H);
    REP(i,H){
        cin >> A[i] >> B[i];
        A[i]--;
    }

    set<P> S;
    multiset<int> M;
    REP(i,W){
        S.insert({i,i});
        M.insert(0);
    }
    S.insert({W,W});
    M.insert(INF);
    S.insert({-1,INF});

    
    REP(i,H){
        while(1){
            auto itr = lower_bound(ALL(S), P{A[i],0});
            if((*itr).first > B[i]) break;

            M.erase(M.find((*itr).first - (*itr).second));
            S.erase(itr);

            if((*next(itr)).first > B[i]+1){
                int s = (*itr).second;
                S.insert({B[i]+1, s});
                M.insert(B[i]+1-s);
            }
        }
        int x = *M.begin() + i+1;
        if(x >= H+W) x = -1;
        cout << x << endl;
    }

    return 0;
}