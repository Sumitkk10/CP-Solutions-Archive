#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	string a, b;
	cin >> a >> b;
	map<int, int> mp, mpp;
	for(auto k : a)
		mp[k - 'a']++;
	for(auto k : b)
		mpp[k - 'a']++;
	bool ok = true;
	for(int i = 0; i < 26; ++i){
		if(mp[i] < mpp[i] || (mp[i] -= mpp[i]) % k){
			ok = 0;
			break;
		}
		mp[i + 1] += mp[i];
	}
	cout << (ok ? "Yes\n" : "No\n");
} 

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
