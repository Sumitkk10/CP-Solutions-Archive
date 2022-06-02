#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 

ll findlcm(ll arr[], ll n) 
{ 
    ll ans = arr[0]; 
    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
} 

int main(){
	fast;
	ll t = 1;
	cin >> t;
	while(t--){
		ll a[2];
		ll n = 2;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		cout << findlcm(a, n) << "\n";
	}
	return 0;
}
