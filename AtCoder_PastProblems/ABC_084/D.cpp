#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

vector<int> get_prime_numbers(int n){
    vector<int> table(n+1, 1);
    table[0] = 0;
    table[1] = 0;
    for (int i=0; i<=(int)sqrt(n); i++){
        if (table[i]){
            for (int j=2*i; j<=n; j+=i){
                table[j] = 0;
            }
        }
    }
    return table;
}

int main() {
    int Q; cin >> Q;

    vector<int> table = get_prime_numbers(101000);

    vector<int> t(101000,0);
    REP(i,100100){
        if(table[i]==1 && table[(i+1)/2]==1) t[i] = 1;
    }
    REP(i,100100){
        t[i+1] += t[i];
    }

    REP(i,Q){
        int l,r; cin >> l >> r;
        cout << t[r] - t[l-1] << endl;

    }
    return 0;
}