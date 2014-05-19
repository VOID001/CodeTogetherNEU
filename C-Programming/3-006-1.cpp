//3-006 Friend 友元
//这是友元函数 
class CCar;
class CDriver{
public:
	void ModifyCar(CCar *pCar)
};

class CCar{
private:
	int price;
	friend int MostExpensiveCar(CCar cars[], int total);	//友元函数 声明在CCar类中 可以使用CCar 类的私有成员
	friend void CDriver::ModifyCar(CCar *pCar);				//友元函数 声明在CCar类中 可以使用CCar 类的私有成员
};

void CDriver::ModifyCar(CCar *pCar)
{
	pCar->price += 1000;
}

int MostExpensiveCar(CCar cars[], int total)
{
	int tmpMax = -1;										//初始化最大值存放的临时变量
	for (int i = 0; i < total; i++)
	{
		if (cars[i].price>tmpMax)
			tmpMax = cars[i].price;
	}
	return tmpMax;
}

int main(void)
{
	return 0;
}
