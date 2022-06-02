#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	string a, b;
	cin >> a >> b;
	map<char, int> mp, mpp;
	for(auto k : a)
		mp[k]++;
	for(auto k : b)
		mpp[k]++;
	for(auto k : mpp){		
		if(!mp[k.first]){
			cout << "-1\n";
			return;
		}
	}
	vector<int> pos[27];
	for(int i = 0; i < a.size(); ++i)
		pos[a[i] - 'a'].push_back(i);
	int ans = 0;
	for(int i = 0; i < b.size(); ++i){
		int pre = pos[b[i] - 'a'][0];
		++ans;
		while(i < b.size()){
			++i;
			if(i >= b.size())
				break;
			int low = 0, high = pos[b[i] - 'a'].size() - 1, poss = -1;
			while(low <= high){
				int mid = (low + high) / 2;
				if(pos[b[i] - 'a'][mid] > pre){
					poss = pos[b[i] - 'a'][mid];
					high = mid - 1; 
				}
				else 
					low = mid + 1;
			}
			if(poss == -1){
				--i;
				// cout << i << ' '; 
				break;
			}
			else
				pre = poss;
		}
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
