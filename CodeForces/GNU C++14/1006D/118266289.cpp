#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
	int n, ans = 0;
	cin >> n;
	string a, b;
	cin >> a >> b;
	for(int i = n - 1; i >= (n / 2); --i){
		if(i == (max(0, n - i - 1))){
			if(a[i] == b[i]) continue;
			++ans;
		}
		else if(a[i] != b[i]){
			if((b[max(0, n - i - 1)] == a[i]) and (a[max(0, n - i - 1)] == b[i])){ 
				swap(a[i], a[max(0, n - i - 1)]);
				continue;
			}
			else if(a[max(0, n - i - 1)] == a[i] and b[max(0, n - i - 1)] == b[i]){
				swap(a[max(0, n - i - 1)], b[max(0, n - i - 1)]);
				swap(a[max(0, n - i - 1)], a[i]);
				continue;
			}
			else if(b[max(0, n - i - 1)] == b[i]){
				swap(a[max(0, n - i - 1)], b[max(0, n - i - 1)]);
				swap(a[max(0, n - i - 1)], a[i]);
				continue;
			}
			else if(a[i] == b[max(0, n - i - 1)]){
				swap(b[max(0, n - i - 1)], b[i]);
				continue;
			}
			else if(a[max(0, n - i - 1)] == b[i]){
				swap(b[max(0, n - i - 1)], b[i]);
				++ans;
				continue;
			}
			else{
				a[i] = b[i];
				++ans;
			}
		}
		else if(a[i] != b[i]){
			a[i] = b[i];
			++ans;
		}
	}
	for(int i = 0; i < n/2; ++i)
		if(a[i] != b[i])
			++ans;
	cout << ans << '\n';
}
 
int main() {
	fast;
	int t = 1;
 	// cin >> t;
	while(t--)
		solve();
	return 0;
}