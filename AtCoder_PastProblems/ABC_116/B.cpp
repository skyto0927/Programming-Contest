#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int s; cin >> s;
    vector<int> a;
    a.push_back(s);
    int count = 1;

    if(s==1){
        cout << 4 << endl;
        return 0;
    }else if(s==2){
        cout << 4 << endl;
        return 0;
    }
    while(1){
        if(s==4){
            cout << count+3 << endl;
            return 0;
        }
        if(s%2==0){
            s = s/2;
        }else{
            s = 3*s+1;
        }
        count ++;
    }
    return 0;
}