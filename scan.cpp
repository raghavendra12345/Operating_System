#include <iostream>
#include <stdlib.h>
using namespace std;
int find(int*,int ,int);
int main()
{
int *request,*order;

int n,head,position,c,sum=0,nearest,rightmost,last,index;
int j;
cout<<"Enter the total number of disk requests made\n";
cin>>n;
request =new int[n+2];
order=new int[n+2];
int overhead[n+2];
cout<<"Enter the sequence\n";
request[0]=0;

for(int i=1;i<=n;i++)
{
cin>>request[i];

}
cout<<"Enter the rightmost value of the disk\n";
cin>>request[n+1];


cout<<"Enter the inital position of the disk head\n";
cin>>head;

cout<<"Enter the last value processed by disk\n";
cin>>last;
n=n+2;



for(int i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(request[j]>request[j+1])
{
c=request[j];
request[j]=request[j+1];
request[j+1]=c;
}
}}

for(int i=0;i<n;i++)
{
if(head>request[i] && head<request[i+1])
{
index=i;
break;
}
}



if(last<=head)
{
cout<<"RIGHT DIRECTIONS\n";

 j=0;
for(int i=index+1;i<n;i++,j++)

{
order[j]=request[i];
}
for(int i=index;i>=1;i--,j++)
{
order[j]=request[i];
}
}

else
{
j=0;
for(int i=index;i>=0;i--,j++)
order[j]=request[i];

for(int i=index+1;i<n-1;i++,j++)
order[j]=request[i];
}

overhead[0]=abs(order[0]-head);
sum=overhead[0];
for(int i=1;i<j;i++)
{
overhead[i]=abs(order[i]-order[i-1]);
sum=sum+overhead[i];
}

 cout<<"SCAN order\n";
for(int i=0;i<j;i++)
cout<<order[i]<<"\n";

cout<<"\nHead Movement per move\n"; 
for(int i=0;i<j;i++)
cout<<overhead[i]<<"\n";

cout<<"The total overhead is "<<sum<<"\n";

return 0;
}

