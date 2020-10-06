#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

int N;
vector<int> table(300,0);
vector<int> remember(300,0);

vector<vector<int>> memo(300,vector<int>(300,-1));

bool dfs(int l, int r){//どちらも偶数であることが保証
    if(memo[l][r] != -1)return (memo[l][r]==1?true:false);
    //cout << l << ", " << r << endl;


    int m = (l+r)/2;
    bool ok = true;
    FOR(i,l,m){
        if(table[i]!=0 && table[i+m-l]!=0){//どちらにも数字がある場合
            if(table[i+m-l] > 0 || table[i] < 0){//矛盾あればダメ
                ok = false;
                break;
            }else if(table[i] != -table[i+m-l]){//数字が違ったらダメ
                ok = false;
                break;
            }
            //それ以外ならOK
        }
        if(table[i]!=0 && table[i+m-l]==0){//前半のみ数字がある場合
            if(table[i] < 0){//前半なのにExitだったらダメ
                ok = false;
                break;
            }else if(remember[table[i]] == 1){//ペアが確定してたらダメ
                ok = false;
                break;
            }
        }
        if(table[i]==0 && table[i+m-l]!=0){//後半のみ数字がある場合
            if(table[i+m-l] > 0){//後半なのにEnterだったらダメ
                ok = false;
                break;
            }else if(remember[-table[i+m-l]] == 1){//ペアが確定してたらダメ
                ok = false;
                break;
            }
        }
    }
    if(ok){//OKならこの区間はうまくいってる
        memo[l][r] = 1;
        return true;
    }

    for(int mid = l+2; mid < r; mid+=2){
        if(dfs(l,mid) & dfs(mid,r)){
            memo[l][r] = 1;
            return true;
        }
    }

    memo[l][r] = 0;
    return false;
}

int main() {
    cin >> N;

    REP(i,N){
        int a, b; cin >> a >> b;
        if(a!=-1){
            if(table[a-1] != 0){//すでに値が入っている場合
                cout << "No" << endl;
                return 0;
            }
            table[a-1] = i+1;
        }
        if(b!=-1){
            if(table[b-1] != 0){//すでに値が入っている場合
                cout << "No" << endl;
                return 0;
            }
            table[b-1] = -(i+1);
        }
        
        if(a!=-1 && b!=-1){
            if(a>b){//乗るより先に降りている場合
                cout << "No" << endl;
                return 0;
            }
            remember[i+1] = 1;
        }
    }

    //REP(i,2*N) cout<< table[i] << " ";
    //cout << endl;
    //FOR(i,1,N+1) cout << remember[i] << " ";
    //cout << endl;

    cout << (dfs(0,2*N)?"Yes":"No") << endl;
    return 0;
}