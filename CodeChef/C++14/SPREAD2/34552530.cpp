#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 205;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        ll ans = 0, sum = 0, k = 0, l = a[0];
        while(true){
        	k = sum;
        	sum += l;
        	++ans;
        	if(sum >= n-1)
            	break;
            for(int i = k+1; i <= sum; ++i)
                l += a[i];	
        }
        cout << ans << endl;
    }
    return 0;
}