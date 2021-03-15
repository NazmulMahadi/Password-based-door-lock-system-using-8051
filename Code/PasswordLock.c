#include<reg51.h>
sbit r1=P1^0;
sbit r2=P1^1;
sbit r3=P1^2;
sbit r4=P1^3;
sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;

sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;

sbit motp=P3^3;
sbit motn=P3^4;

void lcdcmd(unsigned char);
void lcddat(unsigned char);
void lcddis(unsigned char *, unsigned char);
void delay();
void check();
unsigned char pwd[10];

void main()
	{
		unsigned int x;
		unsigned int d;
		lcdcmd(0x38);
		lcdcmd(0x01);
		lcdcmd(0x10);
		lcdcmd(0x0c);
		lcdcmd(0x80);
		lcddis("Password Lock System", 20);
		lcdcmd(0xc0);
		lcddis("CSE331", 6);
		lcdcmd(0x01);
		lcddis("Enter the password", 18);
		lcdcmd(0xc0);
		while(1)
		{
			r1=0;
			if(c1==0)
			{
				pwd[x]='1';
				for(d=1;d<8;d++)
					{
						delay();
					}
				lcddat('*');
				x=x+1;
			}
			if(c2==0)
			{
				pwd[x]='2';
				for(d=1;d<8;d++)
					{
						delay();
					}
				lcddat('*');
				x=x+1;
			}
			if(c3==0)
			{
				pwd[x]='3';
				for(d=1;d<8;d++)
					{
						delay();
					}
				lcddat('*');
				x=x+1;
			}
			r2=0;
			r1=1;
			if(c1==0)
			{
				pwd[x]='4';
				for(d=1;d<8;d++)
					{
						delay();
					}
				lcddat('*');
				x=x+1;
			}
			if(c2==0)
			{
				pwd[x]='5';
				for(d=1;d<8;d++)
					{
						delay();
					}
				lcddat('*');
				x=x+1;
			}
			if(c3==0)
			{
				pwd[x]='6';
				for(d=1;d<8;d++)
					{
						delay();
					}
				lcddat('*');
				x=x+1;
			}
			r3=0;
			r2=1;
			if(c1==0)
			{
				pwd[x]='7';
				for(d=1;d<8;d++)
					{
						delay();
					}
				lcddat('*');
				x=x+1;
			}
			if(c2==0)
			{
				pwd[x]='8';
				for(d=1;d<8;d++)
					{
						delay();
					}
				lcddat('*');
				x=x+1;
			}
			if(c3==0)
			{
				pwd[x]='9';
				for(d=1;d<8;d++)
					{
						delay();
					}
				lcddat('*');
				x=x+1;
			}
			r4=0;
			r3=1;
			if(c1==0)
			{
				pwd[x]='*';
				for(d=1;d<8;d++)
					{
						delay();
					}
				lcddat('*');
				x=x+1;
			}
			if(c2==0)
			{
				pwd[x]='0';
				for(d=1;d<8;d++)
					{
						delay();
					}
				lcddat('*');
				x=x+1;
			}
			if(c3==0)
			{
				check();
				for(d=1;d<8;d++)
					{
						delay();
					}
			}
			r4=1;
		}
	}
void check()
	{
		if(pwd[0]=='5'&&pwd[1]=='5'&&pwd[2]=='5')
		{
			unsigned int d;
			motp=1;
			motn=0;
			lcdcmd(0x01);
			lcddis("Password Correct!", 17);
			for(d=1;d<8;d++)
				{
					delay();
				}
		}
		else
			{
				lcdcmd(0x01);
				lcddis("Password Incorrect!", 19);
			}
	}
void lcdcmd(unsigned char val)
	{
		unsigned int d;
		P2=val;
		rs=0;
		rw=0;
		en=1;
		for(d=1;d<8;d++)
			{
				delay();
			}
		en=0;
	}
void lcddat(unsigned char dat)
	{
		unsigned int d;
		P2=dat;
		rs=1;
		rw=0;
		en=1;
		for(d=1;d<8;d++)
			{
				delay();
			}
		en=0;
	}
void lcddis(unsigned char *s, unsigned char r)
	{
		unsigned int d;
		unsigned char i;
		for(i=0;i<r;i++)
			{
				lcddat(s[i]);
				for(d=1;d<8;d++)
					{
						delay();
					}
			}
	}
void delay()
	{
		unsigned int i,j;
		for(i=0;i<4000;i++);
		for(j=0;j<100;j++);
	}

