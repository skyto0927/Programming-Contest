#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

ll K,M;

typedef vector<vector<ll>> matrix;

const ll ONE = (1LL<<32)-1;

matrix mul(matrix X, matrix Y){
    matrix ans(K, vector<ll>(K,0));
    REP(i,K){
        REP(j,K){
            REP(k,K){
                ans[i][j] ^= X[i][k] & Y[k][j];
            }
        }
    }
    return ans;
}

void print(matrix X){
    REP(i,K){
        REP(j,K){
            cout << X[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    cin >> K >> M;
    vector<ll> A(K);
    REP(i,K) cin >> A[i];
    
    vector<ll> C(K);
    REP(i,K) cin >> C[i];

    if(M < K){
        cout << A[M-1] << endl;
        return 0;
    }

    M = M-K;

    matrix D(K, vector<ll>(K,0));


    REP(i,K){
        D[0][i] = C[i];
    }

    FOR(i,1,K){
        D[i][i-1] = ONE;
    }

    ll d = 0;
    while((1<<d) <= M) d++;

    matrix zeros(K, vector<ll>(K,0));

    vector<matrix> bits(d+1);
    bits[0] = D;

    REP(x,d){
        bits[x+1] = mul(bits[x], bits[x]);
    }

    matrix mat(K, vector<ll>(K,0));
    REP(i,K) mat[i][i] = ONE;

    REP(bit,d){
        if((1<<bit) & M){
            mat = mul(mat, bits[bit]);
        }
    }

    //print(mat);

    ll ans = 0;
    REP(i,K){
        ans ^= mat[0][i] & A[K-1-i];
    }

    cout << ans << endl;

    return 0;
}