#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	long long n;
	cin >> n;
	long long odd = (n + 1)/2;
	long long even = n - odd, an = (n % 2 == 0 ? n - 1 : n);
	long long sum_odd = (odd * (1 + an)) / 2;
	an = (n % 2 == 0 ? n : n - 1);
	long long sum_even = (even * (2 + an)) / 2;
	cout << sum_even - sum_odd << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}