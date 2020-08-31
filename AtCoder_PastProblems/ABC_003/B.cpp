#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    string S,T; cin >> S >> T;
    REP(i,S.size()){
        if(S[i] != T[i]){
            if(S[i]!='@' && T[i]!='@'){
                cout << "You will lose" << endl;
                return 0;
            }else if(S[i]=='@' && T[i]!='@'){
                if(T[i]!='a' && T[i]!='t' && T[i]!='c' && T[i]!='o' && T[i]!='d' && T[i]!='e' && T[i]!='r'){
                    cout << "You will lose" << endl;
                    return 0;
                }
            }else if(S[i]!='@' && T[i]=='@'){
                swap(S[i],T[i]);
                if(T[i]!='a' && T[i]!='t' && T[i]!='c' && T[i]!='o' && T[i]!='d' && T[i]!='e' && T[i]!='r'){
                    cout << "You will lose" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "You can win" << endl;
    return 0;
}