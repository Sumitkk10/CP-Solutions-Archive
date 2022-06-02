#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, p;
        cin >> n >> p;
        ll a[n+1][n+1];
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j < n; ++j){
                cout << 1 << ' ' << i << ' ' << j << ' ' << i << ' ' << j+1 << endl;
                int x;
                cin >> x;
                if(x == 2){
                    a[i][j] = 1;
                    a[i][j+1] = 1;
                }
                else if(x == 0){
                    a[i][j] = 0;
                    a[i][j+1] = 0;
                }
                else if(x == 1){
                    cout << 1 << ' ' << i << ' ' << j << ' ' << i << ' ' << j << endl;
                    cin >> x;
                    a[i][j] = x;
                    if(x == 0)
                        a[i][j+1] = 1;
                    else
                        a[i][j+1] = 0;
                }
            }
        }
        cout << 2 << endl;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
        ll e;
        cin >> e;
        if(e == -1)
            break;
    }  
    return 0;
}