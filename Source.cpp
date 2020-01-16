#include <iostream>

#include "Deque.h"
#include "RangeException.h"
#include "algoritm.h"

#include "BinaryWatch.h"
#include "SmartWatch.h"
#include "WallWatch.h"
#include "WristWatch.h"

using namespace std;

int main()
{
	cout << "Input type" << endl;
	cout << "1. Smart Watch" << endl;
	cout << "2. Binary Watch" << endl;
	cout << "3. Wrist Watch" << endl;
	cout << "4. Wall Watch" << endl;
	cout << "0. exit" << endl;
	int number = RangeException::inputInt(cin, 0, 4);
	switch (number)
	{
	case 1: {
		Deque<SmartWatch> DQ;
		operationsSmartWatch(DQ);
		break;
	}
	case 2: {
		Deque <BinaryWatch> DQ;
		operationsBinaryWatch(DQ);
		break;
	}
	case 3: {
		Deque <WristWatch> DQ;
		operationsWristWatch(DQ);
		break;
	}
	case 4: {
		Deque <WallWatch> DQ;
		operationsWallWatch(DQ);
		break;
	}
	case 0: {
		return 0;
		break;
	}
	}
}