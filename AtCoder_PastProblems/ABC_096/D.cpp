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
    int N; cin >> N;

    vector<int> table = get_prime_numbers(55555);
    
    int cnt = 0;
    REP(i, 55556){
        if(table[i]==1 && i%10==1){
            cout << i << " ";
            cnt++;
            if(cnt==N){
                cout << endl;
                break;
            }
        }
    }

    return 0;
}