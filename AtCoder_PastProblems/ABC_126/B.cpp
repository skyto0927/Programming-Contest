#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int S;
     cin >> S;
    int left = S/100;
    int right = S - left*100;

    if(1<=left && left<=12 && 1<=right && right <= 12){
        cout << "AMBIGUOUS" << endl;
    }
    if((1<=left && left<=12) && (right<1 || 12<right)){
        cout << "MMYY" << endl;
    }
    if((left<1 || 12<left) && (1<=right && right<=12)){
        cout << "YYMM" << endl;
    }
    if((left<1 || 12<left) && (right<1 || 12<right)){
        cout << "NA" << endl;
    }
    return 0;
}
