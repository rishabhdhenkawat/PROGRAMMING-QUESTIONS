#include<iostream>
#define ll long long
using namespace std;

main()
{
    ll n, q,l,r;
    cin>>n>>q;
    ll arr[n];
    for(ll i=1;i<=n;i++)
    cin>>arr[i];
    for(ll p=1;p<=q;p++)
    {
    l=0;
    r=0;
    cin>>l>>r;
    if(arr[l]==arr[r])
    {
    cout<<"Yes";
    cout<<endl;
    continue;
    
    }
    ll s=(r-l);
    ll b[s];
    ll m=l,i=1;
    while(m<r)
    {
        if(arr[m]<=arr[m+1])
         b[i]=1;
        if(arr[m]>arr[m+1])
         b[i]=0;
        
        if(i==(r-l))
        break;
        
        
        m++;
        i++;
        
    }
    //cout<<b[r-l];
    
    int k=0,j=1,f=0;
    for(ll i=1;i<=s;i++)
    {
        if(b[i]==b[i+1])
        f=1;
        
    }
    while(j<=s)
    {
       
       
        //cout<<b[j]<<" "<<b[j+1]<<endl;
        if(b[j]<b[j+1]&& b[j+1]==0||b[j+1]==1)
        {
            k=1;
            break;
        }    
        
        
        j++; 
    }
    //cout<<endl;
   
    if(k==1&&f==1)
    cout<<"No";
    else
    if(k==0&&f==1)
    cout<<"Yes";
    
    cout<<endl;
    }
    
}
