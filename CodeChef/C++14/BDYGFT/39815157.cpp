#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 2e4 + 5;
const int MOD = 1e9 + 7;

bool ans(int a[], int n){
	int l = 0, r = n - 1;
	while(l < r){
		if(a[l] + a[r] == 2000)
			return true;
		if(a[l] + a[r] < 2000)
			++l;
		else
			--r;
	}
	return false;
}

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	cout << (ans(a, n) ? "Accepted\n" : "Rejected\n");
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
