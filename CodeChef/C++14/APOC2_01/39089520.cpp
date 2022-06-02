#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n;
	cin >> n;
	vector<ll> points[n];
	map<int, int> mp, mpp, mppp;
	for(int i = 0; i < n; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		points[i].push_back(a), points[i].push_back(b), points[i].push_back(c);
		sort(points[i].begin(), points[i].end());
		mp[points[i][0]]++;
		mpp[points[i][1]]++;
		mppp[points[i][2]]++;
	}
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		if(mp[points[i][0]] == 1 || mpp[points[i][1]] == 1 || mppp[points[i][2]] == 1)
			++ans;
	}
	cout << ans << "\n";
	return 0;
}
