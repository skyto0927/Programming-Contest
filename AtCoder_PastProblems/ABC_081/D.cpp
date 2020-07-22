#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<int> A(N);
    int max_a = -INF;
    int max_index = -1;
    int min_a = INF;
    int min_index = -1;
    REP(i,N){
        int a; cin >> a;
        A[i] = a;

        if(max_a < a){
            max_a = a;
            max_index = i;
        }
        if(min_a > a){
            min_a = a;
            min_index = i;
        }
    }


    if(min_a>=0){//全部非負の場合
    cout << N-1 << endl;
        REP(i,N-1){
            cout << i+1 << " " << i+2 << endl;
        }
    }else if(max_a<0){//全部負の場合
        cout << N-1 << endl;
        REP(i,N-1){
            cout << N-i << " " << N-i-1 << endl;
        }
    }else{
        if(max_a >= -min_a){
            cout << 2*N-2 << endl;
            REP(i,N){
                if(i!=max_index) cout << max_index+1 << " " << i+1 << endl;
            }
            REP(i,N-1){
                cout << i+1 << " " << i+2 << endl;
            }
        }else{
            cout << 2*N-2 << endl;
            REP(i,N){
                if(i!=min_index) cout << min_index+1 << " " << i+1 << endl;
            }
            REP(i,N-1){
                cout << N-i << " " << N-i-1 << endl;
            }
        }
    }


    return 0;
}