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
    int a,b; cin >> a >> b;

    if(b<15) cout << "C" << " ";
    else{
        int cnt = 0;
        a+=112;
        while(a >= 225){
            a -= 225;
            cnt ++;
        }

        switch (cnt)
        {
        case 0:
            cout << "N" << " ";
            break;
        case 1:
            cout << "NNE" << " ";
            break;
        case 2:
            cout << "NE" << " ";
            break;
        case 3:
            cout << "ENE" << " ";
            break;
        case 4:
            cout << "E" << " ";
            break;
        case 5:
            cout << "ESE" << " ";
            break;
        case 6:
            cout << "SE" << " ";
            break;
        case 7:
            cout << "SSE" << " ";
            break;
        case 8:
            cout << "S" << " ";
            break;
        case 9:
            cout << "SSW" << " ";
            break;
        case 10:
            cout << "SW" << " ";
            break;
        case 11:
            cout << "WSW" << " ";
            break;
        case 12:
            cout << "W" << " ";
            break;
        case 13:
            cout << "WNW" << " ";
            break;
        case 14:
            cout << "NW" << " ";
            break;
        case 15:
            cout << "NNW" << " ";
            break;
        case 16:
            cout << "N" << " ";
            break;
        }
    }


    if(b < 15) cout << 0 << endl;
    else if(b < 93) cout << 1 << endl;
    else if(b < 201) cout << 2 << endl;
    else if(b < 327) cout << 3 << endl;
    else if(b < 477) cout << 4 << endl;
    else if(b < 645) cout << 5 << endl;
    else if(b < 831) cout << 6 << endl;
    else if(b < 1029) cout << 7 << endl;
    else if(b < 1245) cout << 8 << endl;
    else if(b < 1467) cout << 9 << endl;
    else if(b < 1707) cout << 10 << endl;
    else if(b < 1959) cout << 11 << endl;
    else cout << 12 << endl;

    return 0;
}