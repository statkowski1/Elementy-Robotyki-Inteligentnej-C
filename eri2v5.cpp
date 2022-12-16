#include "NXT++.h"
#include <iostream>
#include <conio.h>
using namespace std;
using namespace NXT;

Comm::NXTComm comm;

int main()
{
	cout << "Szukanie sygnału..." << endl;
	srand(time(NULL));
	if(Open(&comm))
	{
		cout << "Sygnał znaleziony!" << endl;
		cout << "Poziom baterii = " << BatteryLevel(&comm) << endl;
		cout << "Dostepna pamiec flash = " << GetAvailableFlash(&comm) << endl;
		cout << "L = lewo wewnętrznie" << endl;
		cout << "F = lewo zewnętrznie" << endl;
		cout << "P = prawo wewnętrznie" << endl;
		cout << "Z = prawo zewnętrznie" << endl;
		cout << "H = stop" << endl;
		
		StartProgram(&comm, "program1");
		char decyzja;
		int color;
		char decColor;
		int x = 20;
		int x2 = 8;
		int x3 = 12;
		int y = 6;
		int z = 4;
		Sensor::SetColor(&comm, IN_3, 'g');

		do
		{
			color = Sensor::GetValue(&comm, IN_3);
			cout << "n = " << color << endl;
			Wait(20);
			if(kbhit()==true)
			{
				decyzja = getch();
			}
			if(decyzja=='L' || decyzja=='l')
			{
				if(color>=250 && color<=145)
				{
					Motor::SetForward(&comm, OUT_B, x);
					Motor::SetForward(&comm, OUT_C, x);
					cout << "XXX" << endl;
				}
				else if(color>=250)
				{
					Motor::SetForward(&comm, OUT_B, x3);
					Motor::SetReverse(&comm, OUT_C, y);
					cout << "YYY" << endl;
				}
				else if(color<=145)
				{
					Motor::SetForward(&comm, OUT_C, x2);
					Motor::SetReverse(&comm, OUT_B, z);
					cout << "ZZZ" << endl;
				}
			}
			else if(decyzja=='F' || decyzja=='f')
			{
				if(color>=4 && color<=11)
				{
					Motor::SetForward(&comm, OUT_B, x);
					Motor::SetForward(&comm, OUT_C, x);
					cout << "XXX" << endl;
				}
				else if(color>=11)
				{
					Motor::SetForward(&comm, OUT_C, x2);
					Motor::SetReverse(&comm, OUT_B, z);
					cout << "YYY" << endl;
				}
				else if(color<=4)
				{
					Motor::SetForward(&comm, OUT_B, x3);
					Motor::SetReverse(&comm, OUT_C, y);
					cout << "ZZZ" << endl;
				}
			}
			else if(decyzja=='P' || decyzja=='p')
			{
				if(color>=8 && color<=45)
				{
					Motor::SetForward(&comm, OUT_B, x);
					Motor::SetForward(&comm, OUT_C, x);
					cout << "XXX" << endl;
				}
				else if(color>=45)
				{
					Motor::SetForward(&comm, OUT_C, x3);
					Motor::SetReverse(&comm, OUT_B, y);
					cout << "YYY" << endl;
				}
				else if(color<=8)
				{
					Motor::SetForward(&comm, OUT_B, x2);
					Motor::SetReverse(&comm, OUT_C, z);
					cout << "ZZZ" << endl;
				}
			}
			else if(decyzja=='Z' || decyzja=='z')
			{
				if(color>=4 && color<=21)
				{
					Motor::SetForward(&comm, OUT_B, x);
					Motor::SetForward(&comm, OUT_C, x);
					cout << "XXX" << endl;
				}
				else if(color>=21)
				{
					Motor::SetForward(&comm, OUT_B, x2);
					Motor::SetReverse(&comm, OUT_C, z);
					cout << "YYY" << endl;
				}
				else if(color<=4)
				{
					Motor::SetForward(&comm, OUT_C, x3);
					Motor::SetReverse(&comm, OUT_B, y);
					cout << "ZZZ" << endl;
				}
			}
			else if(decyzja=='H' || decyzja=='h')
			{
				Motor::SetForward(&comm, OUT_B, 0);
				Motor::SetForward(&comm, OUT_C, 0);
				Motor::Stop(&comm, OUT_B, 0);
				Motor::Stop(&comm, OUT_C, 0);
			}
		}while(decyzja!='K' && decyzja!='k');
		Sensor::SetColorOff(&comm, IN_3);
		StopProgram(&comm);
	}

	Close(&comm);

	return 0;
}
