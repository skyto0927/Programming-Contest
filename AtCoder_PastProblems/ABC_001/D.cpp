#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

typedef pair<int,int> P;

int main() {
    int N; cin >> N;
    vector<P> p(N);
    REP(i,N){
        string s; cin >> s;
        int h1 = 10*(s[0]-'0') + (s[1]-'0');
        int m1 = 10*(s[2]-'0') + (s[3]-'0') - (s[3]-'0')%5;

        int h2 = 10*(s[5]-'0') + (s[6]-'0');
        int m2 = 10*(s[7]-'0');
        int m = s[8]-'0';
        if(1<=m && m<=5) m2 += 5;
        else if(5<=m && m<=9) m2 += 10;
        p[i] = {60*h1+m1, 60*h2+m2};
    }

    sort(ALL(p));
    vector<P> ans;

    P tmp = {p[0].first,p[0].second};
    REP(i,N){
        int l = tmp.first;
        int r = tmp.second;

        if(p[i].first <= r){
            tmp.second = max(r, p[i].second);
        }else{
            ans.push_back(tmp);
            tmp = p[i];
        }
    }
    ans.push_back(tmp);

    for(auto a: ans){
        cout << setw(2) << setfill('0') << a.first/60;
        cout << setw(2) << setfill('0') << a.first%60 << "-";
        cout << setw(2) << setfill('0') << a.second/60;
        cout << setw(2) << setfill('0') << a.second%60 << endl;
    }
    return 0;
}