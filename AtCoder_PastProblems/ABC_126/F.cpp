#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int M,K;
    cin >> M >> K;

    if(K>=pow(2,M)){
        cout << -1 << endl;

    }else if(M==0 && K!=0){
        cout << -1 << endl;
    }else if(M==1 && K==1){
        cout << -1 << endl;
    }else if(M==1 && K==0){
        cout << "0 0 1 1" << endl;
    }else{
        REP(i,pow(2,M)){
            if(i!=K){
                cout << i << " ";
            }
        }
        cout << K << " ";
        REPR(i,pow(2,M)-1){
            if(i!=K){
                cout << i << " ";
            }
        }
        cout << K << endl;

    }
    
  
    return 0;
}
