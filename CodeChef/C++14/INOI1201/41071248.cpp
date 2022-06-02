#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	int n;
	cin >> n;
	pair<int, int> a[n];
	for(int i = 0; i < n; ++i){
		int x, y, z;
		cin >> x >> y >> z;
		a[i].second = x;
		a[i].first = y + z;
	}
	sort(a, a + n, greater<pair<int, int > >());
	long long int sum = 0, ans = 0;
	for(int i = 0; i < n; ++i){
		ans = max(ans, sum + a[i].first + a[i].second);
		sum += a[i].second;
	}
	cout << ans << '\n';
	return 0;
}
