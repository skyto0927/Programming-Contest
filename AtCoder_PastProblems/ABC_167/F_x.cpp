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
    vector<pair<int,int>> S_top;
    vector<pair<int,int>> S_bottom;
    REP(i,N){
        string s;
        cin >> s;

        int count = 0;
        REPR(j,s.size()-1){
            if(s[j] == ')'){
                count ++;
            }else if(s[j] == '('){
                if(count > 0){
                    count --;
                    s.erase(j,2);
                }else{
                    count = 0;
                }
            }
        }
        if(s.size() != 0){
            int c = 0;
            REP(j,s.size()){
                if(s[j] == ')'){
                    c++;
                }
            }
            if((int)s.size()-2*c >= 0){
                S_top.push_back(make_pair(c, s.size()-c));
            }else{
                S_bottom.push_back(make_pair(s.size()-c, c));
            }
        }
    }

    sort(ALL(S_top));
    sort(ALL(S_bottom), greater<pair<int,int>>());

    int q = 0;
    bool ok = true;

    for(auto i: S_top){
        q -= i.first;
        if(q<0){
            ok = false;
        }else{
            q += i.second;
        }
    }

    for(auto i: S_bottom){
        q -= i.second;
        if(q<0){
            ok = false;
        }else{
            q += i.first;
        }
    }

    if (q != 0){
        ok = false;
    }

    if(ok){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


    return 0;
}