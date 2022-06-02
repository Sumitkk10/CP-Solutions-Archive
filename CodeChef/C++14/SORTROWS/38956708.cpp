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
	string s, a[n];
	getline(cin, s);
	for(int i = 0; i < n; ++i){
		getline(cin, s);
		s.pop_back();
		s.pop_back();
		s.pop_back();
		a[i] = s;
	}
	sort(a, a + n);
	for(auto k : a)
		cout << k << "\n";
	return 0;
}
