#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> Q(N);
    REP(i,N)cin >> P[i];
    REP(i,N)cin >> Q[i];

    vector<int> D(N);
    REP(i,N)D[i] = i+1;

    int p,q;
    int count = 0;
    int indexP, indexQ;
    do{
        bool flagP = true;
        bool flagQ = true;
        REP(i,N){
            if(P[i] != D[i])flagP = false;
            if(Q[i] != D[i])flagQ = false;
        }

        if(flagP)indexP = count;
        if(flagQ)indexQ = count;
        count++;
    }while(next_permutation(ALL(D)));

    cout << abs(indexP - indexQ) << endl;
    return 0;
}
