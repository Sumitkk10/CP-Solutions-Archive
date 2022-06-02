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
	string s;
	cin >> s;
	int zero = 0, one = 0;
	for(auto k : s){
		zero += (k == '0');
		one += (k == '1');
	}
	if(zero > one)
		swap(zero, one);
	if(zero == one){
		cout << zero * 2 << '\n';
		return;
	}
	cout << zero * 2 + 1 << '\n'; 
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}