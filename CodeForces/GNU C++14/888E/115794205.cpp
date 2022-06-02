#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, m;
    
    cin >> n >> m;

    int a[n];

    vector<int> l, r;

    for(int i = 0; i < n; ++i){
        
        cin >> a[i];

        if(i < n/2)
            l.push_back(a[i]);
        else
            r.push_back(a[i]);
    
    }
    
    vector<long long int> subset_left, subset_right;

    for(int i = 0; i < (1LL << l.size()); ++i){
        long long sum = 0;
        for(int j = 0; j < l.size(); ++j){
            if(i & (1LL << j))
                sum += l[j];
        }
        subset_left.push_back(sum % m);
    }

    for(int i = 0; i < (1LL << r.size()); ++i){
        long long sum = 0;
        for(int j = 0; j < r.size(); ++j){
            if(i & (1LL << j))
                sum += r[j];
        }
        subset_right.push_back(sum % m);
    }

    long long int ans = 0;
    sort(subset_right.begin(), subset_right.end());
    for(int i = 0; i < subset_left.size(); ++i){
        int rem = m - subset_left[i];
        int low = 0, high = subset_right.size() - 1, ok = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(subset_right[mid] < rem){
                ok = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if(ok != -1)
            ans = max(ans, (subset_left[i] + subset_right[ok]) % m);
        ans = max(ans, (subset_left[i] + subset_right[subset_right.size() - 1]) % m);
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
