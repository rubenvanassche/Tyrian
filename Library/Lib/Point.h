/*
 * Point.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_LIB_POINT_H_
#define LIBRARY_LIB_POINT_H_

namespace tyLib{

class Vector {
public:
	Vector();
	Vector(double const x, double const y);
	Vector operator+(Vector const other);
	Vector operator/(Vector const other);
	Vector operator-(Vector const other);
	Vector operator*(Vector const other);
	Vector operator*(double const scalar);
	Vector operator*(int const scalar);
	bool operator==(Vector const other) const;
	bool operator>(Vector const other) const;
	bool operator<(Vector const other) const;
	virtual ~Vector();

	double x;
	double y;
};

}

#endif /* LIBRARY_LIB_POINT_H_ */
