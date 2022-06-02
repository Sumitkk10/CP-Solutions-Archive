/*
When I get older
I will be stronger
They'll call me freedom
Just like a wavin' flag
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long x;

/*
find the greatest n such that
n*(n + 1) / 2 is < x
final answer --> 2*n + 2
*/

bool check(long long mid){
	if((mid * (mid + 1)) / 2 < x)
		return true;
	return false;
}

void solve(){
	cin >> x;
	long long low = 0, high = 1e5, n;
	while(low <= high){
		long long mid = (low + (high - low) / 2);
		if(check(mid)){
			n = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << 2*n + 2 << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}