// flyweight.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

using namespace std;
using namespace System;

ref class Shape abstract
{ 
public:
	Shape(void)	{;}		
	virtual void draw() = 0;  
};



ref class Rectangle : Shape
{  
public:
	Rectangle(void){;}
	~Rectangle(void){;}
	virtual void draw() override 
	{  
		Console::WriteLine("Shape: Rectangle"); 		
	}  

};


ref class Line : Shape
{  
public:
	Line(void){;}
	~Line(void){;}
	virtual void draw() override 
	{  
		Console::WriteLine("Shape: Line"); 		
	}  

};

ref class FlyweightFactory {
private:
	Line^       chachedLine;
	Rectangle^  cachedRectangle;
public:
	FlyweightFactory(){
		chachedLine = gcnew Line();
		cachedRectangle =  gcnew Rectangle();
		;}
	
	Shape^ getShape(String^  key){
		if(!key->CompareTo("Line"))
			return chachedLine;
		return cachedRectangle;
	}
};

int main(int argc, char** argv)
{

	FlyweightFactory^ mFlyweightFactory = gcnew FlyweightFactory();
	for(int ii=0; ii<10; ii++)
		mFlyweightFactory->getShape("Line")->draw();

	Console::ReadLine();
	return 0;
}

