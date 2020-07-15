#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;
    string S; cin >> S;

    int p = 0;
    REP(i,N){
        if(S[i]=='1') p++;
    }

    reverse(ALL(S));

    vector<int> amari0(N);
    vector<int> amari1(N);


    int num0 = 1;
    int num1 = 1;

    ll sum0 = 0, sum1 = 0;

    REP(i,N){
        num0 %= p+1;
        amari0[i] = num0;
        
        if(S[i] == '1'){
            sum0 += num0;
            sum0 %= p+1;
        }
        num0 *= 2;
    }

    if(p!=1){
        REP(i,N){
            num1 %= p-1;
            amari1[i] = num1;
            
            if(S[i] == '1'){
                sum1 += num1;
                sum1 %= p-1;
            }
            num1 *= 2;
        }
    }
    


    // REPR(i,N-1){
    //     if(S[i] == '0'){
    //         cout << (sum0 + amari0[i])%(p+1) << endl;
    //     }else{
    //         cout << (sum1 - amari1[i] + p-1)%(p-1) << endl;
    //     }
    // }

    vector<int> table(200100, 0);
    FOR(i,1,200010){
        int pc = __builtin_popcount(i);
        if(i%pc==0) table[i] = 1;
        else table[i] = table[i%pc]+1;
    }

    vector<int> ans(N,0);
    REP(i,N){
        if(S[i] == '0'){
            ans[i] = table[(sum0 + amari0[i])%(p+1)];
        }else if(S[i] == '1' && p==1){
            ans[i] = -1;
        }else{
            ans[i] = table[(sum1 - amari1[i] + p-1)%(p-1)];
        }
    }


    reverse(ALL(ans));
    REP(i,N){
        cout << ans[i]+1 << endl;
    }

    return 0;
}