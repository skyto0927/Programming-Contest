#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int x,y; cin >> x >> y;
    vector<int> A{1,3,5,7,8,10,12};
    vector<int> B{4,6,9,11};

    bool isx=false, isy=false;
    REP(i,A.size()){
        if(A[i]==x) isx = true;
        if(A[i]==y) isy = true;
    }
    if(isx && isy){
        cout << "Yes" << endl;
        return 0;
    }
    isx=false, isy=false;
    REP(i,B.size()){
        if(B[i]==x) isx = true;
        if(B[i]==y) isy = true;
    }
    if(isx && isy){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}