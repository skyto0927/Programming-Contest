#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

typedef pair<int,int> P;


int main() {
    int N; cin >> N;

    map<int,int> A;
    map<int,int> B;
    REP(i,N/2){
        int v1,v2; cin >> v1 >> v2;
        A[v1] ++;
        B[v2] ++;
    }

    priority_queue<P> AA;
    priority_queue<P> BB;
    for(auto a: A){
        AA.push({a.second, a.first});
    }
    for(auto b: B){
        BB.push({b.second, b.first});
    }

    P top_a = AA.top(); AA.pop();
    P top_b = BB.top(); BB.pop();

    if(top_a.second != top_b.second){
        cout << N - top_a.first - top_b.first << endl;
    }else{
        if(!AA.empty() && !BB.empty()){
            if(top_a.first+BB.top().first > top_b.first+AA.top().first){
                cout << N - top_a.first - BB.top().first << endl;
            }else{
                cout << N - top_b.first - AA.top().first << endl;
            }
        }else if(AA.empty() && !BB.empty()){
            cout << N/2 - BB.top().first << endl;

        }else if(!AA.empty() && BB.empty()){
            cout << N/2 - AA.top().first << endl;
        }else{
            cout << N/2 << endl;
        }
    }

    return 0;
}