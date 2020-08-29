#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N; cin >> N;
    map<string,int> S;
    REP(i,N){
        string s; cin >> s;
        S[s]++;
    }
    int ans = 0;
    string name;
    for(auto s: S){
        if(s.second > ans){
            ans = s.second;
            name = s.first;
        }
    }
    cout << name << endl;
    return 0;
}