#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

const int MAXR = 110000;

vector<bool> get_prime_numbers(int n){
    vector<bool> table(n+1, true);
    table[0] = false;
    table[1] = false;
    for (int i=0; i<=(int)sqrt(n); i++){
        if (table[i]){
            for (int j=2*i; j<=n; j+=i){
                table[j] = false;
            }
        }
    }
    return table;
}

int main() {
    vector<bool> table = get_prime_numbers(MAXR);
    vector<int> like2017(MAXR, 0);

    for(int i=3; i<MAXR; i+=2){
        if(table[i] && table[(i+1)/2]){
            like2017[i]++;
        }
    }
    FOR(i,1,MAXR){
        like2017[i] += like2017[i-1];
    }

    int Q; cin >> Q;

    REP(i,Q){
        int l,r; cin >> l >> r;
        cout << like2017[r] - like2017[l-1] << endl;
    }

    return 0;
}