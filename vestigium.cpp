// code for vesitigium

#include <string> 
#include <bits/stdc++.h>
#include <iostream> 

//toggles on or off the synchronization (this is used for faster I/O

#define Fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


#define int long long

using namespace std;
signed main()
{
    Fastio
    int x; 
	
	
    int z=1;
	cin>>x;
	
	//test case loop
    while(x--)
    {
        int n;
        cin>>n;
		//creating a array with n*n size
        int arr[n][n];
		
		
		//create a set
           set <int> s;
		//initialise the row ,column and sum counter to zero
              int row=0,column=0,sum=0;
		
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<n;j++)
			{   cin>>arr[i][j]; 
		
		
				//
				s.insert(arr[i][j]);
				
				
			}
                
				if(s.size()!=n)
				
				{
					
					row++;
					
				}
                s.clear();            
        }
       for(int i=0;i<n;i++)
       {   //trace->sum of the diagonale
   
   
   
			 sum=sum+arr[i][i];
		   
		   
           for(int j=0;j<n;j++)
           {
			   
			   //inserting in set
					s.insert(arr[j][i]); 

					
           }
		   
		   //s.size()---> Returns the number of elements in the set.
           if(s.size()!=n)
		   {
		
			   column++;
			   
		   }
                s.clear();
       }
		//Case #1: x row column
        cout<<"Case #"<<z++<<": "<<sum<<" "<<row<<" "<<column;
        cout<<"\n";
    }
}