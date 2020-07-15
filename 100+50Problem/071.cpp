#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

const int MOD = 1e9+7;
const int MAXR = 120100;

template<ll mod> class modint{
public:
    ll val=0;
    //コンストラクタ
    modint(ll x=0){while(x<0)x+=mod;val=x%mod;}
    //コピーコンストラクタ
    modint(const modint &r){val=r.val;}
    //算術演算子
    modint operator -(){return modint(-val);} //単項
    modint operator +(const modint &r){return modint(*this)+=r;}
    modint operator -(const modint &r){return modint(*this)-=r;}
    modint operator *(const modint &r){return modint(*this)*=r;}
    modint operator /(const modint &r){return modint(*this)/=r;}
    //代入演算子
    modint &operator +=(const modint &r){
        val+=r.val;
        if(val>=mod)val-=mod;
        return *this;
    }
    modint &operator -=(const modint &r){
        if(val<r.val)val+=mod;
        val-=r.val;
        return *this;
    }
    modint &operator *=(const modint &r){
        val=val*r.val%mod;
        return *this;
    }
    modint &operator /=(const modint &r){
        ll a=r.val,b=mod,u=1,v=0;
        while(b){
            ll t=a/b;
            a-=t*b;swap(a,b);
            u-=t*v;swap(u,v);
        }
        val=val*u%mod;
        if(val<0)val+=mod;
        return *this;
    }
    //等価比較演算子
    bool operator ==(const modint& r){return this->val==r.val;}
    bool operator <(const modint& r){return this->val<r.val;}
    bool operator !=(const modint& r){return this->val!=r.val;}
};

using mint = modint<MOD>;

//入出力ストリーム
istream &operator >>(istream &is,mint& x){//xにconst付けない
    ll t;is >> t;
    x=t;
    return (is);
}
ostream &operator <<(ostream &os,const mint& x){
    return os<<x.val;
}

//累乗
mint modpow(const mint &a,ll n){
    if(n==0)return 1;
    mint t=modpow(a,n/2);
    t=t*t;
    if(n&1)t=t*a;
    return t;
}

//二項係数の計算
mint fac[MAXR+1],finv[MAXR+1],inv[MAXR+1];
//テーブルの作成
void COMinit() {
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    FOR(i,2,MAXR){
        fac[i]=fac[i-1]*mint(i);
        inv[i]=-inv[MOD%i]*mint(MOD/i);
        finv[i]=finv[i-1]*inv[i];
    }
}
//演算部分
mint COM(ll n,ll k){
    if(n<k)return 0;
    if(n<0)return 0;
    if(k==0) return 1;
    return fac[n]*finv[k]*finv[n-k];
}

int main() {
    int N,Q; cin >> N >> Q;
    vector<int> a(MAXR, 0);
    vector<int> c(MAXR, 0);

    FOR(i,1,N+1){
        cin >> a[i];
    }
    FOR(i,1,Q+1){
        cin >> c[i];
    }

    vector<mint> d(MAXR, 0);
    FOR(i,1,MAXR){
        mint x = a[i-1];
        d[i] = modpow(x, a[i]);
    }
    FOR(i,1,MAXR){
        d[i] += d[i-1];//d[1] 1までの距離 = 0
    }

    c[0] = 1;
    c[Q+1] = 1;

    mint ans = 0;
    REP(i,Q+1){
        if(c[i] > c[i+1]) ans += d[c[i]] - d[c[i+1]];
        if(c[i] < c[i+1]) ans += d[c[i+1]] - d[c[i]];
    }

    cout << ans << endl;

    return 0;
}