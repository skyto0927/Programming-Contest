#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

vector<double> t;
vector<double> v;
vector<double> t_sum;
double ans;

int main() {
    int N; cin >> N;
    t.assign(N,0);
    v.assign(N,0);
    t_sum.assign(N+1,0);
    REP(i,N) cin >> t[i];
    REP(i,N) cin >> v[i];

    REP(i,N) t_sum[i+1] += t_sum[i] + t[i];
    ans = 0.0;

    vector<double> dx;

    for(double x = 0.0; x<=t_sum[N]; x+=0.5){
        int itr = upper_bound(ALL(t_sum), x) - t_sum.begin()-1;
        double num = INF;
        REP(i,N){
            if(i<itr){
                num = min(num, v[i]-t_sum[i+1]+x);
            }else if(i==itr){
                num = min(num, v[i]);
            }else{
                num = min(num, v[i]+t_sum[i]-x);
            }
            num = min(num, x);
            num = min(num, t_sum[N]-x);
        }
        dx.push_back(num);
    }

    REP(d,dx.size()-1){
        ans += (dx[d] + dx[d+1])/4.0;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}