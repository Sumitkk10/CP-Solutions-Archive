#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define int long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;
int n, a[N];

void solve(){
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	// if odd number of elements never possible
	// if freq of any element > n/2 then not possible
	if(n % 2){
		cout << "NO\n";
		return;
	}
	sort(a, a + n);
	for(int i = 0; i < n/2; ++i){
		if(a[i] == a[i + n/2]){
			cout << "NO\n";
			return;
		}
		if(i > 0 and a[i] == a[i + n/2 - 1]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for(int i = 0; i < n/2; ++i)
		cout << a[i] << ' ' << a[i + n/2] << ' ';
	cout << '\n';
}

int32_t main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}