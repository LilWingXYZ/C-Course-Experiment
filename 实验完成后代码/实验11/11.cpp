#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<sstream>
#include<vector>
#include<math.h>


using namespace std;

class Shape {
public:
	virtual double getCircumference()=0;
	virtual void GetParameter()=0;
	bool operator >(Shape &shape);
	virtual void printToScreen()=0;
	virtual void printToFile()=0;
};

class Circle:public Shape {
public:
	void GetParameter (/*double radius*/);
	double getCircumference();
	Circle(double price,int radius=3):radius(radius),price(price){classId=1;};
	void printToScreen();
	void printToFile();
private:
	double radius;
	int classId;
	double price;
};

class RightAngle:public Shape {
public:
	void GetParameter (/*double rightAngle,double hypotenuse*/);
	double getCircumference();
	RightAngle(double price,int rightAngle1=3,int rightAngle2=3,int hypotenuse=3):rightAngle1(rightAngle1),rightAngle2(rightAngle2),hypotenuse(hypotenuse),price(price){classId=3;};
	void printToScreen();
	void printToFile();
private:
	double rightAngle1;
	double rightAngle2;
	double hypotenuse;
	int classId;
	double price;
};

class Rectangle:public Shape {
public:
	void GetParameter (/*double length,double width*/);
	double getCircumference();
	Rectangle(double price,int length=3,int width=3):length(length),width(width),price(price){classId=2;};
	Rectangle() {length=3;width=3,classId=2;};
	void printToScreen();
	void printToFile();
private:
	double length;
	double width;
	int classId;
	double price;
};

class Square:public Rectangle {
public:
	void GetParameter (/*double length,double width*/);
	double getCircumference();
	Square(double price,int length=3):length(length),price(price){classId=4;};
	void printToScreen();
	void printToFile();
private:
	double length;
	int classId;
	double price;
};

class FileNotFoundException:public runtime_error{
public:
	FileNotFoundException(const string &message):message(message),runtime_error(message){ };
	string &what (){return message;}
private:
	string message;
};

void Circle::printToFile() {
	ofstream out("Circle.dat",ios::binary);
	out.write(reinterpret_cast<char*>(this),sizeof(Circle));
	out.close();
}

void RightAngle::printToFile() {
	ofstream out("RightAngle.dat",ios::binary);
	out.write(reinterpret_cast<char*>(this),sizeof(RightAngle));
	out.close();
}

void Rectangle::printToFile() {
	ofstream out("Rectangle.dat",ios::binary);
	out.write(reinterpret_cast<char*>(this),sizeof(Rectangle));
	out.close();
}

void Square::printToFile() {
	ofstream out("Square.dat",ios::binary);
	out.write(reinterpret_cast<char*>(this),sizeof(Square));
	out.close();
}

void Square::printToScreen() {
	cout << "正方形: " << classId <<"Rectangle, "<< "length: " << length << " price: " << price <<endl;
}

void RightAngle::printToScreen() {
	cout << "直角三角形: "<< classId << "RightTriangle, " << "rightAngle1: " << rightAngle1 << " rightAngle2: " << rightAngle2 << " price: " << price <<endl;
}

void Rectangle::printToScreen () {
	cout<<"长方形: " << classId <<"Rectangle, "<< "length: " << length << " width: "<<width<< " price: " << price <<endl;
}

void Circle::printToScreen () {
	cout<<"圆: " << classId << "Circle, " << "radius: " << radius << " price: " << price <<endl;
}

double Square::getCircumference () {
	return (length*4);
}

void Square::GetParameter() {
	cout << "Please input the length of square";
	cin >> length;
}

bool Shape::operator > (Shape &shape) {
	if(getCircumference()>shape.getCircumference())
		return true;
	else
		return false;
}

double Circle::getCircumference() {
	return (3.14*radius*2);
}

double RightAngle::getCircumference() {
	hypotenuse=sqrt(rightAngle1*rightAngle1+rightAngle2*rightAngle2);
	return (rightAngle1+rightAngle2+hypotenuse);
}

double Rectangle::getCircumference() {
	return (length*2+width*2);
}
void Circle::GetParameter() {
	cout << "Please input the radius of circle:";
	cin >> radius;
}

void RightAngle::GetParameter() {
	cout << "Please input the rightAngles of RightAngle:";
	cin >>rightAngle1>>rightAngle2;
}

void Rectangle::GetParameter() {
	cout << "Please input the length and width of rectangle";
	cin >>length>>width;
}

double translate(char ch[]) {
	double price;
	int i=1;
	char get[3]="0";
	int j=0;
	
	while(get[2]==0) {
		if((ch[i]<='9'&&ch[i]>='0')||ch[i]=='.') {
			get[j] = ch[i];
			j++;
		}
		i++;
	}
	istringstream is(get);
	is >> price;
	return price;
}

int main() {
	char classId;
	int n=1;
	char get[100];
	vector<Shape*> shape(n);
	ifstream shapeIn;

	try {
		shapeIn.open("Shapes.txt");
		if(!shapeIn) throw FileNotFoundException("FileNotFoundException!");
	while(shapeIn.read(/*reinterpret_cast<char*>*/(&classId),sizeof(char))) {
		switch (classId) {
		case '1': shapeIn.getline(get,1024);
				  shape[n-1]=new Circle(translate(get));
				  shape[n-1]->printToFile();
				  break;
		case '2': shapeIn.getline(get,1024);
				  shape[n-1]=new Rectangle(translate(get));
				  shape[n-1]->printToFile();
				  break;
		case '3': shapeIn.getline(get,1024);
				  shape[n-1]=new RightAngle(translate(get));
				  shape[n-1]->printToFile();
				  break;
		case '4': shapeIn.getline(get,1024);
				  shape[n-1]=new Square(translate(get));
				  shape[n-1]->printToFile();
				  break;
		}
	shape.resize(n+1);
	n++;
	}
	for(n=0;(unsigned)n<shape.size()-1;n++)
		shape[n]->printToScreen();
	}catch (FileNotFoundException &e) {
		cout << e.what() << endl;
	}
	return 0;

}