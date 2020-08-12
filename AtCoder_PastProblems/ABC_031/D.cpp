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
    int K,N; cin >> K >> N;
    vector<string> V(N), W(N);
    REP(i,N){
        cin >> V[i] >> W[i];
    }

    REP(bit,pow(3,K)){
        vector<int> S(K);
        int x = bit;
        REP(j,K){
            S[K-1-j] = x%3+1;
            x/=3;
        }

        vector<string> goro(K);
        bool ok = true;
        REP(j,N){
            int itr = 0;
            REP(k,V[j].size()){
                int num = V[j][k]-'1';
                if(itr + S[num] > W[j].size()){
                    ok = false;
                    break;
                }
                if(goro[num].size()==0){//初出なら保持
                    goro[num] = W[j].substr(itr,S[num]);
                    itr += S[num];
                }else{//複数回目なら正誤判定
                    if(goro[num] != W[j].substr(itr,S[num])){
                        ok = false;
                        break;
                    }else{
                        itr += S[num];
                    }
                }
            }
            if(itr != W[j].size()){
                ok = false;
                break;
            }
            if(!ok) break;
        }
        if(ok){
            REP(i,K){
                cout << goro[i] << endl;
            }
            return 0;
        }
    }
    
    return 0;
}