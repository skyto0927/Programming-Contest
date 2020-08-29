#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
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

//素因数分解
vector<pair<int,int>> prime_fact(int n){
    vector<pair<int,int>> a;
    if (n <= 1) return a;
    int n_origin = n;
    for(int i=2; i<=(int)sqrt(n_origin); i++){
        if (n%i == 0){
            int count = 0;
            while(n%i == 0){
                n/=i;
                count ++;
            }
            a.push_back(make_pair(i, count));
        }
    }
    if (n!=1){
        a.push_back(make_pair(n,1));
    }
    return a;
}

int main() {
    int N; cin >> N;
    vector<int> A(N);
    REP(i,N) cin >> A[i];

    int g = A[0];
    REP(i,N){
        g = __gcd(g,A[i]);
    }
    
    if(g > 1){
        cout << "not coprime" << endl;
        return 0;
    }

    vector<int> table = get_prime_numbers(1e6+1);

    REP(i,N){
        vector<pair<int,int>> p = prime_fact(A[i]);
        for(auto a: p){
            if(table[a.first] == 0){
                cout << "setwise coprime" << endl;
                return 0;
            }else{
                table[a.first] = 0;
            }
        }
    }

    cout << "pairwise coprime" << endl;





    return 0;
}