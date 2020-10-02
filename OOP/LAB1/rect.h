//File: rect.h

#ifndef _RECT_H
#define _RECT_H
class Rectangle{
	private:
		int len;				//dai
		int wid;				//rong
		bool success = true;
	public:
		Rectangle(void);
		Rectangle(int, int);
		void setLength(int);
		void setWidth(int);
		int getLength(void);
		int getWidth(void);
		int perimeter(void);	//chuvi
		double diagonal(void);	//duongcheo
		int area(void);			//dientich
		void display(void);
		int isSquare(void);
		void draw(char);
		~Rectangle(void);
};
#endif

