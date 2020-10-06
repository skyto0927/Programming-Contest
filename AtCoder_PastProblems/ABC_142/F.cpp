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

vector<int> seen(1000,0);//1,探索中　2,探索済

vector<int> routes;
int loop = -1;

int dfs(vector<vector<int>> &g, int pos){
    
    seen[pos] = 1;
    for(auto e: g[pos]){
        if(seen[e] == 1){
            loop = e;
            routes.push_back(pos);
            return 1;//この時帰りがけに座標保存
            //ループ発見
        }
        if(dfs(g,e) == 1){
            if(e==loop && routes.size()>0){
                return 0;
            }
            routes.push_back(pos);
            return 1;
        }
    }
    seen[pos] = 2;
    return 0;
}

int main() {
    int N,M; cin >> N >> M;
    vector<vector<int>> g(N+1);
    g[0].push_back(1);
    REP(i,M){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
    }

    REP(i,N){
        if(seen[i]==0){
            dfs(g,i);
            if(loop != -1){
                break;
            }
        }
    }

    if(routes.size()==0){
        cout << -1 << endl;
        return 0;
    }

    reverse(ALL(routes));

    set<int> s;
    for(auto e: routes){
        s.insert(e);
    }

    while(1){
        int from = -1;
        int to;
        int id;

        int len = routes.size();
        REP(i,len){
            for(int next: g[routes[i]]){
                REP(j,len){
                    if(next!=routes[(i+1)%len] && next==routes[j]){//途中で短いルートが見つかった場合
                        from = routes[i];
                        to = next;
                        id = j;
                        break;
                    }
                }
            }
        }

        if(from==-1) break;

        vector<int> next_route;
        next_route.push_back(from);
        
        while(routes[id] != from){
            next_route.push_back(routes[id]);
            id = (id+1)%len;
        }
        routes = next_route;
    }

    sort(ALL(routes));

    cout << routes.size() << endl;
    for(auto a: routes){
        cout << a << endl;
    }
    return 0;
}