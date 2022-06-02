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
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	if(n == 1 and a[0] % 2){
		cout << "-1\n";
		return;
	}
	vector<int> ans;
	for(int i = 0; i < n; ++i){
		if(a[i] % 2 == 0){
			ans.push_back(i);
			break;
		}
	}
	if(ans.size()){
		cout << "1\n";
		for(auto k : ans)
			cout << k + 1 << '\n';
		return;
	}
	cout << "2\n" << "1 2\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t; 
	while(t--)
		solve();
	return 0;
}
