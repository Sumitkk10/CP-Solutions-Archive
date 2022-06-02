#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int n;

void solve(){
	cin >> n;
	cout << (n % 2 == 0 ? "2021\n" : "2022\n");
}
 
int main() {
	fast;
	int t = 1;
 	cin >> t;
	while(t--)
		solve();
	return 0;
}   