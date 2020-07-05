#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,K;
    cin >> N >> K;
    string s;
    cin >> s;

    vector<int> S;
    char current = s[0];
    if(current == '0'){
        S.push_back(0);
    }
    int num = 0;
    REP(i,N){
        if(current == s[i]){
            num++;
        }else{
            S.push_back(num);
            num = 1;
            current = s[i];
        }
    }
    S.push_back(num);
    if(S.size()%2 == 0){
        S.push_back(0);
    }

    if(S.size() <= 2*K+1){
        cout << N << endl;
    }else{
        int ans = 0;
        for(int i=0; i<S.size()-2*K; i+=2){
            int cur = 0;
            FOR(j,i,i+2*K+1){
                cur += S[j];
            }
            ans = max(ans,cur);
        }
        cout << ans << endl;
    }



    return 0;
}