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
    int N,a; cin >> N >> a;
    a--;
    string k; cin >> k;
    vector<int> B(N);
    REP(i,N){
        cin >> B[i];
        B[i] --;
    }
    vector<int> seen(N,-1);
    seen[a] = 0;
    int cur = a;
    int len = 0;
    int cnt = 0;
    while(1){
        cur = B[cur];
        if(seen[cur] == -1){
            seen[cur] = 0;
            len++;
        }else if(seen[cur] == 0){
            seen[cur] = 1;
            cnt++;
            len++;
        }else if(seen[cur] == 1){
            break;
        }
    }
    len = len-2*cnt+1;
    //cout << len << " " << cnt << endl;

    vector<int> dp(k.size()+1, 0);
    REP(i,k.size()){
        dp[i+1] = (dp[i]*10 + (k[i]-'0')) % cnt;
    }
    int l = dp[k.size()];
    l -= (len%cnt);
    l += cnt;
    l %= cnt;
    if(l==0) l = cnt;
    l += len;
    if(k.size() < 8){
        int kk = stoi(k);
        if(kk < l){
            l = kk;
        }  
    }
    cur = a;
    REP(i,l){
        cur = B[cur];
    }
    cout << cur+1 << endl;
    return 0;
}