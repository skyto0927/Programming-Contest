#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

const int MOD = 1000000007;

int main() {
    int N,K;
    cin >> N >> K;
    vector<int> A(N);

    int sum = 0;
    REP(i,N){
        cin >> A[i];
        sum += A[i];
    }

    vector<int> div;
    FOR(i,1,(int)sqrt(sum)+ 1){
        if (sum%i == 0){
            div.push_back(i);
            if(i != sum/i){
                div.push_back(sum/i);
            }
        }
    }
    sort(ALL(div), greater<int>());

    REP(i,div.size()){
        vector<int> a;
        int d = div[i];
        REP(j,N){
            if (A[j] % d != 0){
                a.push_back(A[j] % d);
            }
        }
        sort(ALL(a));


        vector<int> s(a.size()+1);
        vector<int> sr(a.size()+1);

        s[0] = 0;
        sr[a.size()] = 0;


        REP(x, a.size()){
            s[x+1] = s[x] + a[x];
        }

        REP(x, a.size()){
            sr[a.size()-x-1] = sr[a.size()-x] + a[a.size()-x-1] - d;
        }

        REP(x, a.size()+1){
            if(s[x] + sr[x] == 0 && s[x]<=K){
                cout << d << endl;
                return 0;
            }
        }
    }
    return 0;
}

//イテレータでやろうとしたけどTLE
//1ずつの加減はまどろっこしいし時間かかるので、極力直接考える
//累積和はこういう時に有効！！