#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	long long int n;
	cin >> n;
	if((n & (n - 1)) == 0){
		cout << "-1\n";
		return;
	}
	if(n % 2 == 1){
		cout << 2 << '\n';
		return;
	}
	if(n % 3 == 0){
		cout << 3 << '\n';
		return;
	}
	long long x = 2, nn = n;
	while(nn > 1){
		if(nn % x == 0)
			nn /= x;
		else
			break;
	}
	x = nn;
	long long y = n / x;
	if(y > x/2){
		cout << x << '\n';
		return;
	}
	if(y == x/2){
		cout << x - 1 << '\n';
		return;
	}
	cout << x - (x/2 - y)*2 - 1 << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}