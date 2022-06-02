#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll n, a[N];

bool check(vector<int> v){
	deque<int> ans, ans1;
	int i = 0, j = v.size() - 1;
	while(i <= j){
		if(i == j){
			ans.push_front(v[j]);
			ans1.push_back(v[j]);
			break;
		}
		if(v[i] < v[j]){
			ans.push_front(v[i]);
			ans1.push_front(v[i]);
			++i;
		}
		else{
			ans.push_back(v[j]);
			ans1.push_back(v[j]);
			--j;
		}
	}
	bool ok = 1, okk = 1;
	int cur = 1;
	for(auto k : ans){
		if(k != a[cur])
			ok = 0;
		++cur;
	}
	cur = 1;
	for(auto k : ans1){
		if(k != a[cur])
			okk = 0;
		++cur;
	}
	if(ok or okk) return true;
	return false;
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	vector<int> v;
	for(int i = n/2; i >= 1; --i)
		v.push_back(a[i]);
	for(int i = n; i > n/2; --i)
		v.push_back(a[i]);
	if(check(v)){
		for(auto k : v)
			cout << k << ' ';
		cout << '\n';
		return;
	}
	cout << "-1\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}