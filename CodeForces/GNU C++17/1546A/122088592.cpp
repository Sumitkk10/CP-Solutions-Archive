#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 42373;

void solve(){
	int n;
	cin >> n;
	int a[n + 1], tar[n + 1];
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		cin >> tar[i];
	vector<int> increase, decrease;
	for(int i = 1; i <= n; ++i){
		if(a[i] > tar[i]){
			int x = a[i] - tar[i];
			while(x--)
				decrease.push_back(i);
		}
		else if(a[i] < tar[i]){
			int x = tar[i] - a[i];
			while(x--)
				increase.push_back(i);
		}
	}
	if(increase.size() != decrease.size()){
		cout << "-1\n";
		return;
	}
	cout << increase.size() << '\n';
	for(int i = 0; i < increase.size(); ++i)
		cout << decrease[i] << ' ' << increase[i] << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}