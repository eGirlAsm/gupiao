// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
int main()
{

	FILE *f;
	fopen_s(&f, "file30bei.txt", "w");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		return 1;
	}

	const int myInitialMoney = 1562500; //�ҵ��ʱ�
	const int TheBuyPrice = 220500;//ÿ������۸�
	const int TheSellPrice = 286650;// 30 %// 231000;//ÿ�������۸�

	int MyTotalMoney = myInitialMoney;
	fprintf(f,"��ʼ�ʽ�Ϊ %d\r\n", MyTotalMoney);

	int nTotalCount = 0; //�ܹ������˶��ٴ�Ͷ�ʡ�


	int bDoubleBenefitMoney = myInitialMoney;



start:

	

	int nMoneybefore = MyTotalMoney; //Ͷ��֮ǰ ӵ�е��ʱ�
	fprintf(f,"Ͷ��ǰӵ�е��ʱ� %d\r\n",nMoneybefore);
	int RemainedMoney = MyTotalMoney % TheBuyPrice;  // �����Ʊ ʣ������Ǯ
	int canBuyCount = (MyTotalMoney - RemainedMoney) / TheBuyPrice; //ÿ������Ĺ���
	int That_i_bought = TheBuyPrice * canBuyCount;//���� ��Ʊ ����ȥ��Ǯ

	nTotalCount++;

	//....��Ʊ���� 4.76%
	MyTotalMoney = TheSellPrice * canBuyCount + RemainedMoney;

	fprintf(f,"(%d) ���Ͷ�ʻ�����%d ��Ԫ �ܻ���: %d ��Ԫ\r\n",nTotalCount, MyTotalMoney - nMoneybefore, MyTotalMoney - myInitialMoney);

	if ((MyTotalMoney / bDoubleBenefitMoney) >= 2) {
		
		fprintf(f,"\r\n��ϲ�� ����ʲ��ѷ���\r\n ԭ�����ʱ� %d,�����ʱ� %d\r\n\r\n",bDoubleBenefitMoney,MyTotalMoney);
		bDoubleBenefitMoney = MyTotalMoney;
	}
		

	fprintf(f,"��ǰ�ʽ� %d,��� %d ��,ʣ���ʽ� %d \r\n", MyTotalMoney, canBuyCount, RemainedMoney);

	if (MyTotalMoney >= 100000000) //����һ�ں�Ԫ,�ͽ����� һ�ں�Ԫ �൱�� �����60��
		goto end;
	
	// keep going
	goto start;
	
end:
	fclose(f);
	printf("Congratulations you got the free life!");
	_getch();
    return 0;
}

