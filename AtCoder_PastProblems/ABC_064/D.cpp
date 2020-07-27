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
    string S; cin >> S;
    string l;

    int cnt = 0;
    REP(i,N){
        if(cnt==0){
            if(S[i] == '(')cnt++;
            else l.push_back('(');
        }else if(cnt>0){
            if(S[i] == '(')cnt++;
            else cnt--;
        }
    }

    S = l+S;
    REP(i,cnt) S.push_back(')');
    cout << S << endl;
    return 0;
}