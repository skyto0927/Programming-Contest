#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    string N; cin >> N;
    vector<int> A(4,0);
    REP(i,4){
        A[i] = N[i]-'0';
    }
    REP(i,2){
        REP(j,2){
            REP(k,2){
                int num = A[0];
                num += (i==1?A[1]:-A[1]);
                num += (j==1?A[2]:-A[2]);
                num += (k==1?A[3]:-A[3]);
                if(num==7){
                    cout << A[0];
                    cout << (i==1?"+":"-");
                    cout << A[1];
                    cout << (j==1?"+":"-");
                    cout << A[2];
                    cout << (k==1?"+":"-");
                    cout << A[3];
                    cout << "=7" << endl;
                    return 0;
                }
            }
        }
    }
    

    return 0;
}