#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

template <typename T> bool next_combination(T first, T last, int k){
    T subset = first + k;
    if (first==last || first==subset || last==subset){
        return false;
    }
    T src = subset;
    while(first != src){
        src--;
        if(*src < *(last-1)){
            T dest = subset;
            while(*src >= *dest){
                dest++;
            }
            iter_swap(src, dest);
            rotate(src+1, dest+1, last);
            rotate(subset, subset+(last-dest)-1, last);
            return true;
        }
    }
    rotate(first, subset, last);
    return false;
}

struct Edge
{
    int to, cost;
};


int main() {
    int n,m,p,q,r; cin >> n >> m >> p >> q >> r;
    vector<vector<Edge>> G(n);
    REP(i,r){
        int x,y,z; cin >> x >> y >> z;
        x--; y--;
        G[x].push_back({y,z});
    }

    vector<int> girl(n);
    REP(i,n) girl[i] = i;

    int ans = 0;

    do{
        vector<int> boy(m,0);
        REP(i,p){
            for(auto b: G[girl[i]]){
                boy[b.to] += b.cost;
            }
        }
        int sum = 0;
        sort(ALL(boy), greater<int>());
        REP(i,q) sum += boy[i];

        ans = max(ans, sum);

    }while(next_combination(ALL(girl), p));

    cout << ans << endl;
    return 0;
}