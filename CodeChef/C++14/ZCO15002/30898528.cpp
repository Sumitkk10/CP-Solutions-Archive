#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
	fast;
	ll n, k;
	cin >> n >> k;
	ll a[n], ans = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a, a + n);
	for(int i = 0; i < n; ++i){
		int low = i + 1;
		int high =  n - 1;
		int x = 0;
		int search = a[i] + k;
		while(low <= high){
			int mid = (low+high)/2;
			if(a[mid] < search){
				low = mid+1;
			}
			else if(a[mid] >= search){
				x = mid;
				high = mid-1;
			}
		}
		if(x > 0)
			ans += n-x;
	}
	cout << ans;
	return 0;
} 