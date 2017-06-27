// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
int main()
{
	const int myInitialMoney = 1562500; //我的资本
	const int TheBuyPrice = 220500;//每次买入价格
	const int TheSellPrice = 231000;//每次卖出价格

	int MyTotalMoney = myInitialMoney;
	printf("初始资金为 %d\r\n", MyTotalMoney);

	int nTotalCount = 0; //总共进行了多少次投资。


	int bDoubleBenefitMoney = myInitialMoney;

start:

	

	int nMoneybefore = MyTotalMoney; //投资之前 拥有的资本
	printf("投资前拥有的资本 %d\r\n",nMoneybefore);
	int RemainedMoney = MyTotalMoney % TheBuyPrice;  // 买完股票 剩下来的钱
	int canBuyCount = (MyTotalMoney - RemainedMoney) / TheBuyPrice; //每次能买的股数
	int That_i_bought = TheBuyPrice * canBuyCount;//买了 股票 花出去的钱

	nTotalCount++;

	//....股票上涨 4.76%
	MyTotalMoney = TheSellPrice * canBuyCount + RemainedMoney;

	printf("(%d) 这次投资获利：%d 韩元 总获利: %d 韩元\r\n",nTotalCount, MyTotalMoney - nMoneybefore, MyTotalMoney - myInitialMoney);

	if ((MyTotalMoney / bDoubleBenefitMoney) >= 2) {
		
		printf("\r\n恭喜你 你的资产已翻倍\r\n 原来的资本 %d,现在资本 %d\r\n\r\n",bDoubleBenefitMoney,MyTotalMoney);
		bDoubleBenefitMoney = MyTotalMoney;
	}
		

	printf("当前资金 %d,买进 %d 股,剩余资金 %d \r\n", MyTotalMoney, canBuyCount, RemainedMoney);

	if (MyTotalMoney >= 100000000) //到了一亿韩元,就结束。 一亿韩元 相当于 人民币60万
		goto end;
	
	// keep going
	goto start;
	
end:
	printf("Congratulations you got the free life!");
	_getch();
    return 0;
}

