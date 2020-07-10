#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

vector<int> table(101,0);

void prime_fact(int n){
    if (n <= 1) return;
    int n_origin = n;
    for(int i=2; i<=(int)sqrt(n_origin); i++){
        if (n%i == 0){
            int count = 0;
            while(n%i == 0){
                n/=i;
                count ++;
            }
            table[i] += count;
        }
    }
    if (n!=1){
        table[n] ++;
    }
}


int main() {
    int N; cin >> N;

    FOR(i,1,N+1) prime_fact(i);

    int count2 = 0;
    int count4 = 0;
    int count14 = 0;
    int count24 = 0;
    int count74 = 0;

    REP(i,N+1){
        if(table[i]>=2) count2 ++;
        if(table[i]>=4) count4 ++;
        if(table[i]>=14) count14 ++;
        if(table[i]>=24) count24 ++;
        if(table[i]>=74) count74 ++;
    }


    int ans = 0;
    if(count74 > 0) ans += count74;
    if(count2 > 0) ans += (count2-1)*count24;
    if(count4 > 0) ans += (count4-1)*count14;

    if(count2 > 2) ans += (count2-2)*count4*(count4-1)/2;

    cout << ans << endl;

    return 0;
}