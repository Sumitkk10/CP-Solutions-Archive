/*
When I get older
I will be stronger
They'll call me freedom
Just like a wavin' flag
*/
// saarangorz
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
long long n, k, a[N][N], med;
vector<ll> v;

bool check(ll mid){
	long long j;
	for(j = 0; j < v.size(); ++j){
		if(v[j] >= mid) break;
	}
	long long cur = (v.size() - j);
	if(cur < n * med)
		return false;
	// return true (for k == 1e14)
	// now we need to find the min cost to make the matrix and if it is < k then good.
	// how to find min cost ??
	long long cost = 0, medd = n/2, okk = 0;
	// if(mid == 6) cout << j << ' ';
	if(medd >= j){
    	for(int i = medd; i < v.size(); i += (medd + 1)){
    	    if(okk == n) break;
    		cost += v[i];
    	    ++okk;
    	}
	}
	else{
	    int i = j, diff = max(0ll, j - medd);
	    // if(mid == 6) cout << diff << ' ';
        
        while(i < v.size()){
            if(okk == n) break;
            cost += v[i];
            // if(mid == 6) cout << v[i] << ' ';
            ++okk;
            if(diff > 0){
                if(diff >= medd){
                    ++i;
                    diff -= medd;
                    continue;
                }
                i += (medd + 1 - diff);
                diff = 0;
                continue;
            }
            i += (medd + 1);
        }	    
	}
	return (okk >= n and cost <= k);
}

void solve(){
	cin >> n >> k;
	v.clear();
	med = (n + 1 - (n % 2 == 0 ? (n/2) + 1 : (n + 1)/2));
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> a[i][j];
			v.push_back(a[i][j]);
		}
	}
	sort(v.begin(), v.end());
	long long low = 0, high = 1e9, ans = -1;
	while(low <= high){
		ll mid = (low + high) / 2;
		if(check(mid)){
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}