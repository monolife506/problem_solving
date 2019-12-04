#pragma once
#include <string>
#include "Employee.h"

class PieceWorker : public Employee
{
public:
	PieceWorker(const std::string&, const std::string&, const std::string&,
		double, unsigned int);
	virtual ~PieceWorker() = default;

	void setWage(double);
	double getWage() const;

	void setPieces(unsigned int);
	unsigned int getPieces() const;

	virtual double earnings() const override;
	virtual std::string toString() const override;
private:
	double wage;
	unsigned int pieces;
};