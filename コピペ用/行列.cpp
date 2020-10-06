#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9


int main() {
    return 0;
}
///////////////////////////////////////////////////////

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