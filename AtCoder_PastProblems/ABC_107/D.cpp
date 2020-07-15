#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18

template<class T> struct BIT{
    vector<T> bit;
    int M;

    BIT(int M_):
        M(M_+1), bit(M,0) {}

    T sum(int a){//sum [1,i) 1_indexed!!!!
        int ret = 0;
        for(int i=a; i>0; i-= i & -i) ret += bit[i];
        return ret;
    }
    
    T sum(int a, int b){//sum [i,j)  1_indexed!!!!
        return sum(b-1) - sum(a-1);
    }

    void add(int a, T x){
        for(int i=a; i<M; i+= i & -i) bit[i] += x;
    }

    void print(){
        FOR(i,1,M){
            cout << sum(i,i+1) << " ";
        }
        cout << endl;
    }

};

ll inversion(vector<int> d){
    
    BIT<ll> bit(d.size() *2);
    ll ans = 0;
    REP(i,d.size()){
        ans += i - bit.sum(d[i] + d.size());
        bit.add(d[i]+d.size(), 1);
    }
    //bit.print();
    
    return ans;
}

ll count(vector<int> a, int m){
    vector<int> b(a.size());
    vector<int> c(a.size()+1,0);
    vector<int> d(a.size()+1,0);

    REP(i,a.size()){
        if(a[i]<=m) b[i] = 1;
        else b[i] = 0;

        c[i+1] = c[i] + b[i];
        d[i+1] = 2*c[i+1] - (i+1);
    }

    reverse(ALL(d));
    return inversion(d);
}

int main() {
    int N; cin >> N;
    vector<int> a(N);
    REP(i,N) cin >> a[i];

    int ng = -1;
    int ok = INF;
    while(abs(ok-ng)>1){
        int mid = (ok+ng)/2;
        ll inv = count(a,mid);
        if(inv > (ll)N*(N+1)/4 ){//ここに条件をかく
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;

    return 0;
}