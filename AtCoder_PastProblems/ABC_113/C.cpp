#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


struct City
{
    int ken, year, id;
    bool operator<(const City &o) const{
        return  year < o.year;
    }
};


int main() {
    int N,M; cin >> N >> M;

    vector<City> city(M);
    REP(i,M){
        City c;
        cin >> c.ken >> c.year;
        c.id = i;
        city[i] = c;
    }

    sort(ALL(city));

    map<int,int> m;
    vector<ll> ans(M);

    REP(i,M){
        m[city[i].ken]++;

        ans[city[i].id] = city[i].ken*1000000LL + m[city[i].ken];
    }


    REP(i,M){
        cout << setw(12) << setfill('0') << ans[i] << endl;
    }

    return 0;
}