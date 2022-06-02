#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define int long long
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;

string binary(int x){
	string ans;
	if(x == 0){
		ans.pb('0');
		return ans;
	}
	while(x > 0){
		ans.pb((x % 2 == 1 ? '1' : '0'));
		x /= 2;
	}
	return ans;
}

int convert(string s){
	int ans = 0, j = 0;
	for(int i = s.size() - 1; i >= 0; --i){
		if(s[i] == '1')
			ans += (1ll << j);
		++j;
	}
	return ans;
}

void solve(){
	int n;
	cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int mp[35] = {0};
	map<int, int> cnt;
	for(int i = 0; i < n; ++i){
		cin >> b[i];
		cnt[b[i]]++;
		string s = binary(b[i]);
		while(s.size() < 35)
			s.pb('0');
		reverse(s.begin(), s.end());
		for(int i = 0; i < s.size(); ++i)
			if(s[i] == '1')
				mp[i]++;
	}
	string res;
	for(int i = 0; i < 35; ++i)
		res.pb('0');
	for(int i = 0; i < 35; ++i)
		if(mp[i] == n)
			res[i] = '1';
	reverse(res.begin(), res.end());
	while(!res.empty() and res.back() == '0') res.pop_back();
	if(res.empty()) res.pb('0');
	reverse(res.begin(), res.end());
	int x = convert(res);
	for(int i = 0; i < n; ++i){
		if(!cnt[a[i] | x]){
			cout << "-1\n";
			return;
		}
		cnt[a[i] | x]--;
	}
	cout << x << '\n';
}

int32_t main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}