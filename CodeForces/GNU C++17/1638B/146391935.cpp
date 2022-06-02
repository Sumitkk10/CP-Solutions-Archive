#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n), odd, even;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] % 2)
			odd.pb(a[i]);
		else
			even.pb(a[i]);
	}
	vector<int> temp = odd, temp1 = even;
	sort(temp.begin(), temp.end());
	sort(temp1.begin(), temp1.end());
	cout << (even == temp1 and odd == temp ? "Yes\n" : "No\n");
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}