#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
static int p = 0;
class a
{
  char busn[2], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
public:
  void create();
  void Reservation();
  void empty();
  void show();
  void join();
  void position(int i);
}
trip[10];
void vline(char ch)//vline
{
  for (int i=80;i>0;i--)
  cout<<ch;
}

void cline(char ch)//cline
{
  for (int i=40;i>0;i--)
  cout<<ch;
}

void a::create()// create bus , bus driver , from , to
{
  cout<<"Enter bus no: "; //
  cin>>trip[p].busn;
  cout<<"\nEnter Driver's name: ";
  cin>>trip[p].driver;
  cout<<"\nArrival time: ";
  cin>>trip[p].arrival;
  cout<<"\nDeparture: ";
  cin>>trip[p].depart;
  cout<<"\nFrom: \t\t\t";
  cin>>trip[p].from;
  cout<<"\nTo: \t\t\t";
  cin>>trip[p].to;
  trip[p].empty();
  p++;
}
void a::Reservation()
{
  int seat;
  char number[5];
  top:
  cout<<"Bus no:";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(trip[n].busn,number)==0)
    break;
  }
  while(n<=p)
  {
    cout<<"\nSeat Number:";
    cin>>seat;
    if(seat>30)
    {
      cout<<"\nThere are only 30 seats available in this bus.";
    }
    else
    {
    if (strcmp(trip[n].seat[seat/4][(seat%4)-1],"Empty")==0)
      {
        cout<<"Enter name: ";
        cin>>trip[n].seat[seat/4][(seat%4)-1];
        break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
      }
    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
      goto top;
    }
  }
void a::empty()
{
  for(int i=0;i<8;i++){
    for(int j=0;j<4;j++){
      strcpy(trip[p].seat[i][j],"Empty");
    }
  }
}


void a::show()
{
  int n;
  char number[5];
  cout<<"Enter bus no: ";
  cin>>number;
  for(n=0;n<=p;n++){
    if(strcmp(trip[n].busn, number)==0)
    break;
  }
while(n<=p)
{
  vline('_');
  cout<<"Bus no:\t"<<trip[n].busn
  <<"\nDriver:\t"<<trip[n].driver<<"\t\tArrival time:\t"
  <<trip[n].arrival<<"\tDeparture time:"<<trip[n].depart
  <<"\nFrom:\t\t"<<trip[n].from<<"\t\tTo:\t\t"<<
  trip[n].to<<"\n";
  vline('_');
  trip[0].position(n);
  int a=1;
  for (int i=0;i<8;i++){
    for(int j=0;j<4;j++){
      a++;
      if(strcmp(trip[n].seat[i][j],"Empty")!=0)
      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<trip[n].seat[i][j]<<".";
    }
  }
  break;
  }
  if(n>p)
    cout<<"Enter correct bus no: ";
}

void a::position(int l){
  int s=0;p=0;
  for (int i=0;i<8;i++){
    cout<<"\n";
    for (int j=0;j<4;j++){
      s++;
      if(strcmp(trip[l].seat[i][j],"Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<trip[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<trip[l].seat[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<trip[l].busn;
  }



void a::join()
{

system("cls");
  int c;
  int ro;
  string na;
  string addd;
  int counting=0;
  cout<<"No of student joining group : ";
  cin>>c;
  for (int i=0;i<c;i++)
    {
    cout<<"rollno:";
    cin>>ro;
  cline('_');
    cout<<"name:";
    cin>>na;
   cline('_');
    cout<<"address:";
    cin>>addd;
    cline('_');
    counting++;
    }
  cout<<"\n\n \t\t\t\t * "<<counting<<"People Joined * \n ";
  cout<<"\n";
  cout<<"\t\t\t\t ROLLNO:"<<ro<<"\n";
  cout<<"\t\t\t\t NAME:"<<na<<"\n";
  cout<<"\t\t\t\t ADDRESS:"<<addd<<"\n";
}

int main()
{
system("cls");
int choice;
string name;
string roomno;
string address;
system("COLOR FC");
    cout<<"\t\t\t\t Enter Name :";
    cin>>name;
    cout<<"\n\t\t\t\t Enter room no:";
    cin>>roomno;
    cout<<"\n\t\t\t\t Enter address:";
    cin>>address;
while(1){
    cout<<"\n\n";
    vline('_');
    cout<<"\n\n";
  cout<<"\t\t\t 1.Create account\n\t\t\t"
  <<"2.Reservation bus\n\t\t\t"
  <<"3.Show available seats\n\t\t\t"
  <<"4.join group\n\t\t\t"
  <<"5.Exit";
  cout<<"\n\n\n";
  vline('_');
  cout<<"\n\n";
  cout<<"\tEnter your choice:";
  cin>>choice;
  switch(choice)
  {
    case 1: trip[p].create();
      break;
    case 2: trip[p].Reservation();
      break;
    case 3: trip[0].show();
      break;
      case 4: trip[p].join();
      break;

case 5: exit(0);
  }
}
return 0;
}



