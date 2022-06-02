#include<bits/stdc++.h> 
using namespace std; 
  
int go(long long int ar[], long long int ar_size) 
{ 
    int res = 0;  
    for (int i = 0; i < ar_size; i++)      
        res = res ^ ar[i]; 
      
    return res; 
}

int main() 
    { 
  		int t;
  		cin >> t;
  		while(t--) {
        	long long int n;
          	cin >> n;
          	int nn = (4*n-1);
          	long long int a[nn], b[nn] ;
          	for(int i = 0; i < nn; ++i) 
              	cin >> a[i] >> b[i] ;
        	cout << go(a, nn) << " "  << go(b, nn) << "\n" ; 
        } 
        return 0; 
    } 