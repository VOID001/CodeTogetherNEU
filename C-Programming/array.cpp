/*************************************************************************
    > File Name: array.cpp
    > Author: VOID_133
    > QQ: 393952764
    > Mail: zhangjianqiu13@gmail.com 
    > Created Time: 2014年07月03日 星期四 09时43分39秒
 ************************************************************************/
#include<iostream>
#include<string>

using namespace std;

class Worker{
	public:
		string name;
		int time_payment;
	public:
		virtual int compute_pay(int hours)=0;
		Worker(const string& nm,int pay):name(nm),time_payment(pay){}
};

class HourlyWorker :public Worker{
	public:
		virtual int compute_pay(int hours);
		HourlyWorker(const string& nm,int pay):Worker(nm,pay){}
		virtual ~HourlyWorker(){}
};

class SalariedWorker:public Worker{
	public:
		virtual int compute_pay(int hours);
		SalariedWorker(const string& nm,int pay):Worker(nm,pay){}
		virtual ~SalariedWorker(){}
};

int HourlyWorker::compute_pay(int hours)
{
	if(hours<=40) return hours*time_payment;
	else if(hours>40) return 40*time_payment+(hours-40)*1.5*time_payment;
}

int SalariedWorker::compute_pay(int hours)
{
	return 40*time_payment;
}

int main(void)
{
	int pay;
	HourlyWorker workerA("Max",10);
	SalariedWorker workerB("Pig",15);
	Worker* pWorker;
	pWorker=&workerA;
	pay=pWorker->compute_pay(30);
	cout<<pay<<endl;
	pWorker=&workerB;
	pay=pWorker->compute_pay(30);
	cout<<pay<<endl;
	return 0;
}

