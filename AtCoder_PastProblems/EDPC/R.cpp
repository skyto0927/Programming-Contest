
#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}

const int MOD = 1e9+7;

struct Matrix{
    vector<vector<ll>> val;
    Matrix(int n, int m, ll x=0): val(n,vector<ll>(m,x)) {}
    void init (int n, int m, ll x = 0) {val.assign(n,vector<ll>(m,x));}

    size_t size() const{return val.size();}
    inline vector<ll>& operator [] (int i){return val[i];}
};

Matrix operator * (Matrix A, Matrix B){
    Matrix C(A.size(), B[0].size());
    REP(i,A.size()){
        REP(j,B[i].size()){
            REP(k,B.size()){
                C[i][j] = (C[i][j] + A[i][k]*B[k][j]%MOD)%MOD;
            }
        }
    }
    return C;
}

Matrix pow(Matrix A, ll n){
    Matrix C(A.size(), A.size());
    REP(i,A.size()){
        C[i][i] = 1;
    }
    while(n>0){
        if(n&1) C = C*A;
        A = A*A;
        n = n>>1;
    }
    return C;
}

int main() {
    ll N,K; cin >> N >> K;
    Matrix A(N,N);
    REP(i,N){
        REP(j,N){
            cin >> A[i][j];
        }
    }

    Matrix mat = pow(A, K);
    ll ans = 0;
    REP(i,N){
        REP(j,N){
            ans = (ans+mat[i][j])%MOD;
        }
    }
    cout << ans << endl;
    return 0;
}