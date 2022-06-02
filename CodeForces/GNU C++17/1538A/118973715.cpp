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
	int a[n], idx, idx1, mx = 0, mn = INT_MAX;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] < mn){
			mn = a[i];
			idx = i + 1;
		}
		if(a[i] > mx){
			mx = a[i];
			idx1 = i + 1;
		}
	}
	if(idx < idx1)
		cout << min({idx + (n - idx1 + 1), idx1, (n - idx + 1)}) << '\n';
	else{
		cout << min({idx1 + (n - idx + 1), idx, (n - idx1 + 1)}) << '\n';
	}
}
 
int main() {
	fast;
	int t = 1;
 	cin >> t;
	while(t--)
		solve();
	return 0;
}