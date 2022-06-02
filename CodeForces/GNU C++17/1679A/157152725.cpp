#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;

void solve(){
	long long n;
	cin >> n;
	if(n % 2 != 0 or (n == 2)){
		cout << "-1\n";
		return;
	}
	if(n % 6 == 0)
		cout << n / 6 << ' ';
	else
		cout << n / 6 + 1 << ' ';
	cout << n / 4 << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}