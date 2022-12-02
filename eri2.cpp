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
		cout << "L = lewo" << endl;
		
		StartProgram(&comm, "program1");
		char decyzja;
		int color;
		char decColor;
		int x = 10;
		int y = 7;
		Sensor::SetColor(&comm, IN_3, 'n');

		do
		{
			color = Sensor::GetValue(&comm, IN_3);
			cout << "n = " << color << endl;
			Wait(500);
			if(kbhit()==true)
			{
				decyzja = getch();
				if(decyzja=='L' || decyzja=='l')
				{
					color=Sensor::GetValue(&comm, IN_2);
					if(color<10)
					{
						Motor::SetForward(&comm, OUT_B, x);
						Motor::SetForward(&comm, OUT_C, x);
					}
					else
					{
						Motor::SetForward(&comm, OUT_B, y);
						Motor::SetForward(&comm, OUT_C, 0);
						Motor::Stop(&comm, OUT_C, 0);
					}
				}
			}
			
		}while(decyzja!='K' && decyzja!='k');
		StopProgram(&comm);
	}

	Close(&comm);

	return 0;
}
