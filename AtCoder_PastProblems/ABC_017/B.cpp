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
    string X; cin >> X;
    int i = 0;
    while(i<X.size()){
        if(X[i]=='o'|| X[i]=='k' || X[i]=='u'){
            i++;
            continue;
        }else if(X[i] == 'c'){
            if(i!=X.size()-1){
                if(X[i+1] == 'h'){
                    i+=2;
                    continue;
                }
            }
        }
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}