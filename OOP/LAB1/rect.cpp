//File: rect.cpp

#include <iostream>
#include <math.h>
#include "rect.h"

Rectangle::Rectangle(void){
	len = 10;
	wid = 10;
//	success = true;
}
Rectangle::Rectangle(int le, int wi){
    success = true;
	if(le>=0 && le<=20){
		len = le;
	} else{
		//cout<<"[ERROR] invalid length\n\n";
		success = false;
	}
	if(wi>=0 && wi<=20){
		wid = wi;
	} else{
		//cout<<"[ERROR] invalid length\n\n";
		success = false;
	}
}
Rectangle::~Rectangle(void){

}
void Rectangle::setLength(int newLen){
	if(newLen>=0 && newLen<=20) this->len = newLen;
}
void Rectangle::setWidth(int newWid){
		if(newWid>=0 && newWid<=20) this->wid = newWid;
}
int Rectangle::getLength(void){
	return this->len;
}
int Rectangle::getWidth(void){
	return this->wid;
}
int Rectangle::perimeter(void){
	return 2*(this->len + this->wid);
}
double Rectangle::diagonal(void){
    if(!this->success) return -1;
	return sqrt( pow(this->len,2) + pow(this->wid,2) );
}
int Rectangle::area(void){
    if(!this->success) return -1;
	return this->len * this->wid;
}
void Rectangle::display(void){
	if(this->success) std::cout<<"[ "<<this->len<<" x "<<this->wid<<" ]\n";
	else std::cout<<"invalid value";
}
int Rectangle::isSquare(void){
    if(!this->success){
        std::cout<<" \"invalid value\" ";
    } else{
        if(this->len == this->wid) return 1;
        return 0;
    }
}
void Rectangle::draw(char c){
    if(!this->success){
        std::cout<<"invalid value";
    }
	for(int i=1; i <= this->len; i++){
		for(int j=1; j <= this->wid; j++){
			std::cout<<c<<" ";
		}
		std::cout<<"\n";
	}
}
