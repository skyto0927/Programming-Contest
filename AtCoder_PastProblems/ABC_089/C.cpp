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
    int N; cin >> N;
    vector<ll> march(5,0);
    REP(i,N){
        string S; cin >> S;
        switch (S[0]){
            case 'M':
                march[0]++;
                break;
            case 'A':
                march[1]++;
                break;
            case 'R':
                march[2]++;
                break;
            case 'C':
                march[3]++;
                break;
            case 'H':
                march[4]++;
                break;
        }
    }
    ll ans = 0;
    vector<int> itr(5,0);
    REP(i,5){
        itr[i] = i;
    }
    do{
        ans += march[itr[0]]*march[itr[1]]*march[itr[2]];
    }while(next_combination(ALL(itr), 3));

    cout << ans << endl;
    return 0;
}