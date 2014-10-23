/*************************************************************************
    > File Name: testwll.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年07月10日 星期四 09时05分05秒
 ************************************************************************/
#include<iostream>
using namespace std;

class Vehicle{
	public:
		double maxSpeed;
		double weight;
		Vehicle(double a=1.1,double b=2.2);
		void run(){cout<<"Vehicle Running"<<endl;}
		void stop(){cout<<"Vehicle Stopping"<<endl;}
};

Vehicle::Vehicle(double a,double b)
{
	maxSpeed=a;
	weight=b;
	cout<<"Vehicle MaxSpeed is "<<maxSpeed<<endl;
	cout<<"Vehicle weight is "<<weight<<endl;
}

class Bicycle:virtual public Vehicle{
	public:
		Bicycle(double c);
		double height;
};

Bicycle::Bicycle(double c)
{
	height=c;
	cout <<"Bicycle Height is " << height<<endl;
}

class MotorCar:virtual public Vehicle{
	public:
		MotorCar(int d);
		int seats;
};

MotorCar::MotorCar(int d)
{
	seats=d;
	cout<<"MotorCar Seats num is "<< seats<<endl;
}

class MotorBicycle:public MotorCar,public Bicycle{
	public:
		MotorBicycle(double a,double b,double c,int d):Vehicle(a,b),MotorCar(d),Bicycle(c){}
		MotorBicycle(const Vehicle& v,const MotorCar& mt,const Bicycle& bc):Vehicle(v),MotorCar(mt),Bicycle(bc){}
};

int main(void)
{
	Vehicle v(2.5,10.9);
	Bicycle b(1.9);
	MotorCar mtc(4);
	MotorBicycle mb1(v,mtc,b);
	MotorBicycle(2.5,10.9,1.9,4);
	return 0;
}
