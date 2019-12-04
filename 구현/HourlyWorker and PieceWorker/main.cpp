// 12.14 : Payroll-System Modification

#include <iostream>
#include <vector>
#include "Employee.h"
#include "HourlyWorker.h"
#include "PieceWorker.h"
using namespace std;

int main()
{
	vector<HourlyWorker> hrWorkers;
	vector<PieceWorker> piWorkers;
	
	hrWorkers.push_back({ "John", "Doe", "12345-54321", 150, 30 });
	hrWorkers.push_back({ "Hey", "You", "98765-56789", 200, 50 });
	hrWorkers.push_back({ "Papa", "Wow", "59217-48291", 50, 45 });
	piWorkers.push_back({ "Bad", "Man", "10001-90001", 100, 15 });
	piWorkers.push_back({ "Good", "Boy", "48232-91923", 50, 20 });
	piWorkers.push_back({ "Poi", "Boi", "23052-59210", 20, 100 });

	Employee* employeePtr;
	for (size_t i = 0; i < 3; i++)
	{
		employeePtr = &hrWorkers[i];
		cout << employeePtr->toString() << "\n\n";
	}
	for (size_t j = 0; j < 3; j++)
	{
		employeePtr = &piWorkers[j];
		cout << employeePtr->toString() << "\n\n";
	}
}