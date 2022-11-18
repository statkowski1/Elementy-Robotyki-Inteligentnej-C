#include "NXT++.h"
#include <conio.h>

using namespace NXT;
using namespace std;
Comm::NXTComm comm;
int main()
{
 cout << "\naquiring signal ... ";
int pointer=0;
if(Open(&comm))/*initialize the NXT via cable or bluetooth and continue if it
succeeds*/
 {
 pointer=1;
 cout<< "signal found";
 StartProgram(&comm,"ExemplaryProgram");
 //declaration of variables
 int color;
 char decColor;
 char temp_choice='o';
 do
{//the beginning of loop
cout<<"\n\n -----------------------------------------";
cout<<"\n color sensor, commands:";
cout<<"\n press f - to detect the full color, considering only:";
cout<<"\n press q - to turn off the sensor\n";
 decColor=getch();
/*The first initiation of sensor is delayed by 0.3s, the following condition let to
avoid delays in multiple reading of the same mode*/
 color=Sensor::GetValue(&comm, IN_3);
if(decColor=='F' || decColor=='f' || decColor=='d')
 {
 cout<<"\n\nIt looks like ";
if(color==1){cout<<"black\n";}
if(color==2){cout<<"blue\n";}
if(color==3){cout<<"green\n";}
if(color==4){cout<<"yellow\n";}
if(color==5){cout<<"red\n";}
if(color==6){cout<<"white\n";}
 //NXT::Sensor::SetColor(&comm, IN_3, 'n');
 }
}//the end of loop
 while(decColor!='q' && decColor!='Q');
cout<<"\n\nprogram is shutting down";
StopProgram(&comm);
 }
Close(&comm); //close the NXT
if(pointer==0){cout<<"\n\nconnection with NXT brick failed";Wait(3000);}
return 0;
}
