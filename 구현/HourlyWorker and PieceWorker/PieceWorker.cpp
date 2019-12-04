#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "PieceWorker.h"
using namespace std;

PieceWorker::PieceWorker(const string& first, const string& last, const string& ssn,
	double wg, unsigned int piece) : Employee(first, last, ssn) {
	setWage(wg); setPieces(piece);
}

void PieceWorker::setWage(double wg)
{
	if (wg < 0.0)
		throw invalid_argument("Wage must be >= 0.0");
	wage = wg;
}

double PieceWorker::getWage() const { return wage; }

void PieceWorker::setPieces(unsigned int piece)
{
	if (piece < 0)
		throw invalid_argument("Piece must be >= 0");
	pieces = piece;
}

unsigned int PieceWorker::getPieces() const { return pieces; }

double PieceWorker::earnings() const
{
	return getWage() * getPieces();
}

string PieceWorker::toString() const
{
	ostringstream output;
	output << fixed << setprecision(2);
	output << "Hourly Worker: "
		<< Employee::toString()
		<< "\nmade pieces: " << getPieces()
		<< "\nwage per pieces: " << getWage()
		<< "\nearnings: " << earnings();
	return output.str();
}