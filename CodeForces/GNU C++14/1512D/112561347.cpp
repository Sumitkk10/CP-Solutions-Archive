#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long 
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	long long int a[n + 2];
	long long sum = 0; 
	for(int i = 0; i < n + 2; ++i){
		cin >> a[i];
		sum += a[i];
	}
	vector<pair<long long, int> > v;
	for(int i = 0; i < n + 2; ++i)
		v.push_back({a[i], i});
	sort(v.begin(), v.end());
	for(int i = 0; i < n + 2; ++i){
		int low = 0, high = n + 1;
		long long constant = sum - a[i];
		while(low <= high){
			int mid = (low + high) / 2;
			if(v[mid].second == i){
				low = low + 1;
				continue;
			}
			if(constant - v[mid].first == a[i]){
				for(int j = 0; j < n + 2; ++j){
					if(j == i or j == v[mid].second) continue;
						cout << a[j] << ' ';
				}
				cout << "\n";
				return;
			}
			else if(constant - v[mid].first > a[i])
				low = mid + 1;
			else
				high = mid - 1;
		}
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