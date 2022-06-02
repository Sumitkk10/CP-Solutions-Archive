#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	int a[n];
	vector<int> odd, even;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] % 2)
			odd.push_back(a[i]);
		else
			even.push_back(a[i]);
	}
	for(auto k : odd)
		cout << k << ' ';
	for(auto k : even)
		cout << k << ' ';
	cout << "\n";	
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
