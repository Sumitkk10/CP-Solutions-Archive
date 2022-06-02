#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1e6 + 5;
int a[N];

int find(int x, int y){
    int ans = 0;
    while(y*2 < x){
        y *= 2;
        ++ans;
    }
    return ans;
}

int main() {
	fast;
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    for(int i = 0; i < n; ++i)
	        cin >> a[i];
        int ans = 0;
	    for(int i = 0; i < n - 1; ++i)
            ans += find(max(a[i], a[i + 1]), min(a[i], a[i + 1]));
	    cout << ans << "\n";
	}
	return 0;
}
