#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
 
int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, m, k, b = 0, q = 0;
        cin >> n >> m >> k;
        ll C[n][k];
        for(ll i = 0; i < n; ++i){
            for(ll j = 0; j < k; ++j)
                cin >> C[i][j];
        }
        for(ll i = 0; i < n; ++i){
            q = 0;
            for(ll j = 1; j < k; ++j){
                if(C[i][0] != C[i][j]){
                    cout << C[i][j] << ' ';
                    break;
                }
                else if(C[i][0] == C[i][j]){
                    q++;
                }
            }
            if(q == (k-1)){
                cout << C[i][0] << ' ';
                b++;
            }
        }
        cout << '\n';
    }
    return 0;
}