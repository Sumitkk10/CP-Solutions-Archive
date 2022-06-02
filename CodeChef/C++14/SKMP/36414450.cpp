#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        string s, ss;
        cin >> s >> ss;
        map<char, int> mp, mpp;
		for(int i = 0; i < s.size();++i){
			mp[s[i]]++;
			mpp[s[i]]++;
		}
      	for(int i = 0; i < ss.size(); ++i){
          	mp[ss[i]]--;
          	mpp[ss[i]]--;
        } 
      	string ans, ans1;
      	for(int i = 0; i <= ss[0] - 'a' ; ++i){
          	while(mp[i + 'a'] > 0){
              	ans.pb(i+'a');
              	mp[i + 'a']--;
            }
        } 
      	ans += ss;
      	for(int i = 0; i < 26; ++i){
          	while(mp[i + 'a'] > 0){
              	ans.pb(i+'a');
              	mp[i + 'a']--;
            }
        } 
      	for(int i = 0; i < ss[0] - 'a' ; ++i){
          	while(mpp[i + 'a'] > 0){
              	ans1.pb(i+'a');
              	mpp[i + 'a']--;
            }
        } 
      	ans1 += ss;
      	for(int i = 0; i < 26; ++i){
          	while(mpp[i + 'a'] > 0){
              	ans1.pb(i+'a');
              	mpp[i + 'a']--;
            }
        } 
      	cout << min(ans, ans1) << "\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}