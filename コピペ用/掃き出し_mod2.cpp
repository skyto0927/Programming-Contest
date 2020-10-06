#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9


int main() {
    return 0;
}
///////////////////////////////////////////////////////

const int MAX_COL = 512;
const int MAX_ROW = 512;

struct BitMatrix{
    int H,W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m=1, int n=1) : H(m), W(n) {}

    inline bitset<MAX_COL> &operator [] (int i) {return val[i];}
};

int GaussJordan(BitMatrix &A, bool is_extended = false){
    int rank = 0;
    REP(col, A.W){//左の列から順に見ていく
        if(is_extended && col==A.W-1) break;
        int pivot = -1;
        FOR(row,rank,A.H){
            if(A[row][col]){//値が1の行を見つけたら、その行を保存する
                pivot = row;
                break;
            }
        }
        if(pivot == -1) continue;//その列が全部ゼロなら次へ
        swap(A[pivot],A[rank]);

        REP(row,A.H){//自身の行以外で、
            if(row!=rank && A[row][col]) A[row] ^= A[rank];
        }
        rank++;
    }
    return rank;
}

int linear_equation(BitMatrix A, vector<int> b, vector<int> &res){
    int m = A.H;
    int n = A.W;
    BitMatrix M(m,n+1);
    REP(i,m){
        REP(j,n){
            M[i][j] = A[i][j];
        }
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M,true);

    FOR(row,rank,m){//0=nになったらおかしいので
        if(M[row][n]) return -1;
    }
    res.assign(n,0);
    REP(i,rank){
        res[i] = M[i][n];
    }
    return rank;
}