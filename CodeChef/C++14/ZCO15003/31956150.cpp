#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n, c = 0;
    cin >> n;
    pair<ll, ll> a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a+n);
    ll ans = 1;
    ll b = 0;
    for(int i = 1; i < n; ++i){
        for(int j = b; j < i; ++j){
            if(a[i].first > a[j].second){
                ++c;
                ans++;
                break;
            }
        }
        if(c > 0)
            b = i;
        c = 0;
    }
    cout << ans;
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
