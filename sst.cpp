#include <iostream>
#include <stdlib.h>
using namespace std;
int find(int *,int,int);
int main()
{
int *request,*order;

int n,head,position,c,sum=0,nearest;
cout<<"Enter the total number of disk requests made\n";
cin>>n;
request =new int[n];
order=new int[n];
int overhead[n];
cout<<"Enter the sequence\n";

for(int i=0;i<n;i++)
{
cin>>request[i];

}

cout<<"Enter the inital position of the disk head\n";
cin>>head;





for(int i=0;i<n;i++)
{
nearest= find(request,n,head);
order[i]=nearest;
overhead[i]=abs(head-nearest);
head=nearest;
sum=sum+overhead[i];
}

cout<<"Order of Execution Shortest Seek Time\n";
for(int i=0;i<n;i++)
{
cout<<order[i]<<"\n";
}

cout<<"Head Movement per move\n";
for(int i=0;i<n;i++)
{
cout<<overhead[i]<<"\n";
}

cout<<"\nThe total overhead for shortest seek time is "<<sum<<"\n";

return 0;
}


int find(int request[], int m,int head)
{
int nearest=1000,c,d;
for(int i=0;i<m;i++)
{
if(request[i]>0)
{
c=abs(request[i]-head);
if(c<nearest)
{nearest=c;
d=i;
}
}
}
nearest=request[d];
request[d]=-1;

return nearest;
}


