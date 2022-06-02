#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 501;
const int MOD = 1e9 + 7;
int n, x, a[N];

bool not_sorted(int x){
	for(int i = 1; i < n; ++i)
		if(a[i] < a[i - 1])
			return true;
	return false;
}

void solve(){
	cin >> n >> x;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 0;
	while(not_sorted(x)){
		ans++;
		int i = 0;
		while(i < n and a[i] <= x)
			++i;
		if(i == n){
			cout << "-1\n";
			return;
		}
		swap(a[i], x);
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
