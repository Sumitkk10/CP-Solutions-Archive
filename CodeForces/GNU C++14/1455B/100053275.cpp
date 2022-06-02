#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 3e6 + 1;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	long long int sum = 0, idx = 1;
	while(sum < n)
		sum += idx++;
	if(sum == n + 1)
		cout << idx << '\n';
	else
		cout << idx - 1 << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
