#include <bits/stdc++.h>
using namespace std;
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        long int m,n,x,y,t,h ;
        cin>>n>>m>>endl;
        x = pow(5,n) + pow(7,n);
        y = pow(5,m) + pow(7,m);
        while (true) 
        {
            if (x>y)
            {   h = x;
                x = y;
                y = h;
            }
            t = y % x;
            y = x;
            x = t;
            if ((x == 0) or (x==1)or (x==y)) break ;
        }
        cout<< y <<endl;
    }
    return 0;
}
    