#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18

struct Edge{
    int from,to,cost;
};

int main() {
    int L; cin >> L;

    int p = 20;
    while(L<(1<<p)){
        p--;
    }

    int N = p+1;

    vector<Edge> ans;
    FOR(i,1,p+1){
        ans.push_back({i, i+1,0});
        ans.push_back({i, i+1, (1<<(i-1))});
    }

    L -= 1<<(N-1);

    while(p>0){
        if(L >= (1<<(p-1))){
            L -= (1<<(p-1));
            ans.push_back({p, N, L+(1<<(N-1)) });
        }
        p--;

    }

    cout << N << " " << ans.size() << endl;



    for(auto x: ans){
        cout << x.from << " " << x.to << " " << x.cost << endl;
    }
    return 0;
}