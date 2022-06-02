#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long int n, a[N];

void solve(){
    cin >> n;
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
       	if(a[i] >= 0) ++ans;
    }
    long long sum = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 1; i <= n; ++i){
    	if(a[i] >= 0){
    		sum += a[i];
    		continue;
    	}
    	else{
    		sum += a[i];
    		pq.push(a[i]);
    		if(sum < 0){
    			sum -= pq.top();
    			pq.pop();
    		}
    	}
    }
    cout << ans + pq.size() << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}