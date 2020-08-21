#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

vector<int> dp(1<<25, -1);
vector<int> table(25,-1);//iが使われている場合の座標
const int MOD = 1e9+7;


bool check(int bit, int pos){//nは入れる座標
    int h = pos/5;
    int w = pos%5;
    bool yoko = false;
    bool tate = false;
    //横から
    if(w==0 || w==4) yoko = true;
    else{
        bool x = bit & (1<<(pos-1));
        bool y = bit & (1<<(pos+1));
        if(x == y) yoko = true;
    }

    if(h==0 || h==4) tate = true;
    else{
        bool x = bit & (1<<(pos-5));
        bool y = bit & (1<<(pos+5));
        if(x == y) tate = true;
    }
    return yoko && tate;
}

int solve(int bit){
    if(dp[bit] != -1) return dp[bit];
    dp[bit] = 0;
    int n = __builtin_popcount(bit);//現在埋めた数の個数
    if(n==0) return dp[0];

    if(table[n-1] != -1){//埋まっている数字の場所が決まっているなら
        if(check(bit&~(1<<table[n-1]), table[n-1])){
            dp[bit] += solve(bit&~(1<<table[n-1]));
            dp[bit] %= MOD;
        }
    }else{  
        REP(i,25){
            if(bit & (1<<i)){//埋まっていれば
                if(check(bit&~(1<<i), i)){
                    dp[bit] += solve(bit&~(1<<i));
                    dp[bit] %= MOD;
                }
            }
        }
    }
    return dp[bit];
}

int main() {
    REP(i,5){
        REP(j,5){
            int a; cin >> a;
            if(a!=0){
                a--;
                table[a] = 5*i + j;
            }
        }
    }

    dp[0] = 1;
    cout << solve((1LL<<25)-1) << endl;

    return 0;
}