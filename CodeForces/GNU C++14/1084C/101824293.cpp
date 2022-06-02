#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
    fast;
    string s;
    cin >> s;
    string ans;
    for(auto k : s)
        if(k == 'a' or k == 'b')
            ans.push_back(k);
    long long int ans1 = 1;
    for(int i = 0; i < ans.size(); ++i){
        int siz = 0;
        while(ans[i] == 'a' and i < ans.size()){
            ++siz;
            ++i;
        }
        ++siz;
        ans1 = (ans1 * siz) % MOD;
    }
    cout << ans1 - 1 << '\n';
    return 0;
}
