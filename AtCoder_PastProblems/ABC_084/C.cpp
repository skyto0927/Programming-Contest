#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

struct Train
{
    int c,s,f;
};


int main() {
    int N; cin >> N;

    vector<Train> T(N-1);
    REP(i,N-1){
        int c,s,f; cin >> c >> s >> f;
        T[i] = {c,s,f};
    }

    REP(i,N-1){
        int time = 0;
        FOR(j,i,N-1){
            if(time <= T[j].s){
                time = T[j].s + T[j].c;
            }else{//割り切れる場合を考慮した繰り上がり
                time = ((time-1)/T[j].f + 1)*T[j].f + T[j].c;
            }
        }
        cout << time << endl;
    }
    cout << 0 << endl;
    return 0;
}
