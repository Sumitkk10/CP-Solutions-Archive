#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n], b[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n; ++i)
            cin >> b[i];
        ll sum = 0, sum1 = 0, ans = 0;
        sum += a[0];
        sum1 += b[0];
        if(sum == sum1){
            ans += sum;
            if(a[1] == b[1])
                ans += a[1];
        }
        for(int i = 1; i < n-1; ++i){
            sum += a[i];
            sum1 += b[i];
            if(sum == sum1 && a[i+1] == b[i+1])
                ans += a[i+1];
        }
        cout << ans << '\n';
    }
    return 0;
}