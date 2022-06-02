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
	int a[n];
	vector<int> pos;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] >= 0)
			pos.push_back(a[i]);
	}
	vector<int> temp = pos;
	sort(temp.begin(), temp.end());
	if(temp != pos){
		cout << "-1\n";
		return;
	}
	for(int i = 0; i < n; ++i){
		if(a[i] > i + 1){
			cout << "-1\n";
			return;
		}
	}
	set<int> s;
	map<int, int> mp;
	for(auto k : pos)
		mp[k]++;
	for(int i = 0; i <= n; ++i)
		if(!mp[i])
			s.insert(i);
	vector<int> ans;
	for(int i = 0; i < n; ++i){
		ans.push_back(*s.begin());
		s.erase(s.begin());
		mp[a[i]]--;
		if(a[i] != -1 and !mp[a[i]])
			s.insert(a[i]);
	}
	for(auto k : ans)
		cout << k << ' ';
	cout << '\n'; 
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}