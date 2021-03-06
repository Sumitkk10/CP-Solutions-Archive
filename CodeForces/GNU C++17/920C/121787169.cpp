#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
const int N = 1e6 + 10;
const ll inf = 1e18;
const int mod = 1e9 + 7;
 
ll a[N];
ll dp[N];
int main(){
  fast;
  ll n;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  string s;
  cin >> s;
  s = '#' + s + '0';
    dp[n + 1] = n;
  for(int i = (int)s.size() - 1; i >= 1; i--){
    if(s[i] == '0')
      dp[i] = i;
    else
      dp[i] = dp[i + 1];
  }
  for(int i = 1; i < (int)s.size(); i++){
    if(s[i] == '1'){
      for(int j = i; j <= dp[i]; j++){
        if( a[j] < i || a[j] > dp[i])
          return cout << "NO", 0;
      }
    }
    else{
      if(a[i] != i)
        return cout << "NO", 0;
    }
    i = dp[i];
  }
  cout << "YES";
 
 
  return 0;
}