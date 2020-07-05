#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e12
typedef long long ll;


//////////////////ここの値は必ず確認！！！！！////////////////////
//---------------------------------------------------------//
const int MOD = 1e9+7;
const int MAXR = 510000;
//---------------------------------------------------------//

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
    ll N,K; cin >> N >> K;

    vector<pair<ll,ll>> A;

    ll minus_count = 0;
    REP(i,N){
        ll a; cin >> a;
        if(a>0){
            A.push_back({a,1});
        }else if (a<0){
            A.push_back({-a,-1});
            minus_count++;
        }else if (a==0){
            A.push_back({0,1});       
        }
    }
    sort(ALL(A), greater<pair<ll,ll>>());

    ll ans = 1;

    if(K==N){//K=Nの場合は全部かけるしかない
        REP(i,K){
            ans *= A[i].first*A[i].second;
            ans %= MOD;
        }
        cout << (ans+MOD)%MOD << endl;
        return 0;
    }

    if(minus_count == N && K%2 == 1){//全部負で奇数個選ぶ場合は負になるしかない
        REP(i,K){
            ans *= A[N-1-i].first*A[N-1-i].second;
            ans %= MOD;
        }
        cout << (ans+MOD)%MOD << endl;
        return 0;
    }


    
    REP(i,K){
        ans *= A[i].first*A[i].second;
        ans %= MOD;
    }

    if(ans >= 0){
        cout << ans << endl;
        return 0;
    }else if(ans < 0){

        ll x1 = INF;//負をぬく
        ll y1 = INF;

        ll x2 = INF;//正をぬく
        ll y2 = INF;
        

        REP(i,K){
            if(A[i].second == 1){
                x2 = A[i].first*A[i].second;               
            }else{
                x1 = A[i].first*A[i].second;       
            }
        }
        for(int j=N-1; j>=K;j--){
            if(A[j].second == -1){
                y2 = A[j].first*A[j].second;
            }else{
                y1 = A[j].first*A[j].second;
            }
        }

        mint a = ans;

        if(x1==INF || y1==INF){
            a = a/mint(x2)*mint(y2);
        }else if(x2==INF || y2==INF){
            a = a/mint(x1)*mint(y1);

        }else{
            if(x2*y1 <= x1*y2){
                a = a/mint(x2)*mint(y2);
            }else{
                a = a/mint(x1)*mint(y1);
            }
        }

        cout << a << endl;
        return 0;
    }
}