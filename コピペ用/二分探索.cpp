#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    return 0;
}
///////////////////////////////////////////////////////

int binary_search(int key, vector<int> A){
    int ng = -1;
    int ok = (int)A.size();
    while(abs(ok-ng)>1){
        int mid = (ok+ng)/2;
        if(){//ここに条件をかく
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ok;
}