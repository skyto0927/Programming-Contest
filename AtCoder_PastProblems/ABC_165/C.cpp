#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

template <typename T> bool next_combination(T first, T last, int k){
    T subset = first + k;
    if (first==last || first==subset || last==subset){
        return false;
    }
    T src = subset;
    while(first != src){
        src--;
        if(*src < *(last-1)){
            T dest = subset;
            while(*src >= *dest){
                dest++;
            }
            iter_swap(src, dest);
            rotate(src+1, dest+1, last);
            rotate(subset, subset+(last-dest)-1, last);
            return true;
        }
    }
    rotate(first, subset, last);
    return false;
}

int main() {
    int N,M,Q;
    cin >> N >> M >> Q;
    vector<int> A(M+N-1);
    REP(i,M+N-1){
        A[i] = i+1;
    }

    vector<vector<int>> itr(Q,vector<int>(4));
    REP(i,Q){
        REP(j,4){
            cin >> itr[i][j];
        }
    }

    int ans = 0;

    do{
        int count = 0;
        vector<int> arr(N);
        REP(n,N){
            arr[n] = A[n] - n;
        }
        REP(i,Q){
            if (arr[itr[i][1]-1] - arr[itr[i][0]-1] == itr[i][2]){
                count += itr[i][3];
            }
        }
        ans = max(ans, count);
    } while(next_combination(ALL(A), N));

    cout << ans << endl;
    return 0;
}