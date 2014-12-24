/*
 * Point.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_LIB_POINT_H_
#define LIBRARY_LIB_POINT_H_

class Point {
public:
	Point();
	Point(double x, double y);
	virtual ~Point();

	double x;
	double y;
};

#endif /* LIBRARY_LIB_POINT_H_ */
