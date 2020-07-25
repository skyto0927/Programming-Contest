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

//速度の上限が厳しいものに合わせて台形を追加
//その範囲を除いて再帰的に解いていく

void dfs(double l, double r, double h){//[l,r]はすでに速度hに達している
    //cout << l << ", " << r << ", " << h << endl;
    if(l>=r) return;

    int l_itr = upper_bound(ALL(t_sum), l) - t_sum.begin() - 1;//左端はどの区間か
    int r_itr = lower_bound(ALL(t_sum), r) - t_sum.begin() - 1;//右端はどの区間か
    //cout << "  " << l_itr << ", " << r_itr << endl;

    if(r_itr == l_itr){//[l,r]が同一区間内なら
        if(r-l > 2*(v[r_itr]-h)){
            ans += ((r-l) - (v[r_itr]-h)) * (v[r_itr]-h);
            return;
        }else{
            ans += (r-l)*(r-l)/4.0;
            return;
        }
    }

    double min_v = INF;
    int min_itr = -1;
    FOR(i,l_itr,r_itr+1){//区間内の最小速度を求める
        if(min_v > v[i]){
            min_v = v[i];
            min_itr = i;
        }
    }
    //cout << "    " << min_v << ", " << min_itr << endl;

    if((r-l) <= 2*(min_v-h)){//そもそも台形にならないなら
        ans += (r-l)*(r-l)/4.0;
        return;
    }

    double l1,r1,l2,r2;
    l1 = l+min_v-h;//台形の上底の両端の値
    r2 = r-min_v+h;

    r1 = t_sum[min_itr];//最小速度の両端の値
    l2 = t_sum[min_itr+1];

    ans += ((r-l) - (min_v-h))*(min_v-h);

    if(r2 < r1 || l2 < l1){//上記値の範囲で場合わけ
        dfs(l1, r2, min_v);
    }else if(r1<=l1 && l1<=l2){
        dfs(l2, r2, min_v);
    }else if(r1<=r2 && r2<=l2){
        dfs(l1, r1, min_v);
    }else{
        dfs(l1,r1,min_v);
        dfs(l2,r2,min_v);
    }
}

int main() {
    int N; cin >> N;
    t.assign(N,0);
    v.assign(N,0);
    t_sum.assign(N+1,0);
    REP(i,N) cin >> t[i];
    REP(i,N) cin >> v[i];

    REP(i,N) t_sum[i+1] += t_sum[i] + t[i];
    ans = 0.0;
    dfs(0,t_sum[N],0);
    cout << ans << endl;
    return 0;
}