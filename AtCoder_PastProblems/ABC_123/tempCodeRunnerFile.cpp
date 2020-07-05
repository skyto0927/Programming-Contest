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

bool solve(ll P){
    int count = 0;
    REP(i,X*Y){
        REP(j,Z){
            if(AB[i] + C[j] >= P){
                count ++;
                if(count >= K){
                    return true;
                }
            }else{
                break;
            }
        }
    }
    return false;
}

ll binary_search(ll M){
    ll ng = -1;
    ll ok = M;
    while(abs(ok-ng)>1){
        ll mid = (ok+ng)/2;
        //cout << ng << ", " << mid << ", " << ok << endl;
        if(solve(mid)){//ここに条件をかく
            ng = mid;
        }else{
            ok = mid;
        }
    }
    return ng;
}

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
    sort(ALL(AB), greater<ll>());
    sort(ALL(C), greater<ll>());


    ll border = binary_search(AB[0]+C[0]);

    int count = 0;
    vector<ll> ans;
    bool finish = false;
    REP(i,X*Y){
        REP(j,Z){
            if(AB[i] + C[j] >= border){
                count ++;
                ans.push_back(AB[i] + C[j]);
                if(count >= K){
                    finish = true;
                    break;
                }
            }else{
                break;
            }
        }
        if(finish){
            break;
        }
    }
    sort(ALL(ans), greater<ll>());
    
    REP(i,K){
        cout << ans[i] << endl;
    }

    return 0;
}