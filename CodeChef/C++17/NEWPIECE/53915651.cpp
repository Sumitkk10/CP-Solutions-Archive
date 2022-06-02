#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int a, b, p, q;
	cin >> a >> b >> p >> q;
	if(a == p and b == q){
		cout << "0\n";
		return;
	}
	if(((a + b) % 2) == ((p + q) % 2))
		cout << "2\n";
	else
		cout << "1\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}