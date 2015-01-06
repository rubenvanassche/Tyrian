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
	Vector(double x, double y);
	virtual ~Vector();

	double x;
	double y;
};

}

#endif /* LIBRARY_LIB_POINT_H_ */
