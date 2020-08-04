#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    string s1,s2,s3; cin >> s1 >> s2 >> s3;
    int a,b,c;
    a = s1.size();
    b = s2.size();
    c = s3.size();
    int i=0,j=0,k=0;
    char t = 'a';
    while(1){
        if(t=='a'){
            if(i==a){
                cout << 'A' << endl;
                return 0;
            }
            t = s1[i];
            i++;
        }else if(t=='b'){
            if(j==b){
                cout << 'B' << endl;
                return 0;
            }
            t = s2[j];
            j++;
        }else if(t=='c'){
            if(k==c){
                cout << 'C' << endl;
                return 0;
            }
            t = s3[k];
            k++;
        }
    }
    return 0;
}