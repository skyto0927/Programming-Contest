#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


bool is_prime_number(int n){
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n%2 == 0) return false;
    for(int i=3; i<=(int)sqrt(n); i+=2){
        if (n%i == 0) return false;
    }
    return true;
}

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