#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
int *request;

int n,head;
cout<<"Enter the total number of disk requests made\n";
cin>>n;
request =new int[n];
cout<<"Enter the sequence\n";

for(int i=0;i<n;i++)
{
cin>>request[i];

}
cout<<"Enter the inital position of the disk head\n";
cin>>head;

int overhead[n],sum=0;

overhead[0]=request[0]-head;
sum=overhead[0];

for(int i=1;i<n;i++)
{
overhead[i]=abs(request[i]-request[i-1]);
sum=sum+overhead[i];
}

 cout<<"FCFS order\n";
for(int i=0;i<n;i++)
cout<<request[i]<<"\n";
cout<<"====================================\n";
cout<<"\nHead Movement per move\n"; 
for(int i=0;i<n;i++)
cout<<overhead[i]<<"\n";
cout<<"====================================\n";

cout<<"The total overhead is "<<sum<<"\n";

return 0;
}

