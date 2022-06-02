#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
	fast;
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a+0, a+n);
	ll ans = 0, r = 0;
	for(int i = 0; i < n; ++i){
		if(a[i] >= k) break;
		else
			r = i;
	} 
	if(r < 1) 
		cout << 0;
	else{
		for(int i = 0; i <= r; ++i){
			int low = i + 1;
			int high = r;
			int x = -1;
			while(low <= high){
				int mid = (low+high)/2;
				if(a[mid] + a[i] >= k){
					high = mid - 1;
				}
				else if (a[mid] + a[i] < k){
					x = mid;
					low = mid + 1;
				}
			}
			if(x > -1){
				ans += (x - i);
			}
		}
		cout << ans;
	}
	return 0;
} 