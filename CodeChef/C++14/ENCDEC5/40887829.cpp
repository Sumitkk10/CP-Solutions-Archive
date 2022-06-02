#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	long long int a[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		a[i] += (a[i] % 3);
	}
	long long int m;
	cin >> m;
	long long int smaller = LLONG_MAX, greater = LLONG_MIN;
	for(int i = 0; i < n; ++i){
		if(a[i] < m)
			greater = max(greater, a[i]);
		else if(a[i] > m)
			smaller = min(smaller, a[i]);
	}
	if(smaller == LLONG_MAX) smaller = -1;
	if(greater == LLONG_MIN) greater = -1;
	cout << greater << ' ' << smaller << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
