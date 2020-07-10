#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int N,A,B,C;
vector<int> L;

int dfs(int a, int b, int c, int n){
    if (n == N){//末端の処理
        if(a!=0 && b!=0 && c!=0){
            return abs(A-a) + abs(B-b) + abs(C-c) - 30;
        }else{
            return INF;
        }
    }

    int pass = dfs(a,b,c,n+1);//選ばない
    int choice_a = dfs(a+L[n],b,c,n+1) + 10;//Aに使用
    int choice_b = dfs(a,b+L[n],c,n+1) + 10;//Aに使用
    int choice_c = dfs(a,b,c+L[n],n+1) + 10;//Aに使用

    return min({pass, choice_a, choice_b, choice_c});
}

int main() {
    cin >> N >> A >> B >> C;
    L.assign(N,0); REP(i,N) cin >> L[i];

    cout << dfs(0,0,0,0) << endl;

    return 0;
}