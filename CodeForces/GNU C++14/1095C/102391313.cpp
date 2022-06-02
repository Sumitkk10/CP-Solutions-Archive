#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	long long int n, k;
	cin >> n >> k;
	map<int, int> mp;
	queue<int> q;
	for(int i = 0; i <= 30; ++i){
		if(n & (1 << i)){
			if(i > 0) q.push(1 << i);
			mp[1 << i]++;
		}
	}
	int cnt = mp.size();
	if(cnt > k){
		cout << "NO\n";
		return 0;
	}
	while(cnt < k and !q.empty()){
		int x = q.front();
		q.pop();
		mp[x]--;
		mp[x / 2] += 2;
		if(x / 2 > 1){
			q.push(x / 2);
			q.push(x / 2);
		}
		++cnt;
	}
	if(cnt < k){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for(auto k : mp)
		while(k.second--)
			cout << k.first << ' ';
	return 0;
}
