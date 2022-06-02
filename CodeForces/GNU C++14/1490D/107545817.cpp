#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1e6 + 5;
int ans[N], a[N];

void go(int l, int r, int h){
    if(r < l)
        return;
    int mx = 0, ind = 0;
    for(int i = l; i <= r; ++i){
        if(a[i] > mx){
            mx = a[i];
            ind = i;
        }
    }
    ans[ind] = h;
    go(l, ind - 1, h + 1);
    go(ind + 1, r, h + 1);
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
	    go(0, n - 1, 0);
	    for(int i = 0; i < n; ++i)
	        cout << ans[i] << ' ';
        cout << "\n";
	}
	return 0;
}
