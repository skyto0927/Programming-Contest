#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

typedef vector<vector<ll>> mat;
ll L,A,B,M;

mat matpow(mat X, mat Y){
    int n = 3;
    mat ans(n, vector<ll>(n,0));
    REP(i,n){
        REP(j,n){
            REP(k,n){
                ans[i][j] += X[i][k]*Y[k][j];
                ans[i][j] %= M;
            }
        }
    }
    return ans;
}

vector<ll> matmul(mat X, vector<ll> Y){
    int n = 3;
    vector<ll> ans(n,0);
    REP(i,n){
        REP(j,n){
            ans[i] += X[i][j]*Y[j];
            ans[i] %= M;
        }
    }
    return ans;
}

void matp(mat X){
    REP(i,3){
        REP(j,3){
            cout << X[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> L >> A >> B >> M;

    vector<ll> S{0,A,1};

    vector<ll> pow10(19);
    pow10[0] = 1;
    REP(i,18){
        pow10[i+1] = 10*pow10[i];
    }
    REP(d,18){
        
        ll l = max(0ll, (ll)ceill(pow10[d]-A)/B);
        ll r = min(L-1, (ll)(pow10[d+1]-A-1)/B);

        ll n = r-l+1;

        if(r == 0) continue;
        if(n < 0) break;

        cout << l <<  " " << r << endl;

        mat X{{(ll)pow10[d+1],1,0}, {0,1,B}, {0,0,1}};

        int c = 0;
        while((1ll<<c) < n) c++;
        vector<mat> mats(c+1);
        mats[0] = X;
        REP(i,c){
            mats[i+1] = matpow(mats[i], mats[i]);
        }
        mat tmp{{1,0,0}, {0,1,0}, {0,0,1}};

        //cout << n << " " << c << endl;
        REP(i,c+1){
            if((1<<i) & n){
                //cout << i << endl;
                tmp = matpow(tmp, mats[i]);

                //matp(mats[i]);
            }
        }

        S = matmul(tmp, S);
        //cout << S[0] << " " <<  S[1] << endl;
    }

    cout << S[0] << " " <<  S[1] << endl;
    return 0;
}