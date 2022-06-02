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
	ll a[n+1];
	multiset<int> s;
	for(int i = 1; i <= n; ++i){ 
		cin >> a[i];
		s.insert(a[i] + i);
	}
	for(int i = 1; i <= n; ++i){
		cout << *s.rbegin() + i - 1;
		cout << " ";
		s.erase(s.find(a[n - i + 1] + n - i + 1));
		s.insert(a[n-i+1] + n - i + 1 - n);
	}
	return 0;
}
