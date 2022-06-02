#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 2e5 + 3;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
    	ll n;
    	cin >> n;
    	ll a[n], hash[N] = {0}, mx = 0;
    	for(int i = 0; i < n; ++i){
    		cin >> a[i];
    		hash[a[i]]++;
    		mx = max(mx, a[i]);
    	}
    	ll cnt = 0, cnt1 = 0, j = 0;
    	for(int i = 0; i < N; ++i){
    		if(hash[i] > 1)
    			++cnt;
    		if(hash[i] == 1 && i == mx)
    			++cnt1;
    		if(hash[i] > 2)
    			++j;
    	}
    	if(cnt == 0){
    		sort(a, a+n);
    		cout << "YES\n";
    		for(int i = 0; i < n; ++i)
    			cout << a[i] << " ";
    		cout << '\n';
    	}
    	else if(cnt1 == 0 || j > 0)
    		cout << "NO\n";
    	else{
    		cout << "YES\n";
    		vii ans;
    		sort(a, a+n);
    		for(int i = 0; i < n; ++i){
    			if(ans.empty() == true){
    				ans.pb(a[i]);
    				continue;
    			}
    			if(a[i] != ans.back())
    				ans.pb(a[i]);
    		}
    		for(int i = 0; i < ans.size(); ++i)
    			cout << ans[i] << " ";
    		int u = ans.size();
    		for(int i = 0; i < N; ++i){
    			if(hash[i] > 1)
    				ans.pb(i);
    		}
       		for(int i = ans.size() - 1; i >= u; --i)
    			cout << ans[i] << " ";
    		cout << '\n';
    	}
    }
    return 0;
}