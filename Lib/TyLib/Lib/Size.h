/*
 * Size.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_LIB_SIZE_H_
#define LIBRARY_LIB_SIZE_H_
namespace tyLib{

class Size {
public:
	Size();
	Size(int width, int height);
	virtual ~Size();

	int width;
	int height;
};

}

#endif /* LIBRARY_LIB_SIZE_H_ */
