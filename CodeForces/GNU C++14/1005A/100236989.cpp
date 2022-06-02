#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<int> ans;

int main(){
	fast;
	ll n, x, prev;
   cin >> n;
   cin >> x;
   prev = x;
   for(int i = 1; i < n; i++){
      cin >> x;
      if(x <= prev){
         ans.push_back(prev);
      }
      prev = x;
   }
   ans.push_back(prev);
   cout << (int)ans.size() << "\n";
   for(auto i : ans)
      cout << i << " ";
	return 0;
}
