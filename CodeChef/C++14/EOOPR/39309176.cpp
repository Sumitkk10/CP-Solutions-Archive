#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	long long int a, b;
	cin >> a >> b;
	if(a < b){
		long long int diff = abs(b - a);
		if(diff % 2) cout << "1\n";
		else{
			if(abs(a - b)/2 % 2 == 1) cout << "2\n";
			else cout << "3\n";
		}
	}
	else if(b < a){
		long long int diff = abs(a - b);
		cout << (diff % 2 ? "2\n" : "1\n");
	}
	else
		cout << "0\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

