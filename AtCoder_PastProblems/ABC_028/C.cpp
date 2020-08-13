#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
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
    vector<int> A(5);
    REP(i,5) cin >> A[i];
    sort(ALL(A));
    vector<int> sum;

    do{
        int num = 0;
        REP(i,3) num += A[i];
        sum.push_back(num);
    }while(next_combination(ALL(A), 3));
    sort(ALL(sum), greater<int>());
    cout << sum[2] << endl;


    return 0;
}