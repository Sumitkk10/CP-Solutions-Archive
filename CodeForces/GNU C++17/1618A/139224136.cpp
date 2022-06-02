#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int a[7];
	for(int i = 0; i < 7; ++i)
		cin >> a[i];
	if(a[2] == a[1] + a[0]){
		cout << a[0] << ' ' << a[1] << ' ' << a[3] << '\n';
		return;
	}
	cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
