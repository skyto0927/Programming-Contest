#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


const int MAX_DIGIT = 60;

const int MAX_COL = 100100;
const int MAX_ROW = 512;


struct BitMatrix{
    int H,W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m=1, int n=1) : H(m), W(n) {}

    inline bitset<MAX_COL> &operator [] (int i) {return val[i];}
};

int GaussJordan(BitMatrix &A, bool is_extended = false){
    vector<bool> used(A.H, 0);
    REP(col, A.W){//左の列から順に見ていく
        if(is_extended && col==A.W-1) break;
        int pivot = -1;
        REP(row,A.H){
            if(used[row]) continue;
            if(A[row][col]){//値が1の行を見つけたら、その行を保存する
                pivot = row;
                break;
            }
        }
        if(pivot == -1) continue;//その列が全部ゼロなら次へ
        //swap(A[pivot],A[rank]);
        //各行が何桁目かを表すのでswapはしちゃいけない

        REP(row,A.H){//自身の行以外で、
            if(row!=pivot && A[row][col]) A[row] ^= A[pivot];
        }
        used[pivot] = true;
    }
    return 0;
}


int main() {
    int N; cin >> N;
    vector<ll> A(N);
    REP(i,N){
        cin >> A[i];
    }

    ll ans = 0;
    BitMatrix B(MAX_DIGIT+1,N+1);
    vector<bool> cannot(MAX_DIGIT+1,0);
    REPR(d, MAX_DIGIT){
        int num = 0;
        REP(i,N){
            if(A[i]&(1ll<<d)) num++;
        }

        if(num==0){//0の場合は何も寄与しないのでスルー
            cannot[d]=1;
            continue;
        }else if(num%2==1){//奇数の場合は繰り上がりが絶対起きないのでスルー
            cannot[d] = 1;
            ans += 1ll<<d;
            continue;
        }

        REP(i,N){
            if(A[i] & (1ll<<d)) B[MAX_DIGIT-d][i] = 1;
        }
        B[MAX_DIGIT-d][N] = 1;
    }
    GaussJordan(B,true);

    REPR(d,MAX_DIGIT){
        if(cannot[d]) continue;//どうでもいい桁はスルー

        bool ok = false;

        REP(i,N){//0=nの左辺判定
            if(B[MAX_DIGIT-d][i]) ok = true;
        }
        if(!B[MAX_DIGIT-d][N]) ok = true;//~=0となるか判定
        if(ok) ans += (2ll<<d);
    }
    cout << ans << endl;


    return 0;
}