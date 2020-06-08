#include <REGX51.H>
//#include<reg51.h>
sbit r1 = P1^0;
sbit r2 = P1^1;
sbit r3 = P1^2;
sbit r4 = P1^3;
sbit c1 = P1^4;
sbit c2 = P1^5;
sbit c3 = P1^6;
sbit button = P3^4;
unsigned char SEG[11] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
unsigned char LED[3] = {0xBD,0x7E,0xFF};

int dau = 0;
int cuoi = 0;
int i;
void delay(unsigned int time)
{
	while(time--);
}

void thangmaydilen(int dau, int cuoi)
{
	int i;
	for(i = dau; i < cuoi; i++)
	{
			P0 = LED[0];//dèn xanh se sáng thông báo thang máy dang di lên
			P2=SEG[i];//den 7 thanh tang dan theo giá tri cua i
			delay(50000);//thoi gian delay
			delay(50000);
	}
}

void thangmaydixuong(int dau, int cuoi)
{
	int i;
	for(i = dau; i > cuoi; i--)
	{
			P0 = LED[1];//dèn do se sáng thông báo thang máy dang di xuóng
			P2=SEG[i];//den 7 thanh giam dan theo giá tri cua i
			delay(50000);//thoi gian delay
			delay(50000);
	}
}

int main()
{
	
	P2 = SEG[1];
	dau = 1;
	while(1)
{
	r1=0;
	if(c1==0)//tang 1
		{
		cuoi = 1;
		thangmaydixuong(dau,1);
		P0 = LED[2];
		P2=SEG[1];
		dau = 1;
	}
	
	if(c2==0)//tang 2
		{
		cuoi = 2;
		if(cuoi>dau)
			thangmaydilen(dau,2);
		else
			thangmaydixuong(dau,2);
		P0 = LED[2];
		P2=SEG[2];
		dau = 2;
	}

	if(c3==0)//tang 3
		{
		//cuoi = 3;
		if(dau<3)
			thangmaydilen(dau,3);
		else
			thangmaydixuong(dau,3);
		P0 = LED[2];
		P2=SEG[3];
		dau = 3;
	}
		
	r1=1;r2=0;
	if(c1==0)//tang 4
		{
		//cuoi = 4;
		if(dau<4)
			thangmaydilen(dau,4);
		else
			thangmaydixuong(dau,4);
		P0 = LED[2];
		P2=SEG[4];
		dau = 4;
	}
		
	
	
	if(c2==0)//tang 5
		{
		//cuoi = 5;
		if(dau<5)
			thangmaydilen(dau,5);
		else
			thangmaydixuong(dau,5);
		P0 = LED[2];
		P2=SEG[5];
		dau = 5;
	}
		
	if(c3==0)//tang 6
		{
		//cuoi = 6;
		if(dau<6)
			thangmaydilen(dau,6);
		else
			thangmaydixuong(dau,6);
		P0 = LED[2];
		P2=SEG[6];
		dau = 6;
	}
		
	r2=1;r3=0;
	if(c1==0)//tang 7
		{
		//cuoi = 7;
		if(dau<7)
			thangmaydilen(dau,7);
		else
			thangmaydixuong(dau,7);
		P0 = LED[2];
		P2=SEG[7];
		dau = 7;
	}
		
	
	if(c2==0)//tang 8
		{
		//cuoi = 8;
		if(dau<8)
			thangmaydilen(dau,8);
		else
			thangmaydixuong(dau,8);
		P0 = LED[2];
		P2=SEG[8];
		dau = 8;
	}
		
	if(c3==0)//tang 9
		{
		//cuoi = 9;
		if(dau<9)
			thangmaydilen(dau,9);
		else
			thangmaydixuong(dau,9);
		P0 = LED[2];
		P2=SEG[9];
		dau = 9;
	}
		if(button == 0){
			cuoi = 5;
		}
	
	r3=1;r4=0;
}
	



}