#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

long long go(long long x){
	long long ans = 0;
	for(int i = 1; i <= x; i *= 10)
		ans += x/i;
	return ans;
}

void solve(){
	long long a, b;
	cin >> a >> b;
	cout << go(b) - go(a) << '\n';
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
