#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	ll n;
	cin >> n;
	ll div = 1;
	bool ok = true;
	while(n > 0){
		if(n % div != 0){
			ok = false;
			cout << "No\n";
			break;
		}
		n /= 10;
		++div;
	}
	if(ok) cout << "Yes\n";
	return 0;
}