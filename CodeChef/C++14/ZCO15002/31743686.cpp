#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
 
int main(){
    fast;
    ll n, k;
    cin >> n >> k;
    ll a[n], ans = 0;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n);
    int j = 0;
    for(int i = 1; i < n; ++i){
        if(abs(a[j]-a[i]) >= k){
            ans++;
            ans += n-(i+1);
            j++;
            i = j;
        }
        else if(i == n-1){
            j++;
            i = j;
        }
    }
    cout << ans;
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#