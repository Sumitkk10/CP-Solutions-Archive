#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
ll MOD = 15746;

int main(){
    fast;
    ll n;
    cin >> n; 
    vector<ll> a(n+1), h(n+1);
    h[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        h[i] = 0;
    }
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        if(h[i] == 1)
            continue;
        else{
            for(int j = i; j <=n;){
                if(h[j] == 1)
                    break;
                h[j] = 1;
                j = a[j];
            }
            ++ans; 
        }
    }
    cout << ans << '\n';
    h[0] = 0;
    for(int i = 1; i <= n; ++i)
        h[i] = 0;
    for(int i = 1; i <= n; ++i){
        if(h[i] == 1)
            continue;
        else{
            for(int j = i; j <=n;){
                cout << j << ' ';
                if(h[j] == 1)
                    break;
                h[j] = 1;
                j = a[j];
            }
            cout << '\n';
        }
    }
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
