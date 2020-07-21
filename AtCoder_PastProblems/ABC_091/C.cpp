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

    vector<pair<int,int>> points(2*N);
    REP(i,N){
        int a,b; cin >> a >> b;
        points[a] = {b,0};
    }

    REP(i,N){
        int a,b; cin >> a >> b;
        points[a] = {b,1};
    }

    int ans = 0;
    REPR(i,2*N-1){
        if(points[i].second==0){
            int min_itr = INF;
            int min_y = INF;
            FOR(j,i+1,2*N){
                if(points[i].first<points[j].first && points[j].second==1){
                    if(min_y > points[j].first){
                        min_y = points[j].first;
                        min_itr = j;
                    }
                }
            }
            if(min_y!=INF){
                ans++;
                points[min_itr].second = -1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

/*
貪欲に解く
最右の赤に対して、それより右にある条件を満たす青のうちy座標が最も小さいものを選ぶ
これにより以降の選択肢を狭めることなく選択していくことができる！
*/