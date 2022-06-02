#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool calc(int i, int n, pair<int, int> a[], int pre){
	if(i >= n)
		return true;
	for(int j = i; j < n; ++j){
		if(a[j].first <= pre)
			return false;
		pre = a[j].second;
	}
	return true;
}

void solve(){
	int len, n, k;
	cin >> len >> n >> k;
	pair<int, int> a[n], b[n + 2];
	b[0].first = b[0].second = 1;
	for(int i = 0; i < n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	for(int i = 0; i < n; ++i){
		b[i + 1].first = a[i].first;
		b[i + 1].second = a[i].second;
	}
	b[n + 1].first = b[n + 1].second = len; 
	int largest = 0;
	for(int i = 1; i < n + 2; ++i){
		int length = b[i].first - b[i - 1].second;
		largest = max(largest, length);
	}
	bool ok = 0;
	int pre = a[0].second;
	for(int i = 1; i < n; ++i){
		if(a[i].first <= pre){
			if(ok == 1 or k == 0){
				cout << "Bad\n";
				return;
			}
			ok = 1;
			if(calc(i + 1, n, a, a[i].second) and (pre - a[i - 1].first + 1) <= largest){
				cout << "Good\n";
				return;
			}
			if(calc(i + 1, n, a, a[i - 1].second) and (a[i].second - a[i].first + 1) <= largest){
				cout << "Good\n";
				return;
			}
			cout << "Bad\n";
			return;
		}
		pre = a[i].second;
	}
	cout << "Good\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
