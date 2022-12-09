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
		cout << "D = prawo zewnętrznie" << endl;
		cout << "H = stop" << endl;
		
		StartProgram(&comm, "program1");
		char decyzja;
		int color;
		char decColor;
		int x = 20;
		int y = 6;
		int z = 6;
		Sensor::SetColor(&comm, IN_3, 'n');

		do
		{
			color = Sensor::GetValue(&comm, IN_3);
			cout << "n = " << color << endl;
			if(kbhit()==true)
			{
				decyzja = getch();
			}
			if(decyzja=='L' || decyzja=='l')
			{
				if(color>12 && color<=25)
				{
					Motor::SetForward(&comm, OUT_B, x);
					Motor::SetForward(&comm, OUT_C, x);
					cout << "XXX" << endl;
				}
				else if(color<=25)
				{
					Motor::SetForward(&comm, OUT_B, y);
					Motor::SetReverse(&comm, OUT_C, y);
					cout << "YYY" << endl;
				}
				else if(color>12)
				{
					Motor::SetForward(&comm, OUT_C, z);
					Motor::SetReverse(&comm, OUT_B, z);
					cout << "ZZZ" << endl;
				}
			}
			else if(decyzja=='F' || decyzja=='f')
			{
				if(color<=12 && color>=25)
				{
					Motor::SetForward(&comm, OUT_B, x);
					Motor::SetForward(&comm, OUT_C, x);
					cout << "XXX" << endl;
				}
				else if(color>25)
				{
					Motor::SetForward(&comm, OUT_B, y);
					Motor::SetReverse(&comm, OUT_C, y);
					cout << "YYY" << endl;
				}
				else if(color<12)
				{
					Motor::SetForward(&comm, OUT_C, z);
					Motor::SetReverse(&comm, OUT_B, z);
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
		StopProgram(&comm);
	}

	Close(&comm);

	return 0;
}
