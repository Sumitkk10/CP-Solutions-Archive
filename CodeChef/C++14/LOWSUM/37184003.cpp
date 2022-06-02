#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n, qq;
		cin >> n >> qq;
		ll a[n], b[n];
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < n; ++i)
			cin >> b[i];
		sort(a, a+n);
		sort(b, b+n);
		priority_queue<ll> q;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(q.size() < 10000) q.push(a[i] + b[j]);
				else if(a[i] + b[j] < q.top()){
					q.pop();
					q.push(a[i] + b[j]);
				}
				else break;
			}
		}
		vector<ll> ans;
		while(!q.empty()){
			ans.push_back(q.top());
			q.pop();
		}
		reverse(ans.begin(), ans.end());
		while(qq--){
			int index; cin >> index;
			cout << ans[index - 1] << "\n";
		}
	}
	return 0;
}
