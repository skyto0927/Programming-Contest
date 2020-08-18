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
    int N; cin >> N;
    string S; cin >> S;

    string cnt = "b";
    if(S==cnt){
        cout << 0 << endl;
        return 0;
    }
    FOR(i,1,60){
        if(i%3==1) cnt = "a" + cnt + "c";
        else if(i%3==2) cnt = "c" + cnt + "a";
        else if(i%3==0) cnt = "b" + cnt + "b";
        if(S==cnt){
            cout << i << endl;
            return 0;
        }else{
            if(cnt.size() > S.size()){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    return 0;
}