#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    ll N,A,B,C;
    cin >> N >> A >> B >> C;
    vector<char> ans;
    while(N>0){
        string S;
        cin >> S;
        if (S == "AB"){
            if(A==1 && B==1 && N!=1){
                string ns;
                cin >> ns;
                if(ns=="AB"){
                    ans.push_back('A');
                    ans.push_back('B');
                    N--;
                }else if(ns=="AC"){
                    ans.push_back('A');
                    ans.push_back('C');
                    B--;
                    C++;
                    N--;
                }else if(ns=="BC"){
                    ans.push_back('B');
                    ans.push_back('C');
                    A--;
                    C++;
                    N--;
                }
            }else if(A==0 && B==0){
                cout << "No" << endl;
                return 0;
            }else{
                if(A>=B){
                    ans.push_back('B');
                    A--;
                    B++;
                }else{
                    ans.push_back('A');
                    A++;
                    B--;
                }
            }
        }else if(S == "AC"){
            if(A==1 && C==1 && N!=1){
                string ns;
                cin >> ns;
                if(ns=="AB"){
                    ans.push_back('A');
                    ans.push_back('B');
                    C--;
                    B++;
                    N--;
                }else if(ns=="AC"){
                    ans.push_back('A');
                    ans.push_back('C');
                    N--;
                }else if(ns=="BC"){
                    ans.push_back('C');
                    ans.push_back('B');
                    A--;
                    B++;
                    N--;
                }
            }else if(A==0 && C==0){
                cout << "No" << endl;
                return 0;
            }else{
                if(A>=C){
                    ans.push_back('C');
                    A--;
                    C++;
                }else{
                    ans.push_back('A');
                    A++;
                    C--;
                }
            }
        }else if(S == "BC"){
            if(B==1 && C==1 && N!=1){
                string ns;
                cin >> ns;
                if(ns=="AB"){
                    ans.push_back('B');
                    ans.push_back('A');
                    C--;
                    A++;
                    N--;
                }else if(ns=="AC"){
                    ans.push_back('C');
                    ans.push_back('A');
                    B--;
                    A++;
                    N--;
                }else if(ns=="BC"){
                    ans.push_back('B');
                    ans.push_back('C');
                    N--;
                }
            }else if(B==0 && C==0){
                cout << "No" << endl;
                return 0;
            }else{
                if(B>=C){
                    ans.push_back('C');
                    B--;
                    C++;
                }else{
                    ans.push_back('B');
                    B++;
                    C--;
                }
            }
        }
        N--;
    }
    cout << "Yes" << endl;

    for(auto c: ans){
        cout << c << endl;
    }
    return 0;
}