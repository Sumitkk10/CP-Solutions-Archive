#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 5e5 + 5, MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	deque<int> d;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		d.push_back(x);
	}
	int moves = 0, sum_a = 0, sum_b = 0, pre = 0, chance = 0;
	while(!d.empty()){
		int cur = 0;
		while(!d.empty()){
			if(cur > pre) break;
			if(chance % 2 == 0){
				int x = d.front();
				cur += x;
				d.pop_front();
			}
			else{
				int x = d.back();
				cur += x;
				d.pop_back();
			}
		}
		if(chance % 2) sum_b += cur;
		else
			sum_a += cur;
		++moves;
		++chance;
		pre = cur;
	}
	cout << moves << ' ' << sum_a << ' ' << sum_b << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}