#include <bits/stdc++.h>
 
 
using namespace std; 
 
int f(long long x, int c)
{
   return (x >> c) & 1;
}
long long sum,n,m[500005];
long long a[70],b[70];
int main() 
{ 
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   int t;
   cin >> t ;
   while (t--)
   {
      
      for ( int i= 0;i <69;i++)
      {
         a[i] = 0 ;
         b[i] = 0 ;
      }
      sum = 0;
      cin>> n;
      for (int j = 0 ; j < n ; j++)
      cin>>m[j] ;
      int maxc = 0 ;
      for (int c = 0; c < 60; c++)
      {  
 
         long long sum_1 = 0;
         long long sum_2 = 0;
 
         for ( int i =0; i<n ; i++)
         {
            if (f(m[i],c) && maxc < c ) maxc = c ;
            sum_1 += f(m[i],c);
            sum_2 += 1 - f(m[i],c);
         }
         a[c] = sum_1;
         b[c] = sum_2;
      }
      for (int j = 0;j<n;j++)
      {
         long long sum1 = 0;
 
         long long sum2 = 0;
         for  (int c = 0; c < (maxc + 1) ;c++)
         {
         	long long z = (1ll << c);
            sum1 += (((1ll*z)%1000000007)*(f(m[j],c)*a[c]))%1000000007;
            sum2 += (((1ll*z)%1000000007)*(n - (1-f(m[j],c))*b[c]))%1000000007;
            sum1 %= 1000000007 ;
            sum2 %= 1000000007	;
         }
         sum += (sum1*sum2)%1000000007;
         sum = sum % 1000000007;
      }
      sum = sum % 1000000007;
   
      cout << sum << '\n';
    	
   }
   
   return 0 ;
 
}