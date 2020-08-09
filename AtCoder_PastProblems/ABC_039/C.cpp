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
    string s; cin >> s;
    string key = "WBWBWWBWBWBW";
    REP(i,12){
        string x;
        REP(j,12){
            x.push_back(s[(i+j)%12]);
        }
        if(x==key){
            switch (i)
            {
            case 0:
                cout << "Do" << endl;
                break;
            case 10:
                cout << "Re" << endl;
                break;
            case 8:
                cout << "Mi" << endl;
                break;
            case 7:
                cout << "Fa" << endl;
                break;
            case 5:
                cout << "So" << endl;
                break;
            case 3:
                cout << "La" << endl;
                break;
            case 1:
                cout << "Si" << endl;
                break;     
            }
            return 0;
        }
    }
    return 0;
}