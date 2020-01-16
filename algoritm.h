#pragma once

#include "Deque.h"
#include "RangeException.h"
#include "NameException.h"
#include <string>

#include "SmartWatch.h"
#include "WristWatch.h"
#include "BinaryWatch.h"
#include "WallWatch.h"

#include "File.h"

#define SMART_WATCH 0
#define BINARY_WATCH 1
#define WALL_WATCH 2
#define WRIST_WATCH 3

using namespace std;

template<class InputIterator, class T>
InputIterator my_find(InputIterator first, InputIterator last, const T& val)
{
	while (first != last) {
		if (*first == val) return first;
		++first;
	}
	return last;
}

void outputTable(const int TYPE) {
	switch (TYPE)
	{
	case SMART_WATCH: {
		SmartWatch::headOfTable();
		break;
	}
	case BINARY_WATCH: {
		BinaryWatch::headOfTable();
		break;
	}
	case WALL_WATCH: {
		WallWatch::headOfTable();
		break;
	}
	case WRIST_WATCH: {
		WristWatch::headOfTable();
		break;
	}
	}
}

template<class Type>
void workingWithFile(Deque<Type>& dq)
{
	system("CLS");
	std::cout << "1. Read text" << std::endl;
	std::cout << "2. Write text" << std::endl;
	std::cout << "3. Read binary" << std::endl;
	std::cout << "4. Write binary" << std::endl;
	std::cout << "5. Read index binary" << std::endl;
	std::cout << "6. Swap first last" << std::endl;

	File currentFile;
	string fileName = typeid(Type).name();
	int action = RangeException::inputInt(cin, 1, 6);
	switch (action)
	{
	case 1: {
		currentFile.openTextFileRead((fileName + ".txt").c_str());
		currentFile.read_text(dq);
		break;
	}
	case 2: {
		currentFile.openTextFileWrite((fileName + ".txt").c_str());
		currentFile.write_text(dq);
		break;
	}
	case 3: {
		currentFile.openBinaryFileRead((fileName + ".bin").c_str());
		currentFile.read_binary(dq);
		break;
	}
	case 4: {
		currentFile.openBinaryFileWrite((fileName + ".bin").c_str());
		currentFile.write_binary(dq);
		break;
	}
	case 5: {
		currentFile.openBinaryFileRead((fileName + ".bin").c_str());
		currentFile.read_index_binary(dq);
		break;
	}
	case 6: {
		currentFile.openBinaryFileRead((fileName + ".bin").c_str());
		currentFile.swap_first_last(dq, (fileName + ".bin").c_str());
		break;
	}
	}
	system("CLS");
	std::cout << "OK" << std::endl;
	system("PAUSE");
}

template<class Type>
void addDequeTop(Deque<Type>& dq)
{
	Type T;
	cin >> T;
	dq.pushTop(T);
	std::cout << "OK" << std::endl;
	system("PAUSE");
}

template<class Type>
void showDeque(Deque<Type>& dq, const int TYPE)
{
	typename Deque<Type>::iterator it;
	if (dq.size() == 0) {
		std::cout << "EMPTY" << std::endl;
		std::cout << "OK" << std::endl;
		system("PAUSE");
		return;
	}
	outputTable(TYPE);
	std::cout << endl;
	for (it = dq.it_begin(); it != dq.it_end(); it++) {
		std::cout << (*it) << std::endl;
	}
	std::cout << "OK" << std::endl;
	system("PAUSE");
}

template<class Type>
void addDequeBack(Deque<Type>& dq)
{
	Type T;
	cin >> T;
	dq.pushBack(T);
	std::cout << "OK" << std::endl;
	system("PAUSE");
}

template<class Type>
void popDequeTop(Deque<Type>& dq)
{
	try {
		dq.popTop();
	}
	catch (std::exception & exp) {
		cout << exp.what() << endl;
	}
	std::cout << "OK" << std::endl;
	system("PAUSE");
}

template<class Type>
void dequeTop(Deque<Type>& dq, const int TYPE)
{
	outputTable(TYPE);
	std::cout << endl;
	try {
		std::cout << dq.top() << endl;
	}
	catch (std::exception & exp) {
		cout << exp.what() << endl;
	}
	std::cout << "OK" << std::endl;
	system("PAUSE");
}

template<class Type>
void popDequeBack(Deque<Type>& dq)
{
	try {
		cout << dq.popBack() << endl;
	}
	catch (std::exception & exp) {
		cout << exp.what() << endl;
	}
	std::cout << "OK" << std::endl;
	system("PAUSE");
}

template<class Type>
void dequeBack(Deque<Type>& dq, const int TYPE)
{
	outputTable(TYPE);
	std::cout << endl;
	try {
		cout << dq.back() << endl;
	}
	catch (std::exception & exp) {
		cout << exp.what() << endl;
	}
	std::cout << "OK" << std::endl;
	system("PAUSE");
}

template<class Type>
void dequeClear(Deque<Type>& dq)
{
	dq.clear();
	std::cout << "OK" << std::endl;
	system("PAUSE");
}

template<class Type>
void isDequeEmpty(Deque<Type>& dq)
{
	cout << dq.isEmpty() << endl;
	std::cout << "OK" << std::endl;
	system("PAUSE");
}

template<class Type>
void dequeFindOne(Deque<Type>& dq, const int TYPE, Type T)
{
	typename Deque<Type>::iterator it;
	it = my_find(dq.it_begin(), dq.it_end(), T);
	outputTable(TYPE);
	cout << endl << (*it) << endl;
	std::cout << "OK" << std::endl;
	system("PAUSE");
}

template<class Type>
void dequeFindAll(Deque<Type>& dq, const int TYPE, Type T)
{
	typename Deque<Type>::iterator it;
	outputTable(TYPE);
	std::cout << endl;
	for (it = dq.it_begin(); it != dq.it_end(); it++) {
		if ((*it) == T) {
			std::cout << (*it) << std::endl;
		}
	}
}

void chosenSmartWatch(Deque<SmartWatch>& dq, int findType)
{
	SmartWatch T;
	while (true) {
		std::cout << "1. Name" << std::endl;
		std::cout << "2. Produser" << std::endl;
		std::cout << "3. Battery capacity" << std::endl;
		std::cout << "4. Display size" << std::endl;
		std::cout << "0. End" << std::endl;

		int action = RangeException::inputInt(cin, 0, 4);
		bool end = false;
		int inputInt;
		std::string inputString;

		switch (action)
		{
		case 1: {
			inputString = NameException::inputString(cin);
			T.setName(inputString);
			break;
		}
		case 2: {
			inputString = NameException::inputString(cin);
			T.setProducer(inputString);
			break;
		}
		case 3: {
			inputInt = RangeException::inputInt(cin, 1, 10000);
			T.setBatteryCapacity(inputInt);
			break;
		}
		case 4: {
			inputInt = RangeException::inputInt(cin, 1, 10000);
			T.setDisplaySize(inputInt);
			break;
			break;
		}
		case 0: {
			end = true;
			break;
		}
		}

		if (end) {
			break;
		}

	}

	switch (findType)
	{
	case 1: {
		dequeFindOne(dq, SMART_WATCH, T);
		break;
	}
	case 2: {
		dequeFindAll(dq, SMART_WATCH, T);
		break;
	}
	}

	std::cout << "OK" << std::endl;
	system("PAUSE");
}

void chosenWallWatch(Deque<WallWatch>& dq, int findType)
{
	WallWatch T;
	while (true) {
		std::cout << "1. Name" << std::endl;
		std::cout << "2. Produser" << std::endl;
		std::cout << "3. Mechanism" << std::endl;
		std::cout << "4. Footprint" << std::endl;
		std::cout << "0. End" << std::endl;

		int action = RangeException::inputInt(cin, 0, 4);
		bool end = false;
		int inputInt;
		std::string inputString;

		switch (action)
		{
		case 1: {
			inputString = NameException::inputString(cin);
			T.setName(inputString);
			break;
		}
		case 2: {
			inputString = NameException::inputString(cin);
			T.setProducer(inputString);
			break;
		}
		case 3: {
			inputString = NameException::inputString(cin);
			T.setMechanismDesign(inputString);
			break;
		}
		case 4: {
			inputInt = RangeException::inputInt(cin, 1, 10000);
			T.setFootprint(inputInt);
			break;
		}
		case 0: {
			end = true;
			break;
		}
		}

		if (end) {
			break;
		}

	}

	switch (findType)
	{
	case 1: {
		dequeFindOne(dq, WALL_WATCH, T);
		break;
	}
	case 2: {
		dequeFindAll(dq, WALL_WATCH, T);
		break;
	}
	}

	std::cout << "OK" << std::endl;
	system("PAUSE");
}

void chosenWristWatch(Deque<WristWatch>& dq, int findType)
{
	WristWatch T;
	while (true) {
		std::cout << "1. Name" << std::endl;
		std::cout << "2. Produser" << std::endl;
		std::cout << "3. Mechanism" << std::endl;
		std::cout << "4. Dial size" << std::endl;
		std::cout << "0. End" << std::endl;

		int action = RangeException::inputInt(cin, 0, 4);
		bool end = false;
		int inputInt;
		std::string inputString;

		switch (action)
		{
		case 1: {
			inputString = NameException::inputString(cin);
			T.setName(inputString);
			break;
		}
		case 2: {
			inputString = NameException::inputString(cin);
			T.setProducer(inputString);
			break;
		}
		case 3: {
			inputString = NameException::inputString(cin);
			T.setMechanismDesign(inputString);
			break;
		}
		case 4: {
			inputInt = RangeException::inputInt(cin, 1, 10000);
			T.setDialSize(inputInt);
			break;
			break;
		}
		case 0: {
			end = true;
			break;
		}
		}

		if (end) {
			break;
		}

	}

	switch (findType)
	{
	case 1: {
		dequeFindOne(dq, WRIST_WATCH, T);
		break;
	}
	case 2: {
		dequeFindAll(dq, WRIST_WATCH, T);
		break;
	}
	}

	std::cout << "OK" << std::endl;
	system("PAUSE");
}

void chosenBinaryWatch(Deque<BinaryWatch>& dq, int findType)
{
	BinaryWatch T;
	while (true) {
		std::cout << "1. Name" << std::endl;
		std::cout << "2. Produser" << std::endl;
		std::cout << "3. Battery capasity" << std::endl;
		std::cout << "4. Luminidiodes" << std::endl;
		std::cout << "0. End" << std::endl;

		int action = RangeException::inputInt(cin, 0, 4);
		bool end = false;
		int inputInt;
		std::string inputString;

		switch (action)
		{
		case 1: {
			inputString = NameException::inputString(cin);
			T.setName(inputString);
			break;
		}
		case 2: {
			inputString = NameException::inputString(cin);
			T.setProducer(inputString);
			break;
		}
		case 3: {
			inputInt = RangeException::inputInt(cin, 1, 100);
			T.setBatteryCapacity(inputInt);
			break;
		}
		case 4: {
			inputInt = RangeException::inputInt(cin, 1, 10000);
			T.setNumberOfLuminodiodes(inputInt);
			break;
		}
		case 0: {
			end = true;
			break;
		}
		}

		if (end) {
			break;
		}

	}

	switch (findType)
	{
	case 1: {
		dequeFindOne(dq, BINARY_WATCH, T);
		break;
	}
	case 2: {
		dequeFindAll(dq, BINARY_WATCH, T);
		break;
	}
	}

	std::cout << "OK" << std::endl;
	system("PAUSE");
}

void chosenSortingSmartWatch(Deque<SmartWatch>& dq)
{
	std::cout << "1. Decrement" << std::endl;
	std::cout << "2. Increment" << std::endl;
	int sortingType = RangeException::inputInt(cin, 1, 2);
	
	std::cout << "1. Name" << std::endl;
	std::cout << "2. Producer" << std::endl;
	std::cout << "3. BatteryCapacity" << std::endl;
	std::cout << "4. Display size" << std::endl;

	bool (*compare)(SmartWatch&, SmartWatch&) = SmartWatch::sortingName;

	int compareType = RangeException::inputInt(cin, 1, 4);

	switch (compareType)
	{
	case 1: {
		compare = SmartWatch::sortingName;
		break;
	}
	case 2: {
		compare = SmartWatch::sortingProducer;
		break;
	}
	case 3: {
		compare = SmartWatch::sortingBatteryCapacity;
		break;
	}
	case 4: {
		compare = SmartWatch::sortingDisplaySize;
		break;
	}
	}

	dq.sort(compare, sortingType);

	std::cout << "OK" << std::endl;
	system("PAUSE");
}

void chosenSortingWallWatch(Deque<WallWatch>& dq)
{
	std::cout << "1. Decrement" << std::endl;
	std::cout << "2. Increment" << std::endl;
	int sortingType = RangeException::inputInt(cin, 1, 2);

	std::cout << "1. Name" << std::endl;
	std::cout << "2. Producer" << std::endl;
	std::cout << "3. Mechanism Design" << std::endl;
	std::cout << "4. Footprint size" << std::endl;

	bool (*compare)(WallWatch&, WallWatch&) = WallWatch::sortingName;

	int compareType = RangeException::inputInt(cin, 1, 4);

	switch (compareType)
	{
	case 1: {
		compare = WallWatch::sortingName;
		break;
	}
	case 2: {
		compare = WallWatch::sortingProducer;
		break;
	}
	case 3: {
		compare = WallWatch::sortingMechanismDesign;
		break;
	}
	case 4: {
		compare = WallWatch::sortingFootprint;
		break;
	}
	}

	dq.sort(compare, sortingType);

	std::cout << "OK" << std::endl;
	system("PAUSE");
}

void chosenSortingWristWatch(Deque<WristWatch>& dq)
{
	std::cout << "1. Decrement" << std::endl;
	std::cout << "2. Increment" << std::endl;
	int sortingType = RangeException::inputInt(cin, 1, 2);

	std::cout << "1. Name" << std::endl;
	std::cout << "2. Producer" << std::endl;
	std::cout << "3. Mechanism Design" << std::endl;
	std::cout << "4. Dial size" << std::endl;

	bool (*compare)(WristWatch&, WristWatch&) = WristWatch::sortingName;

	int compareType = RangeException::inputInt(cin, 1, 4);

	switch (compareType)
	{
	case 1: {
		compare = WristWatch::sortingName;
		break;
	}
	case 2: {
		compare = WristWatch::sortingProducer;
		break;
	}
	case 3: {
		compare = WristWatch::sortingMechanismDesign;
		break;
	}
	case 4: {
		compare = WristWatch::sortingDialSize;
		break;
	}
	}

	dq.sort(compare, sortingType);

	std::cout << "OK" << std::endl;
	system("PAUSE");
}

void chosenSortingBinaryWatch(Deque<BinaryWatch>& dq)
{
	std::cout << "1. Decrement" << std::endl;
	std::cout << "2. Increment" << std::endl;
	int sortingType = RangeException::inputInt(cin, 1, 2);

	std::cout << "1. Name" << std::endl;
	std::cout << "2. Producer" << std::endl;
	std::cout << "3. BatteryCapacity" << std::endl;
	std::cout << "4. Number Of Lumiodiodes" << std::endl;

	bool (*compare)(BinaryWatch&, BinaryWatch&) = BinaryWatch::sortingName;

	int compareType = RangeException::inputInt(cin, 1, 4);

	switch (compareType)
	{
	case 1: {
		compare = BinaryWatch::sortingName;
		break;
	}
	case 2: {
		compare = BinaryWatch::sortingProducer;
		break;
	}
	case 3: {
		compare = BinaryWatch::sortingBatteryCapacity;
		break;
	}
	case 4: {
		compare = BinaryWatch::sortingNumberOfLumiodiodes;
		break;
	}
	}

	dq.sort(compare, sortingType);

	std::cout << "OK" << std::endl;
	system("PAUSE");
}

void outputMenu() 
{
	system("CLS");
	cout << "1. push top" << endl;
	cout << "2. push back" << endl;
	cout << "3. pop top" << endl;
	cout << "4. pop back" << endl;
	cout << "5. top" << endl;
	cout << "6. back" << endl;
	cout << "7. clear" << endl;
	cout << "8. is empty" << endl;
	cout << "9. find one" << endl;
	cout << "10. show" << endl;
	cout << "11. find all" << endl;
	cout << "12. sorting" << endl;
	cout << "13. working with file" << endl;
	cout << "0. exit" << endl;
}

void operationsSmartWatch(Deque<SmartWatch> dq)
{
	while (true) {
		outputMenu();
		SmartWatch T;
		int number = RangeException::inputInt(cin, 0, 13);
		switch (number)
		{
		case 1: {
			addDequeTop(dq);
			break;
		}
		case 2: {
			addDequeBack(dq);
			break;
		}
		case 3: {
			popDequeTop(dq);
			break;
		}
		case 4: {
			popDequeTop(dq);
			break;
		}
		case 5: {
			dequeTop(dq, SMART_WATCH);
			break;
		}
		case 6: {
			dequeBack(dq, SMART_WATCH);
			break;
		}
		case 7: {
			dequeClear(dq);
			break;
		}
		case 8: {
			isDequeEmpty(dq);
			break;
		}
		case 9: {
			chosenSmartWatch(dq,1);
			break;
		}
		case 10: {
			showDeque(dq, SMART_WATCH);
			break;
		}
		case 11: {
			chosenSmartWatch(dq, 2);
			break;
		}
		case 12: {
			chosenSortingSmartWatch(dq);
			break;
		}
		case 13: {
			workingWithFile(dq);
			break;
		}
		case 0: {
			return;
			break;
		}
		}
	}
}

void operationsWristWatch(Deque<WristWatch> dq)
{
	while (true) {
		outputMenu();
		WristWatch T;
		int number = RangeException::inputInt(cin, 0, 10);
		switch (number)
		{
		case 1: {
			addDequeTop(dq);
			break;
		}
		case 2: {
			addDequeBack(dq);
			break;
		}
		case 3: {
			popDequeTop(dq);
			break;
		}
		case 4: {
			popDequeTop(dq);
			break;
		}
		case 5: {
			dequeTop(dq, WRIST_WATCH);
			break;
		}
		case 6: {
			dequeBack(dq, WRIST_WATCH);
			break;
		}
		case 7: {
			dequeClear(dq);
			break;
		}
		case 8: {
			isDequeEmpty(dq);
			break;
		}
		case 9: {
			chosenWristWatch(dq, 1);
			break;
		}
		case 10: {
			showDeque(dq, WRIST_WATCH);
			break;
		}
		case 11: {
			chosenWristWatch(dq, 2);
			break;
		}
		case 12: {
			chosenSortingWristWatch(dq);
			break;
		}
		case 0: {
			return;
			break;
		}
		}
	}
}

void operationsWallWatch(Deque<WallWatch> dq)
{
	while (true) {
		outputMenu();
		WallWatch T;
		int number = RangeException::inputInt(cin, 0, 10);
		switch (number)
		{
		case 1: {
			addDequeTop(dq);
			break;
		}
		case 2: {
			addDequeBack(dq);
			break;
		}
		case 3: {
			popDequeTop(dq);
			break;
		}
		case 4: {
			popDequeTop(dq);
			break;
		}
		case 5: {
			dequeTop(dq, WALL_WATCH);
			break;
		}
		case 6: {
			dequeBack(dq, WALL_WATCH);
			break;
		}
		case 7: {
			dequeClear(dq);
			break;
		}
		case 8: {
			isDequeEmpty(dq);
			break;
		}
		case 9: {
			chosenWallWatch(dq, 1);
			break;
		}
		case 10: {
			showDeque(dq, WALL_WATCH);
			break;
		}
		case 11: {
			chosenWallWatch(dq, 2);
			break;
		}
		case 12: {
			chosenSortingWallWatch(dq);
			break;
		}
		case 0: {
			return;
			break;
		}
		}
	}
}

void operationsBinaryWatch(Deque<BinaryWatch> dq)
{
	while (true) {
		outputMenu();
		BinaryWatch T;
		int number = RangeException::inputInt(cin, 0, 10);
		switch (number)
		{
		case 1: {
			addDequeTop(dq);
			break;
		}
		case 2: {
			addDequeBack(dq);
			break;
		}
		case 3: {
			popDequeTop(dq);
			break;
		}
		case 4: {
			popDequeTop(dq);
			break;
		}
		case 5: {
			dequeTop(dq, BINARY_WATCH);
			break;
		}
		case 6: {
			dequeBack(dq, BINARY_WATCH);
			break;
		}
		case 7: {
			dequeClear(dq);
			break;
		}
		case 8: {
			isDequeEmpty(dq);
			break;
		}
		case 9: {
			chosenBinaryWatch(dq, 1);
			break;
		}
		case 10: {
			showDeque(dq, BINARY_WATCH);
			break;
		}
		case 11: {
			chosenBinaryWatch(dq, 2);
			break;
		}
		case 12: {
			chosenSortingBinaryWatch(dq);
			break;
		}
		case 0: {
			return;
			break;
		}
		}
	}
}

