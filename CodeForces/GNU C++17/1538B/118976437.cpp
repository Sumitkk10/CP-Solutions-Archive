#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
	int n;
	cin >> n;
	int a[n], sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		sum += a[i];
	}
	if(sum % n != 0){
		cout << "-1\n";
		return;
	}
	int req = sum / n, ans = 0;
	for(int i = 0; i < n; ++i)
		if(a[i] > req)
			++ans;
	cout << ans << '\n';
}
 
int main() {
	fast;
	int t = 1;
 	cin >> t;
	while(t--)
		solve();
	return 0;
}