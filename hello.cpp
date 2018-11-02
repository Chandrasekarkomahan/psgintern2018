#include<iostream>
#include <ctime>
using namespace std;
int i,month;
float total,high,low;
int displayMonthly(float rain[])
{
for(i=0; i<12; i++)
{
cout<<"Rainfall for month"<<(i+1)<<":"<<rain[i]<<endl;
}
cout<<endl;
}
float displayTotal(float rain[])
{
total=0;
for(i=0; i<12; i++)
{
total += rain[i];
}
return total;
}
int displayAverage(float rain[])
{
cout<<"The average rainfall amounts during the year"<<displayTotal(rain)/12.0<<endl<<endl;;
}
int displayHigh(float rain[])
{
month = 0;
high = rain[0];
for(i=1; i<12; i++)
{
if(rain[i] > high)
{
high = rain[i];
month = i;
}
}
cout<<"The month "<<(month+1)<<" has the highest rainfall amount "<<high<<endl<<endl;;
}
int displayLow(float rain[])
{
month = 0;
low = rain[0];
for(i=1; i<12; i++)
{
if(rain[i] < low)
{
low = rain[i];
month = i;
}
}
cout<<"The month "<<(month+1)<<" has the lowest rainfall amount "<<low<<endl<<endl;;
}
int main()
{
float rain[12];
int n;
int pin;
string reg;
cout<<"pincode :";
cin>>pin;
cout<<"region :";
cin>>reg;
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];
  time (&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S \n ",timeinfo);
  std::string str(buffer);
  std::cout << str;
  return 0;
for(i=0; i<12; i++)
{
cout<<"Enter rainfall for month "<<(i+1)<<":";
cin>>rain[i];
}
while(1)
{
cout<<"1.Display monthly amounts\n";
cout<<"2.Display total amount\n";
cout<<"3.Display average amount\n";
cout<<"4.Display highest amount\n";
cout<<"5.Display low amount\n";
cout<<"6.End program\n";
cout<<"Enter your choice : ";
cin>>n;
switch(n)
{
case 1 : displayMonthly(rain);
break;
case 2 : cout<<"The total rainfall amounts for the entire year : "<<displayTotal(rain)<<endl<<endl;
break;
case 3 : displayAverage(rain);
break;
case 4 : displayHigh(rain);
break;
case 5 : displayLow(rain);
break;
case 6 : cout<<"end:)";
break;
default : cout<<"Wrong Choice!!!";
}
}
}
