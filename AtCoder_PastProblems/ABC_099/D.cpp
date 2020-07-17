#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
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

int main() {
    int N,C; cin >> N >> C;

    vector<vector<int>> D(C, vector<int>(C));
    REP(i,C){
        REP(j,C){
            cin >> D[i][j];
        }
    }

    vector<vector<int>> G(C, vector<int>(3, 0));
    REP(i,N){
        REP(j,N){
            int c; cin >> c;
            G[c-1][(i+j+2)%3]++;
        }
    }


    vector<int> P(C);
    REP(i,C) P[i] = i;

    ll ans = INF;

    do{
        vector<int> cs = {P[0], P[1], P[2]};
        do{
            ll sum = 0;
            REP(i,C){
                REP(j,3){
                    sum += D[i][cs[j]] * G[i][j];
                }
            }
            ans = min(ans, sum);


        }while (next_permutation(ALL(cs)));

    }while (next_combination(ALL(P), 3));

    cout << ans << endl;

    return 0;
}