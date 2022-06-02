#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		map<ll, ll> hash, hash1, hash2;
		ll a[n], b[n], mn = 1e12;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			hash[a[i]]++;
			hash1[a[i]]++;
			mn = min(mn, a[i]);
		}
		for(int i = 0; i < n; ++i){
			cin >> b[i];
			hash[b[i]]++;
			hash2[b[i]]++;
			mn = min(mn, b[i]);
		}
		sort(a, a+n);
		sort(b, b+n);
		bool fals = false;
		for(auto i : hash){
			if(i.second % 2 != 0){
				fals = true;
				cout << "-1\n";
				break;
			}
		}
		if(fals == true)
			continue;
		vii ans, ans1;
		for(auto i : hash1){
			if(i.second != hash[i.first]/2){
				ll k = i.second - hash[i.first]/2;
				if(k <= 0) continue;
				while(k--)
					ans.push_back(i.first);
			}
		}
		for(auto i : hash2){
			if(i.second != hash[i.first]/2){
				ll k = i.second - hash[i.first]/2;
				if(k <= 0) continue;
				while(k--)
					ans1.push_back(i.first);
			}
		}
		ll sum = 0;
		sort(ans.begin(), ans.end());
		sort(ans1.rbegin(), ans1.rend());
		if(ans.size() != ans1.size()){ 
			cout << "-1\n";
			continue;
		}
		for(int i = 0; i < ans.size(); ++i)
			sum += min(2*mn, min(ans[i], ans1[i]));
		cout << sum << "\n";
	} 
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}