#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


const int MOD = 1e9+7;
const int MAXR = 510000;

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
    if(n<=0)return 1;
    mint t=modpow(a,n/2);
    t=t*t;
    if(n&1)t=t*a;
    return t;
}

//二項係数の計算
mint fac[MAXR+1],finv[MAXR+1],inv[MAXR+1];
//テーブルの作成
void com_init() {
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
mint com(ll n,ll k){
    if(n<k)return 0;
    if(n<0)return 0;
    if(k==0) return 1;
    return fac[n]*finv[k]*finv[n-k];
}

int main() {
    string S; cin >> S;
    int N = S.size();
    vector<ll> q_front(N,0), q_back(N,0);
    vector<ll> a_cnt(N,0), c_cnt(N,0);
    REP(i,N){
        if(S[i]=='A') a_cnt[i]+=1;
        if(S[i]=='?') q_front[i]+=1;

        if(i!=N-1){
            a_cnt[i+1] += a_cnt[i];
            q_front[i+1] += q_front[i];
        }
    }
    REPR(i,N-1){
        if(S[i]=='C') c_cnt[i]+=1;
        if(S[i]=='?') q_back[i]+=1;

        if(i!=0){
            c_cnt[i-1] += c_cnt[i];
            q_back[i-1] += q_back[i];
        }
    }

    mint ans = 0;
    FOR(i,1,N-1){
        if(S[i]=='B' || S[i]=='?'){
            mint a = a_cnt[i-1];
            mint x = q_front[i-1];
            mint front = (a+x)*modpow(3,q_front[i-1]) - (mint)2*x*modpow(3,q_front[i-1]-1);

            mint c = c_cnt[i+1];
            mint y = q_back[i+1];
            mint back = (c+y)*modpow(3,q_back[i+1]) - (mint)2*y*modpow(3,q_back[i+1]-1);
            ans +=  front * back;
            //cout << i << ", " << front << ", " << back << endl;
        }
    }

    cout << ans << endl;
    return 0;
}