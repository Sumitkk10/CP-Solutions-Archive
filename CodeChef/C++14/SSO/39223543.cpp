#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
#define pb push_back
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	long long int n;
	cin >> n;
	long long int a[n], sum = 0, orr = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];		
		orr = (orr | a[i]);
		sum += a[i];
		orr = (orr | sum);
	}
	cout << orr << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
