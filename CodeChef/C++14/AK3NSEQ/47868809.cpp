#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    long long a[3*n + 1];
    for(int i = 1; i <= 3*n; ++i)
        cin >> a[i];
    long long min_suf[3*n + 1], sum = 0;
    priority_queue<int> pq;
    for(int i = 3*n; i >= 1; --i){
        if(pq.size() >= n){
            if(a[i] < pq.top()){
                sum -= pq.top();
                pq.pop();
                sum += a[i];
                pq.push(a[i]);
            }
        }
        else{
            sum += a[i];
            pq.push(a[i]);
        }
        min_suf[i] = sum;
    }
    sum = 0;
    long long ans = LLONG_MIN;
    priority_queue<int, vector<int>, greater<int> > pq1;
    for(int i = 1; i <= 2*n; ++i){
        if(pq1.size() >= n){
            if(a[i] >= pq1.top()){
                sum -= pq1.top();
                sum += a[i];
                pq1.pop();
                pq1.push(a[i]);
            }
            ans = max(ans, sum - min_suf[i + 1]);
        }
        else{
            sum += a[i];
            pq1.push(a[i]);
        }
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
