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
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	stack<int> s, first, second;
	int max_dpt = 0, ct = 0, ans = 0, ans1 = 0;
	for(int i = 0; i < n; ++i){
		if(a[i] == 1){
			if(s.empty() or s.top() == 3)
				++ct;
			s.push(a[i]);
			first.push(i);
		}
		else if(a[i] == 3){
			if(s.empty() or s.top() == 1)
				++ct;
			s.push(a[i]);
			second.push(i);
		}
		else{
			s.pop();
			if(a[i] == 2){
				if(first.size() == 1)
					ans = max(ans, i - first.top() + 1);
				first.pop();
				if(s.empty() or s.top() == 3)
					--ct;
			}
			else{
				if(second.size() == 1)
					ans1 = max(ans1, i - second.top() + 1);
				second.pop();
				if(s.empty() or s.top() == 1)
					--ct;
			}
			ct = max(0, ct);
		}
		max_dpt = max(max_dpt, ct);
	}
	cout << max_dpt << ' ' << ans << ' ' << ans1 << '\n';
	return 0;
}
// ([([](()))])