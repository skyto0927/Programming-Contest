#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int top_bit(ll n){
    int ans = 0;
    while(n>0){
        n /= 2;
        ans++;
    }
    return ans;
}

string digit(ll n){
    string ans;
    while(n>0){
        if(n%2==1)ans += '1';
        else ans += '0';
        n/= 2;
    }
    reverse(ALL(ans));
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<ll> a(N);

    ll sum = 0;
    REP(i,N){
        cin >> a[i];
        if(i>1) sum ^= a[i];
    }
    
    ll A=0;
    ll B=0;
    ll sa = a[0]+a[1]-sum;
    if(sa<0){
        cout << -1 << endl;
        return 0;
    }
    bool next = false;
    REPR(i,50){
        bool s_bit = sum & (1LL<<i);
        bool d_bit = (a[0]+a[1]) & (1LL<<i);
        if(!next){
            if(!s_bit && !d_bit){
                next = false;
            }else if(!s_bit && d_bit){
                next = true;
            }else if(s_bit && d_bit){
                B += pow(2,i);
                next = false;
            }else{
                cout << -1 << endl;
                return 0;
            }
        }else{
            if(!s_bit && !d_bit){
                A += pow(2,i);
                B += pow(2,i);
                next = false;
            }else if(!s_bit && d_bit){
                A += pow(2,i);
                B += pow(2,i);
                next = true;
            }else if(s_bit && d_bit){
                cout << -1 << endl;
                return 0;
            }else{
                B += pow(2,i);
                next = true;
            }
        }
    }
    if(next){
        cout << -1 << endl;
                return 0;
    }

    if(A>a[0]){
        cout << -1 << endl;
        return 0;
    }

    REPR(i,50){
        bool aa = A & (1LL<<i);
        bool bb = B & (1LL<<i);
        if(!aa && bb){
            if(A+pow(2,i) <= a[0]){
                A += pow(2,i);
                B -= pow(2,i);
            }
        }
    }
    if(A==0) cout << -1 << endl;
    else cout << a[0]-A << endl;
    

    return 0;
}
