#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e5 + 3;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
    	ll n, k;
    	cin >> n >> k;
    	ll a[n], hash[N] = {0};
    	for(int i = 0; i < n; ++i)
    		cin >> a[i];
    	ll cnt = 0, left = 0, right = 0, mx = 0;
    	while(right < n){
    		hash[a[right]]++;
    		if(hash[a[right]] == 1) cnt++;
    		while(cnt == k){
    			hash[a[left]]--;
    			if(hash[a[left]] == 0) cnt--;
    			left++;
    		}
    		mx = max(mx, right - left + 1);
    		right++;
    	}
    	cout << mx << endl;
    }
    return 0;
}