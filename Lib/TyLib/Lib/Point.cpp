/*
 * Point.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "Point.h"

namespace tyLib{

Vector::Vector(){

}

Vector::Vector(double x, double y) {
	this->x = x;
	this->y = y;
}

Vector Vector::operator+(Vector other){
	Vector back;
	back.x = other.x + this->x;
	back.y = other.y + this->y;
	return back;
}

Vector Vector::operator/(Vector other){
	Vector back;
	back.x = other.x / this->x;
	back.y = other.y / this->y;
	return back;
}

Vector Vector::operator-(Vector other){
	Vector back;
	back.x = other.x - this->x;
	back.y = other.y - this->y;
	return back;
}

Vector Vector::operator*(Vector other){
	Vector back;
	back.x = other.x * this->x;
	back.y = other.y * this->y;
	return back;
}

Vector Vector::operator*(double scalar){
	Vector back;
	back.x = this->x*scalar;
	back.y = this->y*scalar;
	return back;
}

Vector Vector::operator*(int scalar){
	Vector back;
	back.x = this->x*scalar;
	back.y = this->y*scalar;
	return back;
}

bool Vector::operator==(Vector other){
	if(other.x == this->x and other.y == this->y){
		return true;
	}else{
		return false;
	}
}
bool Vector::operator>(Vector other){
	double productMe = this->x*this->x + this->y*this->y;
	double productOther = other.x*other.x + other.y*other.y;

	return productMe > productOther;
}
bool Vector::operator<(Vector other){
	double productMe = this->x*this->x + this->y*this->y;
	double productOther = other.x*other.x + other.y*other.y;

	return productMe < productOther;
}

Vector::~Vector() {
	// TODO Auto-generated destructor stub
}

}
