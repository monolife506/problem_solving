#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "HourlyWorker.h"
using namespace std;

HourlyWorker::HourlyWorker(const string& first, const string& last, const string& ssn,
	double wg, double hr) : Employee(first, last, ssn) {
	setWage(wg); setHours(hr);
}

void HourlyWorker::setWage(double wg)
{
	if (wg < 0.0) 
		throw invalid_argument("Wage must be >= 0.0");
	wage = wg;
}

double HourlyWorker::getWage() const { return wage; }

void HourlyWorker::setHours(double hr)
{
	if (hr < 0.0) 
		throw invalid_argument("Hour must be >= 0.0");
	hours = hr;
}

double HourlyWorker::getHours() const { return hours; }

double HourlyWorker::earnings() const
{
	if (getHours() > 40) 
		return ((getHours() - 40) * getWage() * 1.5) + (40 * getWage());
	else 
		return getHours() * getWage();
}

string HourlyWorker::toString() const
{
	ostringstream output;
	output << fixed << setprecision(2);
	output << "Hourly Worker: "
		<< Employee::toString()
		<< "\nworking hours: " << getHours()
		<< "\nwage per hours: " << getWage()
		<< "\nearnings: " << earnings();
	return output.str();
}