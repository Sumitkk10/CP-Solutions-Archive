#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
ll MOD = 15746;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, k, c = 0, ans = 0;
        cin >> n >> k;
        char a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = n-1; i >= (n-k); --i){
            if(a[i] == 'H'){
                for(int j = 0; j < i; ++j){
                    if(a[j] == 'H')
                        a[j] = 'T';
                    else
                        a[j] = 'H';
                }
            }
        }
        for(int j = 0; j < n-k; ++j){
            if(a[j] == 'H')
                ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
