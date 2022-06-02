#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	long long int a, b;
	cin >> a >> b;
	if(a == 0){
		cout << "1\n";
		return;
	}
	long long x = 2 * b + a;
	cout << x + 1 << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}