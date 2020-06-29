#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    while(1){
        list<pair<int,int>> cakes;
        int n,w,d; cin >> n >> w >> d;

        if(n==0 && w==0 && d==0){
            return 0;
        }
        cakes.push_back(make_pair(w,d));
        
        REP(i,n){
            int p,s;
            cin >> p >> s;
            p--;
            auto itr = cakes.begin();
            REP(k,p) itr++;
            pair<int,int> piece = *itr;
            cakes.erase(itr);

            int W = piece.first;
            int H = piece.second;
            s %= (W+H);

            if(s<W){
                cakes.push_back(make_pair(min(s,W-s), H));
                cakes.push_back(make_pair(max(s,W-s), H));
            }else{
                s = s-W;
                cakes.push_back(make_pair(W, min(s,H-s)));
                cakes.push_back(make_pair(W, max(s,H-s)));

            }
        }
        
        

        vector<int> result;
        int sizes = cakes.size();
        REP(i,sizes){
            pair<int,int> P = *cakes.begin();
            cakes.pop_front();
            result.push_back(P.first * P.second);
        }

        sort(ALL(result));
        REP(i,result.size()){
            int ans = result[i];
            cout << ans;
            if(i != result.size()-1){
                cout << " ";
            }
        }
        cout << endl;
    }
    

    return 0;
}