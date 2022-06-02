#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	long long int n, m;
	cin >> n >> m;
	long long int a[m];
	for(int i = 0; i < m; ++i)
		cin >> a[i];
	if(n == 1){
		cout << "0\n";
		return;
	}
	long long int gcd = a[0];
	for(int i = 1; i < m; ++i)
		gcd = __gcd(gcd, a[i]);
	vector<int> div;
	for(int i = 1; i*i <= gcd; ++i){
		if(gcd % i == 0){
			div.push_back(i);
			if((gcd / i) != i)
				div.push_back(gcd / i);
		}
	}
	sort(div.begin(), div.end());
	int low = 0, high = div.size() - 1;
	ll ans = 1;
	while(low <= high){
		int mid = (low + high) / 2;
		if(div[mid] <= n){
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	// cout << div[ans] << ' ';
	cout << n - div[ans] << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}