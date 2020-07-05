#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


ll X,Y,Z,K;
vector<ll> AB;
vector<ll> C;


int main() {
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X);
    vector<ll> B(Y);
    C.assign(Z,0);
    REP(i,X){
        cin >> A[i];
    }
    REP(i,Y){
        cin >> B[i];
    }
    REP(i,Z){
        cin >> C[i];
    }
    AB.assign(X*Y, 0);
    REP(i,X){
        REP(j,Y){
            AB[i*Y + j] = A[i]+B[j];
        }
    }
    sort(ALL(A), greater<ll>());
    sort(ALL(B), greater<ll>());
    sort(ALL(C), greater<ll>());


    vector<ll> vec;

    REP(i,X){
        REP(j,Y){
            REP(k,Z){
                if((i+1) * (j+1) * (k+1) <= K){
                    vec.push_back(A[i]+ B[j] + C[k]);
                }else{
                    break;
                }
            }
        }
    }

    sort(ALL(vec), greater<ll>());
    
    REP(i,K){
        cout << vec[i] << endl;
    }

    return 0;
}