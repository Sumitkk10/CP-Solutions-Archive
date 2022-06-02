#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n;
    cin >> n;
    ll a[n], sum = 0, ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    sort(a+0, a+n);
    for(int i = 0; i < n-1; ++i){
        sum -= a[i];
        ans += sum - ((n-(i+1))*a[i]);
    }
    cout << ans; 
    return 0;
}