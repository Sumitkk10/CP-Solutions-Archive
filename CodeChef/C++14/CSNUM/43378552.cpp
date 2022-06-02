#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, a[N];

void solve(){
	string s;
	cin >> s;
	int sum = 0;
	for(auto k : s)
		sum += (k - '0');
	cout << (sum % s.size() ? "Try again\n" : "Good Work\n");
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
