#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    string s; cin >> s;
    int x,y; cin >> x >> y;

    vector<int> move;
    int cnt = 0;
    REP(i,s.size()){
        if(s[i] == 'F'){
            cnt++;
        }else{
            move.push_back(cnt);
            cnt = 0;
        }
    }
    if(cnt!=0) move.push_back(cnt);

    vector<int> X,Y;

    int x_pos = 0;
    int y_pos = 0;

    REP(i,move.size()){
        if(i==0) x_pos = move[i];
        else if(i%2==0) X.push_back(move[i]);
        else Y.push_back(move[i]);
    }

    sort(ALL(X), greater<int>());
    sort(ALL(Y), greater<int>());

    
    REP(i,X.size()){
        if(x_pos < x) x_pos += X[i];
        else x_pos -= X[i];
    }
    REP(i,Y.size()){
        if(y_pos < y) y_pos += Y[i];
        else y_pos -= Y[i];
    }

    if(x==x_pos && y==y_pos) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}