#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ll long long
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<long long> a(n), b(m);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < m; ++i)
		cin >> b[i];
	vector<long long> lis;
	lis.push_back(a[0]);
    for(int i = 1; i < n; ++i){
        if(a[i] >= lis.back())
            lis.push_back(a[i]);
        else {
            int low = 0, high = lis.size() - 1, ok = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (lis[mid] > a[i]) {
                    ok = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            if (ok != -1)
                lis[ok] = a[i];
        }
    }
    int res = lis.size();
    lis.clear();
    lis.push_back(b[0]);
    for(int i = 1; i < m; ++i){
        if(b[i] >= lis.back())
            lis.push_back(b[i]);
        else {
            int low = 0, high = lis.size() - 1, ok = -1;
            while (low <= high) {	
                int mid = (low + high) / 2;
                if (lis[mid] > b[i]) {
                    ok = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            if (ok != -1)
                lis[ok] = b[i];
        }
    }
    cout << res + lis.size() << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}