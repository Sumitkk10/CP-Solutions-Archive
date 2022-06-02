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
        ll n, m;
        cin >> n >> m;
        ld a[m][n], average[n] = {0}, avr = 0, ans = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                cin >> a[i][j];
            }
        }
        for(int i = 0; i < m; ++i){
            int d = 0;
            for(int j = 0; j < n; ++j)
                d += a[i][j];
            avr = d/n;
            for(int j = 0; j < n; ++j){
                if(a[i][j] > avr && average[j] == 0){
                    average[j] = 1;
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
