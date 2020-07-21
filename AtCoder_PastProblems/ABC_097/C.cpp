#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    string S; cin >> S;
    int K; cin >> K;

    int N = S.size();
    set<string> dic;

    REP(n,K){
        REP(i,N-n){
            string s;
            REP(j,n+1){
                s.push_back(S[i+j]);
            }
            dic.insert(s);
        }
    }


    auto itr = dic.begin();
    REP(i,K-1) itr++;

    cout << *itr << endl;

    return 0;
}