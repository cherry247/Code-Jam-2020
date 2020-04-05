//nesting depth

#include<iostream>
#include <bits/stdc++.h>
#define int long long
//toggles on or off the synchronization (this is used for faster I/O


#define Fastio ios_base::sync_with_stdio(false); 
cin.tie(0); 
cout.tie(0);
using namespace std;
signed main()
{
    Fastio
    int t;
    
    int k=1;
	
	cin>>t;
	//for the test case
    while(t--)
    {
        string st; 
		//input a string
		cin>>st;
		
		
        int pt=0;
		int y;
		int g=st[0]-'0';
		
		
        string ans="";
        if(g==0)
		{
			ans+="0";
		}
        else{
            pt=g;
			
            while(g--)
			{
				ans+="(";
			}
            ans+=st[0];
        }
        for(int i=1;i<st.length();i++)
        {
            x=st[i]-'0';
            y=st[i-1]-'0';
           
            if(y>x)
            {
                int z=y-x;
                pt=pt-z;
                while(z--) 
				{
					ans+=")";
				}
                ans+=st[i];
            }
            else if(x>y)
            {
                
				int z=x-y;
                pt+=z;
                while(z--) 
				{
					ans+="(";
				}
                ans+=st[i];
            }
            else{
                ans+=st[i];
            }
        }
        
        while(pt--)
		{
			ans+=")";
		}
		
		//Case #1: 0000
        cout<<"Case #"<<k++<<": "<<ans<<endl;

    }
}