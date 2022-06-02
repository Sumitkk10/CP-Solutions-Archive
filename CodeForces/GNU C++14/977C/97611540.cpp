#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e8;

void solve(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	if(k == 0){
		if(a[0] > 1) cout << "1\n";
		else cout << "-1\n";
	}
	else if(a[k - 1] == a[k] && k != n || a[k - 1] == 0) cout << "-1\n";
	else cout << a[k - 1] << '\n';
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
