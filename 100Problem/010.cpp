#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin, (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    int n,q;
    cin >> n;
    vector<int> A(n);
    REP(i,n)cin >> A[i];

    cin >> q;
    vector<int> m(n);
    REP(i,q)cin >> m[i];


    for (int x=0; x<q; x++){
        bool flag = false;
        for (int bit=0; bit< (1<<n); bit++){
            vector<int> S;
            for(int i=0; i<n; i++){
                if(bit & (1<<i)){
                    S.push_back(i);
                }
            }
            int sum = 0;
            for (int i=0; i<S.size(); i++){
                sum += A[S[i]];
            }
            if (sum == m[x]){
                flag = true;
                break;
            }
             
        }

        cout << (flag?"yes":"no") << endl;
    }
    return 0;
    
}
