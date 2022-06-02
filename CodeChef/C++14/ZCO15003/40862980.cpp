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
		int x, y;
		cin >> x >> y;
		a[i].second = x, a[i].first = y;
	}
	sort(a, a + n);
	int ans = 1, pre = a[0].first;
	for(int i = 1; i < n; ++i){
		if(a[i].second > pre){
			++ans;
			pre = a[i].first;
		}
	}
	cout << ans << '\n';
	return 0;
}
// 5 8 10 13 15 17 20