#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // 1 ----> '('
    // 2 ----> ')'
    // find the maximum depth and first position to occur that.
    int mx = 0, pos = 0, cnt = 0, mx1 = 0, pos1 = 0;
    stack<int> s;
    for(int i = 0; i < n; ++i){
        if(a[i] == 1)
            s.push(a[i]);
        else
            s.pop();
        if(s.size() > mx){
            mx = s.size();
            pos = i + 1;
        }
        if(s.size())
            ++cnt;
        else{
            ++cnt;
            if(cnt > mx1){
                mx1 = cnt;
                pos1 = i + 1 - cnt + 1;
            }
            cnt = 0;
        }
    }
    cout << mx << ' ' << pos << ' ' << mx1 << ' ' << pos1 << '\n';

}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}