#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	int n;
	cin >> n;
	int a[n];
	multiset<int> s;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		s.insert(a[i] + i + 1);
	}
	for(int i = 0; i < n; ++i){
		cout << *s.rbegin() + i << ' ';
		s.erase(s.find(a[n - i - 1] + n - i));
		s.insert(a[n - i - 1] - i);
	}
	return 0;
}
