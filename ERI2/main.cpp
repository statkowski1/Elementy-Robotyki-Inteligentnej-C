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
		cout<<"Poziom baterii = " << BatteryLevel(&comm) << endl;
		cout<<"Dostepna pamiec flash = " << GetAvailableFlash(&comm) << endl;
		
		Sensor::SetColor(&comm, IN_2, 'n');
		StartProgram(&comm, IN_1);
		char decyzja;
		int color;
		
		do
		{
			color=Sensor::GetValue(&comm, IN_3);
			if(color<10)
			{
				
			}
			else
			{
				
			}
		} while(decyzja!='k' && decyzja!='K');
		StopProgram(&comm);
	}


	Close(&comm);

	return 0;
}
