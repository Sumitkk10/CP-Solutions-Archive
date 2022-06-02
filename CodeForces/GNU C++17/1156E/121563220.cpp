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
    int a[n + 1];
    map<int, int> mp;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        mp[a[i]] = i;
    }
    stack<int> st;
    int pre_greater[n + 1], nxt_greater[n + 1];
    for(int i = 1; i <= n; ++i){
        while(!st.empty() and a[st.top()] < a[i]){
            nxt_greater[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        nxt_greater[st.top()] = n + 1;
        st.pop();
    }
    for(int i = n; i >= 1; --i){
        while(!st.empty() and a[st.top()] < a[i]){
            pre_greater[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        pre_greater[st.top()] = 0;
        st.pop();
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){

        // currently this is what i want lp + lr to be.
        
        int lft = pre_greater[i] + 1, right = nxt_greater[i] - 1;
        if(abs(i - lft) <= abs(i - right)){
            for(int j = lft; j < i; ++j)
                if(mp[a[i] - a[j]] > i and mp[a[i] - a[j]] <= right) ++ans;
        }
        else{
            for(int j = i + 1; j <= right; ++j)
                if(mp[a[i] - a[j]] < i and mp[a[i] - a[j]] >= lft) ++ans;
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
