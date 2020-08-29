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
    int N,K; cin >> N >> K;
    string S; cin >> S;
    vector<int> table(26,0);
    REP(i,N){
        table[S[i]-'a'] ++;
    }

    string ans;
    int cnt = 0;
    REP(i,N){
        string tmp = ans;

        for(char j='a'; j<='z'; j++){
            vector<int> T(table);
            int tmp_cnt = cnt;
            if(T[j-'a'] == 0) continue;
            
            T[j-'a']--;
            tmp.push_back(j);
            if(S[i] != j) tmp_cnt++;
            FOR(k,i+1,N){
                if(T[S[k]-'a'] > 0){
                    T[S[k]-'a']--;
                }else{
                    tmp_cnt++;
                }
            }
            if(tmp_cnt <= K){
                if(S[i] != j) cnt++;
                ans.push_back(j);
                table[j-'a']--;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}