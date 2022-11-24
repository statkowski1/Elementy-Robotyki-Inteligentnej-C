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
		
		
		
		StartProgram(&comm, IN_1);
	}
























	Close(&comm);

	return 0;
}
