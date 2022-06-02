#include<bits/stdc++.h>
#define LL long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
   fastio;
   LL t;
   cin>>t;
   while(t--)
   {
      string s;
      LL ct0 = 0, ct1 = 0, ans = 0, range, n, i, j;
      cin>>s;
      n = s.size();
      for(i = 1; i*i+i <= n; i++)
      {
         ct0 = 0, ct1 = 0, range = i*i + i;
         for(j = 0; j < range; j++){
            if(s[j]=='0')
               ct0++;
            else
               ct1++;
         }
         if(ct1 == i)  // edit
               ans++;
         for(j = range; j < n; j++){
            if(s[j - range] == '0')
               ct0--;
            else
               ct1--;
            if(s[j] == '0')
               ct0++;
            else
               ct1++;
            if(ct1 == i)
                ans++;
         }

      }
      cout<<ans<<endl;
   }
  return 0;
}