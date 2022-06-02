#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, a[N];

int is_present(int i, int tar){
	if(i >= n)
		return -1;
	int low = i, high = n - 1;
	while(low <= high){
		int mid = (low + high) / 2;
		if(a[mid] == tar)
			return mid;
		if(a[mid] > tar)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int main(){
	fast;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			int cnt = 2, k = j;
			int diff = a[j] - a[i];
			while(is_present(k + 1, a[i] + (cnt * diff)) != -1){
				k = is_present(k + 1, a[i] + (cnt * diff));
				++cnt;
			}
			ans = max(ans, cnt);
		}
	}
	cout << ans << '\n';
	return 0;
}