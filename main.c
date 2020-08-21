
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <usart.h>
#include <avr/eeprom.h>
int adc_read(int );
void lcd_cmd(int);
void lcd_data(int);
void lcd_init(void);
void clrscr(void);
void lcd_num(int );
void lcd_string(char*);
int scanning_data(void);
void operation(int ,int);
void addition(int,int);
void subtraction(int,int);
void multiplication(int,int);
int keypad(void);
void custom_character(void);
void custom_character1(void);
void obstacle(void);
void game(void);
int  music(void);
void password_change(void);
void contacts(void);
void messages(void);
void calculator(void);
void sa_re_ga(void);
void namokar_mantra(void);
void vande_matram(void);
int early_keypad(void);
void existing_contacts(void);
int new_contact(int);
void delete_contact(void);
long long int  i;
int main(void)
{	
	DDRA =0;
	PORTA=0xff;
	DDRD=0;
	DDRB =0xff;
	DDRC =0b11101111;
	usart_init();
	_delay_ms(100);
	lcd_init();
	_delay_ms(100);
	int m,s=0,w,t=0,a,b,c,d,e,f,kk;
	int aa;
	int g=1,h=0;
	int v[10];
	char aaa[4]={'1','2','3','4'};
	for( w=0;w<4;w++)
	{
		eeprom_write_byte(w,aaa[w]);
	}
	aaa[4]='\0';
	_delay_ms(1000);
	int j;
	int p;
	int k=6;
	int mm,n;
	char ab[]="Ishika";
	char aab[]="9057880344";
	char bb[]="Mumma";
	char bbb[]="9887225374";
	char cb[]="Dad";
	char ccb[]="9887224250";
	char ch;
	j=0;
	eeprom_write_byte(k,'*');
	k=k+1;
	for( p=k;ab[j]!='\0';p++)
	{
		eeprom_write_byte(p,ab[j]);
		j++;
		k=k+1;
	}
	eeprom_write_byte(k,'*');
	k=k+1;
	j=0;
	for(p=k ;aab[j]!='\0';p++)
	{
		eeprom_write_byte(p,aab[j]);
		j++;
		k=k+1;
	}
	j=0;
	eeprom_write_byte(k,'*');
	k=k+1;
	for(p=k ;bb[j]!='\0';p++)
	{
		eeprom_write_byte(p,bb[j]);
		j++;
		k=k+1;
	}
	eeprom_write_byte(k,'*');
	k=k+1;
	j=0;
	for(p=k ;bbb[j]!='\0';p++)
	{
		eeprom_write_byte(p,bbb[j]);
		j++;
		k=k+1;
	}
	j=0;
	eeprom_write_byte(k,'*');
	k=k+1;
	for(p=k ;cb[j]!='\0';p++)
	{
		eeprom_write_byte(p,cb[j]);
		j++;
		k=k+1;
	}
	eeprom_write_byte(k,'*');
	k=k+1;
	j=0;
	for(p=k ;ccb[j]!='\0';p++)
	{
		eeprom_write_byte(p,ccb[j]);
		j++;
		k=k+1;
	}
	eeprom_write_byte(k,'*');
	k=k+1;
	_delay_ms(1000);
	clrscr();
	 while (1) 
    {	
		for( i=0;i<60*9*60;i++)
		{
			if(i%3600==0)
			m=0;
			else
			m++;
			a=(i/(60*60))/10;
			b=(i/(60*60))%10;
			c=(m/60)/10;
			d=(m/60)%10;
			e=(i%60)/10;
			f=(i%60)%10;
			lcd_cmd(0x84);
			lcd_num(a);
			lcd_cmd(0x85);
			lcd_num(b);
			lcd_cmd(0x86);
			lcd_data(':');
			lcd_cmd(0x87);
			lcd_num(c);
			lcd_cmd(0x88);
			lcd_num(d);
			lcd_cmd(0x89);
			lcd_data(':');
			lcd_cmd(0x8a);
			lcd_num(e);
			lcd_cmd(0x8b);
			lcd_num(f);
			_delay_ms(1000);
			clrscr();
			if(PIND==1)
			{
				for(int j=0;j<4;j++)
				{
					aa=keypad();
					lcd_cmd(0x85);
					lcd_num(aa);
					_delay_ms(100);
					if(aa+48==eeprom_read_byte(j))
					{
						if(j==3)
						{	
							lcd_string("correct password");
							_delay_ms(2000);
							i=i+1;
							s=1;
							_delay_ms(3000);
							clrscr();
							lcd_cmd(0x85);
							clrscr();
							lcd_num(s);
							_delay_ms(2000);
							break;
						}
						i=i+1;
						continue;
					}
					else
					{
						lcd_string("incorrect password");
						_delay_ms(1000);
						i=i+1;
						break;
					}
				}
				while(s==1)
				{	
					PORTC=0;
					while(PIND==0&&PINC!=16);
					i=i+1;
					if(PIND==1)//settings option
					{
						while(PIND==1);
						clrscr();
						lcd_string_num("music",0x80);
						lcd_string_num("games",0xc0);
						while(1)
						{
							while(PIND==0);
							if(PIND==2)
							{
								if(g>1)
								{
									while(PIND==2);
									if(g!=1)
									{
										g=g-1;
									}
									clrscr();
									lcd_cmd(0x85);
									lcd_num(g);
									h=1;
								}
							}
							if(PIND==4)
							{
								while(PIND==4);
								if(g<=5)
								g=g+1;
								clrscr();
								lcd_cmd(0x85);
								lcd_num(g);
								h=1;
							}
							if(PIND==32)
							{
								h=1;
								t=1;
							}
							if(PIND==64)
							{
								break;
							}
							if(h==1)
							{
								if(g==1&&t==0)
								{
									lcd_string_num("music",0x80);
									lcd_string_num("games",0xc0);
									h=0;
								}
								if(g==2&&t==0)
								{
									lcd_string_num("games",0x80);
									lcd_string_num("password change",0xc0);
									h=0;
								}
								if(g==3&&t==0)
								{
									lcd_string_num("password change",0x80);
									lcd_string_num("calculator",0xc0);
									h=0;
								}
								if(g==4&&t==0)
								{
									lcd_string_num("calculator",0x80);
									lcd_string_num("contacts",0xc0);
									h=0;
								}
								if(g==5&&t==0)
								{
									lcd_string_num("contacts",0x80);
									lcd_string_num("messages",0xc0);
									h=0;
								}
								if(g==6&&t==0)
								{
									lcd_string_num("messages",0x80);
									h=0;
								}
								if(g==1&&t==1)
								{
									lcd_string_num("music",0x80);
									_delay_ms(1500);
									int hj=music();
									clrscr();
									if(hj==1)
									{
										break;
									}
									lcd_string_num("music",0x80);
									lcd_string_num("games",0xc0);
									t=0;
									h=0;
								}
								if(g==2&&t==1)
								{
									lcd_string_num("games",0x80);
									game();
									lcd_string_num("games",0x80);
									lcd_string_num("password change",0xc0);
									h=0;
									h=0;
									t=0;
								}
								if(g==3&&t==1)
								{
									lcd_string_num("password change",0x80);
									password_change();
									lcd_string_num("password change",0x80);
									lcd_string_num("calculator",0xc0);
									h=0;
									t=0;
								}
								if(g==4&&t==1)
								{
									lcd_string_num("calculator",0x80);
									//calculator();
									lcd_string_num("calculator",0x80);
									lcd_string_num("contacts",0xc0);
									h=0;
									t=0;
								}
								if(g==5&&t==1)
								{
									lcd_string_num("contacts",0x80);
									_delay_ms(2500);
									int gg=1;
									int hh=0;
									int tt=0;
									clrscr();
									lcd_string_num("existing contact",0x80);
									lcd_string_num("new contact",0xc0);
									while(1)
									{
										while(PIND==0);
										if(PIND==2)
										{
											if(gg>1)
											{
												while(PIND==2);
												if(gg!=1)
												{
													gg=gg-1;
												}
												clrscr();
												lcd_cmd(0x85);
												lcd_num(gg);
												hh=1;
											}
										}
										if(PIND==4)
										{
											while(PIND==4);
											if(gg<=2)
											gg=gg+1;
											clrscr();
											lcd_cmd(0x85);
											lcd_num(gg);
											hh=1;
										}
										if(PIND==32)
										{
											hh=1;
											tt=1;
										}
										if(PIND==64)
										{
											break;
										}
										if(hh==1)
										{
											if(gg==1&&tt==0)
											{
												lcd_string_num("existing contact",0x80);
												lcd_string_num("new contact",0xc0);
												hh=0;
											}
											if(gg==2&&tt==0)
											{
												lcd_string_num("new contact",0x80);
												lcd_string_num("delete contact",0xc0);
												hh=0;
											}
											if(gg==3&&tt==0)
											{
												lcd_string_num("delete contact",0x80);
												hh=0;
											}
											if(gg==1&&tt==1)
											{
												lcd_string_num("existing contact",0x80);
												existing_contacts();
												hh=0;
											}
											if(gg==2&&tt==1)
											{
												lcd_string_num("new contact",0x80);
												mm=new_contact(k);
												k=mm;
												_delay_ms(2000);
												hh=0;
												tt=0;
											}
											if(gg==3&&tt==1)
											{
												lcd_string_num("delete contact",0x80);
												delete_contact();
												hh=0;
												tt=0;
											}
										}
									}
									lcd_string_num("contacts",0x80);
									lcd_string_num("messages",0xc0);
									h=0;
									t=0;
								}
								if(g==6&&t==1)
								{
									lcd_string_num("messages",0x80);
									//messages();
									h=0;
									t=0;
								}
							}
						}
					}
					//if(1)
					if(PINC==16)
					{	//calling
						//char ch=usart_rec();
						//usart_send(ch);
						clrscr();
						lcd_string("enter the number");
						_delay_ms(2000);
						clrscr();
						lcd_cmd(0x80);
						for(kk=0;kk<10;kk++)
						{
							v[kk]=keypad();
							lcd_data('v[kk]');
							_delay_ms(100);							
						}
						if(PINC==16)
						{
							//usart_send('A');
							//usart_send('T');
							//usart_send('D');
							/*for(kk=0;kk<10;kk++)
							{
								//usart_send('v[k]');
							}*/
							//usart_send(';');
							//usart_send(13);
							//_delay_ms(100);
						}
						lcd_cmd(0xc0);
						clrscr();
						lcd_string("DIALLING...");
						_delay_ms(100);
					}
					if(PIND==64)
					{	
						break;
					}
					if(PIND==128)
					{
						break;	
					}
					if(PIND==32)
					{	
						clrscr();
						lcd_string_num("existing contact",0x80);
						_delay_ms(1500);
						existing_contacts();
					}
				}
			}
		}
	}
}
void existing_contacts(void)
{	
	int gg=1;
	int hh=0;
	int tt=0;
	int kl=7;
	int ifg;
	clrscr();
	char ch=eeprom_read_byte(kl);
	lcd_cmd(0x80);
	for( ifg=kl;ch!='*';ifg++)
	{
		ch=eeprom_read_byte(ifg);
		lcd_data(ch);
		if(PIND==64||PIND==128)
		return;
	}
	kl=ifg;
	lcd_cmd(0xc0);
	ch=eeprom_read_byte(ifg);
	for( ifg=kl;ch!='*';ifg++)
	{
		ch=eeprom_read_byte(ifg);
		lcd_data(ch);
		if(PIND==64||PIND==128)
		return;
	}
	kl=ifg;
	while(1)
	{
		while(PIND==0);
		if(PIND==2)
		{
			while(PIND==2);
			if(hh>=1)
			{	lcd_string("hello");
				//clrcsr();
				kl=kl-2;
				while((eeprom_read_byte(kl))!='*')
				{
					kl--;
				}
				kl=kl-1;
				while((eeprom_read_byte(kl))!='*')
				{
					kl--;
				}
				kl=kl-1;
				while((eeprom_read_byte(kl))!='*')
				{
					kl--;
				}
				kl=kl-1;
				while((eeprom_read_byte(kl))!='*')
				{
					kl--;
				}
				kl=kl+1;
				ch=eeprom_read_byte(kl);
				lcd_cmd(0x80);
				for( ifg=kl;ch!='*';ifg++)
				{
					ch=eeprom_read_byte(ifg);
					lcd_data(ch);
				}
				kl=ifg;
				lcd_cmd(0xc0);
				ch=eeprom_read_byte(ifg);
				for( ifg=kl;ch!='*';ifg++)
				{
					ch=eeprom_read_byte(ifg);
					lcd_data(ch);
				}
				kl=ifg;
				hh=hh-1;
			}
		}
		if(PIND==4)
		{	
			//clrscr();
			hh=hh+1;
			while(PIND==4);
			lcd_cmd(0x80);
			ch=eeprom_read_byte(kl);
			for( ifg=kl;ch!='*';ifg++)
			{
				ch=eeprom_read_byte(ifg);
				lcd_data(ch);
			}
			kl=ifg;
			lcd_cmd(0xc0);
			ch=eeprom_read_byte(ifg);
			for( ifg=kl;ch!='*';ifg++)
			{
				ch=eeprom_read_byte(ifg);
				lcd_data(ch);
			}
			kl=ifg;
			lcd_cmd(0x85);
		}
		if(PIND==128)
		{
			break;
		}
		if(PIND==64)
		break;
	}
}
void delete_contact(void)
{
	 int gg=1;
	 int hh=0;
	 int tt=0;
	 int kl=7;
	 int ipp;
	 char ch=eeprom_read_byte(kl);
	 clrscr();
	 lcd_cmd(0x80);
	 for( ipp=kl;ch!='*';ipp++)
	 {
		 ch=eeprom_read_byte(ipp);
		 lcd_data(ch);
	 }
	 kl=ipp;
	 lcd_cmd(0xc0);
	 ch=eeprom_read_byte(ipp);
	 for( ipp=kl;ch!='*';ipp++)
	 {
		 ch=eeprom_read_byte(ipp);
		 lcd_data(ch);
	 }
	 kl=ipp;
	 while(1)
	 {
		 while(PIND==0);
		 if(PIND==2)
		 {
			 while(PIND==2);
			 if(hh>=1)
			 {	//lcd_string("hello");
				 kl=kl-2;
				 while((eeprom_read_byte(kl))!='*')
				 {
					 kl--;
				 }
				 kl=kl-1;
				 while((eeprom_read_byte(kl))!='*')
				 {
					 kl--;
				 }
				 kl=kl-1;
				 while((eeprom_read_byte(kl))!='*')
				 {
					 kl--;
				 }
				 kl=kl-1;
				 while((eeprom_read_byte(kl))!='*')
				 {
					 kl--;
				 }
				 kl=kl+1;
				 ch=eeprom_read_byte(kl);
				 lcd_cmd(0x80);
				 for( ipp=kl;ch!='*';i++)
				 {
					 // eeprom_write_byte(i,' ');
					 ch=eeprom_read_byte(ipp);
					 lcd_data(ch);
				 }
				 kl=ipp;
				 lcd_cmd(0xc0);
				 ch=eeprom_read_byte(ipp);
				 for( ipp=kl;ch!='*';ipp++)
				 {
					 // eeprom_write_byte(i,' ');
					 ch=eeprom_read_byte(ipp);
					 lcd_data(ch);
				 }
				 kl=ipp;
				 hh=hh-1;
			 }
		 }
		 if(PIND==4)
		 {	
			 hh=hh+1;
			 while(PIND==4);
			 lcd_cmd(0x80);
			 ch=eeprom_read_byte(kl);
			 for( ipp=kl;ch!='*';ipp++)
			 {
				 ch=eeprom_read_byte(ipp);
				 lcd_data(ch);
			 }
			 kl=ipp;
			 lcd_cmd(0xc0);
			 ch=eeprom_read_byte(ipp);
			 for( ipp=kl;ch!='*';ipp++)
			 {
				 ch=eeprom_read_byte(ipp);
				 lcd_data(ch);
			 }
			 kl=ipp;
			 lcd_cmd(0x85);
		 }
		 if(PIND==32)
		 {
			 while(PIND==32);
			 clrscr();
			 lcd_string("Delete contact?");
			 while(1)
			 {
				 if(PIND==32)
				 {		clrscr();
					 while(PIND==32);
					 kl=kl-2;
					 while((eeprom_read_byte(kl))!='*')
					 {
						 kl--;
					 }
					 kl=kl-1;
					 while((eeprom_read_byte(kl))!='*')
					 {
						 kl--;
					 }
					 int ug=kl;
					 kl=kl+1;
					 lcd_cmd(0x80);
					 ch=eeprom_read_byte(kl);
					 for( ipp=kl;ch!='*';ipp++)
					 {
						 eeprom_write_byte(ipp,' ');
						 ch=eeprom_read_byte(ipp);
						 lcd_data(ch);
					 }
					 kl=ipp;
					 lcd_cmd(0xc0);
					 ch=eeprom_read_byte(i);
					 for( ipp=kl;ch!='*';ipp++)
					 {
						 eeprom_write_byte(ipp,' ');
						 ch=eeprom_read_byte(ipp);
						 lcd_data(ch);
					 }
					 kl=ipp;
					 break;
				 }
				 if(PIND==64)
				 {
					 break;
				 }
				 if(PIND==128)
				 {	
					 break;
				 }
			 }
		 }
		 if(PIND==64||PIND==128)
		 break;
	 }
}
int new_contact(int k)
{
	int p;
	int j=0;
	clrscr();
	lcd_string_num("enter name",0x80);
	eeprom_write_byte(k,'*');
	k=k+1;
	p=k;
	int cmd=0x80;
	clrscr();
	while(1)
	{
		if(PIND==32)
		break;
		PORTC =0x06;;
		if(PINA==0b11111110)
		{	
			lcd_cmd(cmd);
			while(PINA==0b11111110);
			lcd_data('.');
			eeprom_write_byte(p,'.');
			_delay_ms(200);
			for(int ihj=0;ihj<=500;ihj++)
			{
				_delay_ms(1);
				if(PINA==0b11111110)
				{
					lcd_cmd(cmd);
					while(PINA==0b11111110);
					lcd_data(',');
					eeprom_write_byte(p,',');
					_delay_ms(100);
					for(int ihj=0;ihj<=500;ihj++)
					{
						_delay_ms(1);
						if(PINA==0b11111110)
						{
							lcd_cmd(cmd);
							while(PINA==0b11111110);
							lcd_data('!');
							eeprom_write_byte(p,'!');
							_delay_ms(100);
						}
					}
				}
			}
			cmd=cmd+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11111101)
		{	
			lcd_cmd(cmd);
			while(PINA==0b11111101);
			lcd_data('g');
			eeprom_write_byte(p,'g');
			for(int ihj=0;ihj<=500;ihj++)
			{
				_delay_ms(1);
				if(PINA==0b11111101)
				{
					lcd_cmd(cmd);
					while(PINA==0b11111101);
					lcd_data('h');
					eeprom_write_byte(p,'h');
					for(int ihj=0;ihj<=500;ihj++)
					{
						_delay_ms(1);
						if(PINA==0b11111101)
						{
							lcd_cmd(cmd);
							while(PINA==0b11111101);
							lcd_data('i');
							eeprom_write_byte(p,'i');
						}
					}
				}
			}
			cmd=cmd+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11111011)
		{	
			lcd_cmd(cmd);
			while(PINA==0b11111011);
			lcd_data('p');
			eeprom_write_byte(p,'p');
			for(int ihj=0;ihj<=500;ihj++)
			{
				_delay_ms(1);
				if(PINA==0b11111011)
				{
					lcd_cmd(cmd);
					while(PINA==0b11111011);
					lcd_data('q');
					eeprom_write_byte(p,'q');
					for(int ihj=0;ihj<=500;ihj++)
					{
						_delay_ms(1);
						if(PINA==0b11111011)
						{
							lcd_cmd(cmd);
							while(PINA==0b11111011);
							lcd_data('r');
							eeprom_write_byte(p,'r');
							for(int ihj=0;ihj<=500;ihj++)
							{
								_delay_ms(1);
								if(PINA==0b11111011)
								{
									lcd_cmd(cmd);
									while(PINA==0b11111011);
									lcd_data('s');
									eeprom_write_byte(p,'s');
								}
							}
						}
					}
				}
			}
			cmd=cmd+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11110111)
		{	
			lcd_cmd(cmd);
			lcd_data('&');
			eeprom_write_byte(p,'&');
			_delay_ms(100);
			for(int ihj=0;ihj<=500;ihj++)
			{
				_delay_ms(1);
				if(PINA==0b11110111)
				{
					lcd_cmd(cmd);
					lcd_data('#');
					eeprom_write_byte(p,'#');
					_delay_ms(100);
					for(int ihj=0;ihj<=500;ihj++)
					{
						_delay_ms(1);
						if(PINA==0b11110111)
						{
							lcd_cmd(cmd);
							lcd_data('@');
							eeprom_write_byte(p,'@');
							_delay_ms(100);
						}
					}
				}
			}
			cmd=cmd+1;
			p=p+1;
			k=k+1;
		}
		if(PIND==64)
		{	
			while(PIND==64);
			lcd_cmd(cmd);
			while(PINA==0b11111110);
			lcd_data(' ');
			eeprom_write_byte(p,' ');
			cmd=cmd-1;
			p=p-1;
			k=k-1;
		}
		PORTC =0x05;
		_delay_ms(10);
		if(PINA==0b11111110)
		{	
			lcd_cmd(cmd);
			while(PINA==0b11111110);
			lcd_data('a');
			eeprom_write_byte(p,'a');
			for(int ihj=0;ihj<=500;ihj++)
			{
				_delay_ms(1);
				if(PINA==0b11111110)
				{
					lcd_cmd(cmd);
					while(PINA==0b11111110);
					lcd_data('b');
					eeprom_write_byte(p,'b');
					for(int ihj=0;ihj<=500;ihj++)
					{
						_delay_ms(1);
						if(PINA==0b11111110)
						{
							lcd_cmd(cmd);
							while(PINA==0b11111110);
							lcd_data('c');
							eeprom_write_byte(p,'c');
						}
					}
				}
			}
			cmd=cmd+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11111101)
		{	
			lcd_cmd(cmd);
			while(PINA==0b11111101);
			lcd_data('j');
			eeprom_write_byte(p,'j');
			for(int ihj=0;ihj<=500;ihj++)
			{
				_delay_ms(1);
				if(PINA==0b11111101)
				{
					lcd_cmd(cmd);
					while(PINA==0b11111101);
					lcd_data('k');
					eeprom_write_byte(p,'k');
					for(int ihj=0;ihj<=500;ihj++)
					{
						_delay_ms(1);
						if(PINA==0b11111101)
						{
							lcd_cmd(cmd);
							while(PINA==0b11111101);
							lcd_data('l');
							eeprom_write_byte(p,'l');
						}
					}
				}
			}
			cmd=cmd+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11111011)
		{	
			lcd_cmd(cmd);
			while(PINA==0b11111011);
			lcd_data('t');
			eeprom_write_byte(p,'t');
			for(int ihj=0;ihj<=500;ihj++)
			{
				_delay_ms(1);
				if(PINA==0b11111011)
				{
					lcd_cmd(cmd);
					while(PINA==0b11111011);
					lcd_data('u');
					eeprom_write_byte(p,'u');
					for(int ihj=0;ihj<=500;ihj++)
					{
						_delay_ms(1);
						if(PINA==0b11111011)
						{
							lcd_cmd(cmd);
							while(PINA==0b11111011);
							lcd_data('v');
							eeprom_write_byte(p,'v');
						}
					}
				}
			}
			cmd=cmd+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11110111)
		{	
			while(PINA==0b11110111);
			lcd_cmd(cmd);
			lcd_data(' ');
			eeprom_write_byte(p,' ');
			cmd=cmd+1;
			p=p+1;
			k=k+1;
		}
		PORTC=0x03;
		_delay_ms(10);
		if(PINA==0b11111110)
		{
			lcd_cmd(cmd);
			while(PINA==0b11111110);
			lcd_data('d');
			eeprom_write_byte(p,'d');
			for(int ihj=0;ihj<=500;ihj++)
			{
				_delay_ms(1);
				if(PINA==0b11111110)
				{
					lcd_cmd(cmd);
					while(PINA==0b11111110);
					lcd_data('e');
					eeprom_write_byte(p,'e');
					for(int ihj=0;ihj<=500;ihj++)
					{
						_delay_ms(1);
						if(PINA==0b11111110)
						{
							lcd_cmd(cmd);
							while(PINA==0b11111110);
							lcd_data('f');
							eeprom_write_byte(p,'f');
						}
					}
				}
			}
			cmd=cmd+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11111101)
		{
			lcd_cmd(cmd);
			while(PINA==0b11111101);
			lcd_data('m');
			eeprom_write_byte(p,'m');
			for(int ihj=0;ihj<=500;ihj++)
			{
				_delay_ms(1);
				if(PINA==0b11111101)
				{
					lcd_cmd(cmd);
					while(PINA==0b11111101);
					lcd_data('n');
					eeprom_write_byte(p,'n');
					for(int ihj=0;ihj<=500;ihj++)
					{
						_delay_ms(1);
						if(PINA==0b11111101)
						{
							lcd_cmd(cmd);
							while(PINA==0b11111101);
							lcd_data('o');
							eeprom_write_byte(p,'o');
						}
					}
				}
			}
			cmd=cmd+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11111011)
		{
			lcd_cmd(cmd);
			while(PINA==0b11111011);
			lcd_data('w');
			eeprom_write_byte(p,'w');
			for(int ihj=0;ihj<=500;ihj++)
			{
				_delay_ms(1);
				if(PINA==0b11111011)
				{
					lcd_cmd(cmd);
					while(PINA==0b11111011);
					lcd_data('x');
					eeprom_write_byte(p,'x');
					for(int ihj=0;ihj<=500;ihj++)
					{
						_delay_ms(1);
						if(PINA==0b11111011)
						{
							lcd_cmd(cmd);
							while(PINA==0b11111011);
							lcd_data('y');
							eeprom_write_byte(p,'y');
							for(int ihj=0;ihj<=500;ihj++)
							{
								_delay_ms(1);
								if(PINA==0b11111011)
								{
									lcd_cmd(cmd);
									while(PINA==0b11111011);
									lcd_data('z');
									eeprom_write_byte(p,'z');
								}
							}
						}
					}
				}
			}
			cmd=cmd+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11110111)
		{
			cmd=0x80;
		}
		if(PIND==32)
		break;
		if(PIND==64||PIND==128)
		return;
	}
	eeprom_write_byte(k,'*');
	k=k+1;
	p=k;
	lcd_string_num("enter number",0x80);
	_delay_ms(1000);
	while(1)
	{
		PORTC =0x06;
		_delay_ms(10);
		if(PINA==0b11111110)
		{
			while (PINA==0b11111110);
			lcd_cmd(0x80+j);
			lcd_num(1);
			eeprom_write_byte(p,'1');
			j=j+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11111101)
		{
			while (PINA==0b11111101);
			lcd_cmd(0x80+j);
			lcd_num(4);
			eeprom_write_byte(p,'4');
			j=j+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11111011)
		{
			while (PINA==0b11111011);
			lcd_cmd(0x80+j);
			lcd_num(7);
			eeprom_write_byte(p,'7');
			j=j+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11110111)
		{
			while (PINA==0b11110111);
			lcd_cmd(0x80+j);
			lcd_num(11);
			eeprom_write_byte(p,'11');
			j=j+1;
			p=p+1;
			k=k+1;
		}
		PORTC =0x05;
		_delay_ms(10);
		if(PINA==0b11111110)
		{
			while (PINA==0b11111110);
			lcd_cmd(0x80+j);
			lcd_num(2);
			eeprom_write_byte(p,'2');
			j=j+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11111101)
		{
			while (PINA==0b11111101);
			lcd_cmd(0x80+j);
			lcd_num(5);
			eeprom_write_byte(p,'5');
			j=j+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11111011)
		{
			while (PINA==0b11111011);
			lcd_cmd(0x80+j);
			lcd_num(8);
			eeprom_write_byte(p,'8');
			j=j+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11110111)
		{
			while (PINA==0b11110111);
			lcd_cmd(0x80+j);
			lcd_num(0);
			eeprom_write_byte(p,'0');
			j=j+1;
			p=p+1;
			k=k+1;
		}
		PORTC=0x03;
		_delay_ms(10);
		if(PINA==0b11111110)
		{
			while (PINA==0b11111110);
			lcd_cmd(0x80+j);
			lcd_num(3);
			eeprom_write_byte(p,'3');
			j=j+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11111101)
		{
			while (PINA==0b11111101);
			lcd_cmd(0x80+j);
			lcd_num(6);
			eeprom_write_byte(p,'6');
			j=j+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11111011)
		{
			while (PINA==0b11111011);
			lcd_cmd(0x80+j);
			lcd_num(9);
			eeprom_write_byte(p,'9');
			j=j+1;
			p=p+1;
			k=k+1;
		}
		else if(PINA==0b11110111)
		{
			while (PINA==0b11110111);
			lcd_cmd(0x80+j);
			lcd_num(12);
			eeprom_write_byte(p,'12');
			j=j+1;
			p=p+1;
			k=k+1;
		}
		if(PIND==32)
		break;
		if(PIND==64||PIND==128)
		return;
	}
	lcd_string("contact saved");
	return k;
}
int keypad(void)
{	int j=0;
	while(1)
	{	
		PORTC =0x06;
		_delay_ms(10);
		j=j+10;
		if(PINA==0b11111110)
		{
			while (PINA==0b11111110)
			{
			j=j+1;}
			i=i+j/1000;
			return(1);
		}
		else if(PINA==0b11111101)
		{
			while (PINA==0b11111101){
			j=j+1;}
			i=i+j/1000;
			return (4);
		}
		else if(PINA==0b11111011)
		{
			while (PINA==0b11111011){
			j=j+1;}
			i=i+j/1000;
			return (7);
		}
		else if(PINA==0b11110111)
		{
			while (PINA==0b11110111){
			j=j+1;}
			i=i+j/1000;
			return (11);
		}
		PORTC =0x05;
		_delay_ms(10);
		j=j+10;
		if(PINA==0b11111110)
		{
			while (PINA==0b11111110){
			j=j+1;}
			i=i+j/1000;
			return(2);
		}
		else if(PINA==0b11111101)
		{
			while (PINA==0b11111101){
			j=j+1;}
			i=i+j/1000;
			return (5);
		}
		else if(PINA==0b11111011)
		{
			while (PINA==0b11111011){
				j=j+1;}
				i=i+j/1000;
			return (8);
		}
		else if(PINA==0b11110111)
		{
			while (PINA==0b11110111)
			{
				j=j+1;
			}
			i=i+j/1000;
			return (10);
		}
		PORTC=0x03;
		_delay_ms(10);
		j=j+10;
		if(PINA==0b11111110)
		{
			while (PINA==0b11111110);
			{
				j=j+1;
			}
			i=i+j/1000;
			return(3);
		}
		else if(PINA==0b11111101)
		{
			while (PINA==0b11111101)
			{
				j=j+1;
			}
			i=i+j/1000;
			return (6);
		}
		else if(PINA==0b11111011)
		{
			while (PINA==0b11111011)
				{
					j=j+1;
				}
				i=i+j/1000;
			return (9);
		}
		else if(PINA==0b11110111)
		{
			while (PINA==0b11110111)
				{
					j=j+1;
				}
				i=i+j/1000;
			return (12);
		}
	}
}
void lcd_num(int n)
{
		int iop=0;
		lcd_cmd(0x04);
		if(n==0)
		lcd_data(48);
		else
		{
			while(n!=0)
			{
				iop=n%10;
				lcd_data(48+iop);
				n=n/10;
			}
		}
		lcd_cmd(0x06);
}
void lcd_cmd(int c)
{
	PORTB = (c&0xf0)+0x04;
	_delay_ms(1);
	PORTB =PORTB-0x04;
	PORTB=((c<<4)&0xf0)+0x04;
	_delay_ms(1);
	PORTB =PORTB-0x04;
}
void lcd_data(int d)
{
	PORTB = (d&0xf0)+0x05;
	_delay_ms(1);
	PORTB =PORTB-0x04;
	PORTB=((d<<4)&0xf0)+0x05;
	_delay_ms(1);
	PORTB =PORTB-0x04;
}
void clrscr(void)
{
	lcd_cmd(0x01);
	_delay_ms(5);
}
void lcd_init(void)
{
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x0c);
	lcd_cmd(0x06);
}
void lcd_string(char*name)
{
	int k=0;
	int ikl=0;
	for(int m=0;name[m]!='\0';m++)
	{
		k=m;
	}
	_delay_ms(1000);
	
		for(int j=0;j<k+1;j=j+i)
		{
			int e = 0x80;
			for( ikl=0;ikl<32;ikl++)
			{
				lcd_cmd(e++);
				lcd_data(name[ikl+j]);
				_delay_ms(50);
				if(ikl==15)
				{e=0xc0;
				}
				if(ikl+j==k+1)
				break;
			}
		}
}
int adc_read(int chn)
{
	ADMUX=0x40+chn;
	ADCSRA=0xd7;
	while((ADCSRA&0x10)==0);
	return ADC;
}
void lcd_string_num(char*name,int e)
{
	int k=0;
	int il=0;
	for(int m=0;name[m]!='\0';m++)
	{
		k=m;
	}
	_delay_ms(1000);
	for(int j=0;j<k+1;j=j+i)
	{
		for( il=0;il<32;il++)
		{
			lcd_cmd(e++);
			lcd_data(name[il+j]);
			_delay_ms(50);
			if(il+j==k+1)
			break;
		}
	}
}
void obstacle(void)
{
	lcd_cmd(0x50);
	lcd_data(0b00000000);
	lcd_data(0b00001100);
	lcd_data(0b00001100);
	lcd_data(0b00010010);
	lcd_data(0b00010010);
	lcd_data(0b00100001);
	lcd_data(0b00100001);
}
void custom_character(void)
{
	lcd_cmd(0x40);
	lcd_data(0b00000000);
	lcd_data(0b00000000);
	lcd_data(0b00000000);
	lcd_data(0b00000000);
	lcd_data(0b00001100);
	lcd_data(0b00010010);
	lcd_data(0b00100001);
}
void custom_character1(void)
{
	lcd_cmd(0x48);
	lcd_data(0b00001110);
	lcd_data(0b00000110);
	lcd_data(0b00000100);
	lcd_data(0b00001110);
	lcd_data(0b00010101);
	lcd_data(0b00000100);
	lcd_data(0b00001010);
	lcd_data(0b00001010);
}
void game(void)
{	
	int ww=15;
	int x=1;
	int m=0;
	int z=1;
	int j;
	PORTC=0;
	clrscr();
	_delay_ms(1000);
	lcd_string("game starts");
	_delay_ms(2500);
	clrscr();
	lcd_string("rules");
	_delay_ms(2500);
	lcd_string("4 or 6 for forward movement");
	_delay_ms(2500);
	clrscr();
	lcd_string("2 or 8 for jumping" );
	_delay_ms(2500);
	clrscr();
	lcd_string("pass every obstacle to win");
	_delay_ms(2500);
	clrscr();
	while (1)
	{
		for(j=16;j>0;j--)
		{
			if(j!=x)
			{
				if(j%ww!=0)
				{
					custom_character();
					lcd_cmd(0xc0+j-1);
					lcd_data(0);
					_delay_ms(1);
				}
				if(PINA==0b11111101)
				{
					z=z+1;
					if(z==16)
					{
						lcd_string("next level");
						z=1;
					}
					x=z;
					custom_character1();
					lcd_cmd(0xc0+z);
					lcd_data(1);
					_delay_ms(1);
					custom_character();
					lcd_cmd(0xc0+z-1);
					lcd_data(0);
					_delay_ms(1);
				}
				if(PINA==0b11111011)
				{
					z=z+1;
					if(z==16)
					{
						lcd_string("next level");
						z=1;
					}
					x=z;
					custom_character1();
					lcd_cmd(0xc0+z+1);
					lcd_data(1);
					_delay_ms(1);
					custom_character();
					lcd_cmd(0xc0+z-1);
					lcd_data(0);
					_delay_ms(1);
				}
				if(PINA==0b11111110)
				{
					z=z+1;
					if(z==16)
					{
						lcd_string("next level");
						z=1;
					}
					x=z;
					custom_character1();
					lcd_cmd(0xc0+z+1);
					lcd_data(1);
					_delay_ms(1);
					custom_character();
					lcd_cmd(0xc0+z-1);
					lcd_data(0);
					_delay_ms(1);
				}
			}
			if(j%ww==0)
			{
				if(j==x)
				{
					clrscr();
					lcd_string("game over");
					_delay_ms(2500);
					lcd_string("exit:press back cont: press middle");
					m=1;
					break;
				}
				obstacle();
				lcd_cmd(0xc0+j-1);
				lcd_data(2);
				_delay_ms(10);
				if(PINA==0b11111101)
				{
					z=z+1;
					if(z==16)
					{
						lcd_string("next level");
						z=1;
					}
					x=z;
					custom_character1();
					lcd_cmd(0xc0+z);
					lcd_data(1);
					_delay_ms(1);
					custom_character();
					lcd_cmd(0xc0+z-1);
					lcd_data(0);
					_delay_ms(1);
				}
				if(PINA==0b11111011)
				{
					z=z+1;
					if(z==16)
					{
						lcd_string("next level");
						z=1;
					}
					x=z;
					custom_character1();
					lcd_cmd(0xc0+z+1);
					lcd_data(1);
					_delay_ms(1);
					custom_character();
					lcd_cmd(0xc0+z-1);
					lcd_data(0);
					_delay_ms(1);
				}
				if(PINA==0b11111110)
				{
					z=z+1;
					if(z==16)
					{
						lcd_string("next level");
						z=1;
					}
					x=z;
					custom_character1();
					lcd_cmd(0xc0+z+1);
					lcd_data(1);
					_delay_ms(1);
					custom_character();
					lcd_cmd(0xc0+z-1);
					lcd_data(0);
					_delay_ms(1);
				}
			}
			if(j==x)
			{
				custom_character1();
				lcd_cmd(0xc0+x);
				lcd_data(1);
				_delay_ms(1);
				if(PINA==0b11111101)
				{
					z=z+1;
					if(z==16)
					{
						lcd_string("next level");
						z=1;
					}
					x=z;
					custom_character1();
					lcd_cmd(0xc0+z);
					lcd_data(1);
					_delay_ms(1);
					custom_character();
					lcd_cmd(0xc0+z-1);
					lcd_data(0);
					_delay_ms(1);
				}
				if(PINA==0b11111011)
				{
					z=z+1;
					if(z==16)
					{
						lcd_string("next level");
						z=1;
					}
					x=z;
					custom_character1();
					lcd_cmd(0xc0+z+1);
					lcd_data(1);
					_delay_ms(1);
					custom_character();
					lcd_cmd(0xc0+z-1);
					lcd_data(0);
					_delay_ms(1);
				}
				if(PINA==0b11111110)
				{
					z=z+1;
					if(z==16)
					{
						lcd_string("next level");
						z=1;
					}
					x=z;
					custom_character1();
					lcd_cmd(0xc0+z+1);
					lcd_data(1);
					_delay_ms(1);
					custom_character();
					lcd_cmd(0xc0+z-1);
					lcd_data(0);
					_delay_ms(1);
				}
			}
		}
		if(m==1)
		{
			while(PIND==0);
			if(PIND==1)
			{
				 ww=15;
				 x=1;
				 m=0;
				 z=1;
				 j=16;
				 continue;
			}
			if(PIND==8)
			{
				 m=1;
				 break;
			}
		}
		for(int k=ww+8;k>=0;k--)
		{
			 _delay_ms(100);
		}
		_delay_ms(100);
		ww=ww-1;
		if(ww==1)
		{
			 ww=15;
		}
		if(PINA==0b11111101)
		{
			 z=z+1;
			 if(z==16)
			 {
				 lcd_string("next level");
				 z=1;
			 }
			 x=z;
			 custom_character1();
			 lcd_cmd(0xc0+z);
			 lcd_data(1);
			 _delay_ms(1);
			 custom_character();
			 lcd_cmd(0xc0+z-1);
			 lcd_data(0);
			 _delay_ms(1);
		}
		if(PINA==0b11111011)
		{
			 z=z+1;
			 if(z==16)
			 {
				 lcd_string("next level");
				 z=1;
			 }
			 x=z;
			 custom_character1();
			 lcd_cmd(0xc0+z+1);
			 lcd_data(1);
			 _delay_ms(1);
			 custom_character();
			 lcd_cmd(0xc0+z-1);
			 lcd_data(0);
			 _delay_ms(1);
		}
		if(PINA==0b11111110)
		{
			 z=z+1;
			 if(z==16)
			 {
				 lcd_string("next level");
				 z=1;
			 }
			 x=z;
			 custom_character1();
			 lcd_cmd(0xc0+z+1);
			 lcd_data(1);
			 _delay_ms(1);
			 custom_character();
			 lcd_cmd(0xc0+z-1);
			 lcd_data(0);
			 _delay_ms(1);
		}
	 }
}
int music(void)
{	
	int g=1;
	int h=0;
	int t=0;
	clrscr();
	while(1)
	{
		lcd_string_num("sa-re-ga-ma",0x80);
		lcd_string_num("vande_matram",0xc0);
		while(PIND==0);
		if(PIND==2)
		{
			if(g>1)
			{
				while(PIND==2);
				if(g!=1)
				{
					g=g-1;
				}
				clrscr();
				lcd_cmd(0x85);
				lcd_num(g);
				h=1;
			}
		}
		if(PIND==4)
		{
			while(PIND==4);
			if(g<=2)
			g=g+1;
			clrscr();
			lcd_cmd(0x85);
			lcd_num(g);
			h=1;
		}
		if(PIND==32)
		{
			h=1;
			t=1;
		}
		if(PIND==64)
		{	
			return 0;
		}
		if(PIND==128)
		{	
			return 1;
		}
		if(h==1)
		{
			if(g==1&&t==0)
			{
				lcd_string_num("sa-re-ga",0x80);
				lcd_string_num("vande-matram",0xc0);
				h=0;
			}
			if(g==2&&t==0)
			{
				lcd_string_num("vande-matram",0x80);
				lcd_string_num("namokar-mantra",0xc0);
				h=0;
			}
			if(g==3&&t==0)
			{
				lcd_string_num("namokar-mantra",0x80);
				h=0;
			}
			if(g==1&&t==1)
			{	
				clrscr();
				lcd_string_num("sa-re-ga",0x80);
				sa_re_ga();
				h=0;
				t=0;
			}
			if(g==2&&t==1)
			{	
				clrscr();
				lcd_string_num("vande-matram",0x80);
				vande_matram();
				h=0;
				t=0;
			}
			if(g==3&&t==1)
			{	
				clrscr();
				lcd_string_num("namokar-mantra",0x80);
				namokar_mantra();
				h=0;
				t=0;
			}
			if(PIND==64)
			{
				return 0;
			}
			if(PIND==128)
			{
				return 1;
			}
		}
	}
}
void sa_re_ga(void)
{	
	TCCR0=0b00011010;
	OCR0=59;//sa
	_delay_ms(1000);
	OCR0=52;//re
	_delay_ms(1000);
	OCR0=46;//g
	_delay_ms(1000);
	OCR0=42;//m
	_delay_ms(1000);
	OCR0=38;//p
	_delay_ms(1000);
	OCR0=34;//dha
	_delay_ms(1000);
	OCR0=30;//ni
	_delay_ms(1000);
	OCR0=28;//sa
	_delay_ms(1000);
	OCR0=0;
	_delay_ms(100);
	OCR0=28;//sa
	_delay_ms(1000);
	OCR0=30;//ni
	_delay_ms(1000);
	OCR0=34;//dha
	_delay_ms(1000);
	OCR0=38;//p
	_delay_ms(1000);
	OCR0=42;//m
	_delay_ms(100);
	OCR0=46;//g
	_delay_ms(100);
	OCR0=52;//re
	_delay_ms(100);
	OCR0=59;//sa
	_delay_ms(100);
	OCR0=0;
	_delay_ms(100);
	lcd_string("hello");
	return ;
}
void vande_matram(void)
{	
	TCCR0=0x1a;
	OCR0=59;//sa
	_delay_ms(100);
	OCR0=52;//re
	_delay_ms(100);
	OCR0=42;//m
	_delay_ms(50);
	OCR0=38;//p
	_delay_ms(50);
	OCR0=42;//m
	_delay_ms(50);
	OCR0=38;//p
	_delay_ms(100);
	OCR0=42;//m
	_delay_ms(100);
	OCR0=38;//p
	_delay_ms(100);
	OCR0=30;//ni
	_delay_ms(50);
	OCR0=28;//sa
	_delay_ms(50);
	OCR0=30;//ni
	_delay_ms(50);
	OCR0=28;//sa
	_delay_ms(100);
	return ;
}
void namokar_mantra(void)
{	
	TCCR0=0x1a;
	OCR0=59;//sa
	_delay_ms(50);
	OCR0=42;//m
	_delay_ms(50);
	OCR0=0;
	_delay_ms(10);
	OCR0=42;//m
	_delay_ms(100);
	OCR0=0;
	_delay_ms(10);
	OCR0=42;//m
	_delay_ms(100);
	OCR0=38;//p
	_delay_ms(100);
	OCR0=42;//m
	_delay_ms(100);
	OCR0=59;//sa
	_delay_ms(50);
	OCR0=42;//m
	_delay_ms(50);
	OCR0=0;
	_delay_ms(10);
	OCR0=42;//m
	_delay_ms(100);
	OCR0=38;//p
	_delay_ms(100);
	OCR0=42;//m
	_delay_ms(100);
	OCR0=59;//sa
	_delay_ms(50);
	OCR0=42;//m
	_delay_ms(50);
	OCR0=0;
	_delay_ms(10);
	OCR0=42;//m
	_delay_ms(100);
	OCR0=0;
	_delay_ms(10);
	OCR0=42;//m
	_delay_ms(100);
	OCR0=38;//p
	_delay_ms(100);
	OCR0=42;//m
	_delay_ms(100);	
	return;
}
void password_change(void)
{	
	lcd_cmd(0x80);
	char b[4];
	int aa;
	//checking the existing password
	lcd_string("change password press pind1");
	if(PIND==1)
	{
		for(int j=0;j<4;j++)
		{
			aa=keypad();
			lcd_cmd(0x85);
			clrscr();
			lcd_num(aa);
			_delay_ms(1000);
			if(eeprom_read_byte(j)==aa+48)
			{
				if(j==3)
				{
					lcd_string("correct password");
					_delay_ms(1000);
					clrscr();
					lcd_string("enter the new password");
					for(int ip=0;ip<4;ip++)
					{
						aa=keypad();
						lcd_cmd(0x85);
						clrscr();
						lcd_num(aa);
						_delay_ms(1000);
						b[ip]=aa+48;
						eeprom_write_byte(ip,b[ip]);
					}
				}
				continue;
			}
			else
			{
				clrscr();
				lcd_string("incorrect password");
				break;
			}
		}
	}
	clrscr();
	//checking password
/*		lcd_cmd(0x85);
		for(int i=0;i<4;i++)
		{
			b[i]=eeprom_read_byte(i);
			lcd_data(b[i]);
		}
		_delay_ms(100);*/
}
void calculator(void)
{
	_delay_ms(1000);
	int g=1,h=0,t=0,b;
	int c;
	int a;
	int cmd=0x82;
    while (1) 
    {
		for(int o=0;o<100;o++)
		{	
			PORTC =0x06;
			_delay_ms(10);
			if(PINA==0b11111110)
			{
				while (PINA==0b11111110);
				a=1;

				lcd_cmd(cmd);
				lcd_num(a);
				_delay_ms(1000);
			}
			else if(PINA==0b11111101)
			{
				while (PINA==0b11111101);
				a=4;
				lcd_cmd(cmd);
				lcd_num(a);
				_delay_ms(1000);
			}
			else if(PINA==0b11111011)
			{
				while (PINA==0b11111011);
				a=7;
				lcd_cmd(cmd);
				lcd_num(a);
				_delay_ms(1000);
			}
			else if(PINA==0b11110111)
			{
				while (PINA==0b11110111);
				a=11;
				lcd_cmd(cmd);
				lcd_num(a);
				_delay_ms(1000);
			}
			PORTC =0x05;
			_delay_ms(10);
			if(PINA==0b11111110)
			{
				while (PINA==0b11111110);
				a=2;
				lcd_cmd(cmd);
				lcd_num(a);
				_delay_ms(1000);
			}
			else if(PINA==0b11111101)
			{
				while (PINA==0b11111101);
				a=5;
				lcd_cmd(cmd);
				lcd_num(a);
				_delay_ms(1000);
			}
			else if(PINA==0b11111011)
			{
				while (PINA==0b11111011);
				a=8;
				lcd_cmd(cmd);
				lcd_num(a);
				_delay_ms(1000);
			}
			else if(PINA==0b11110111)
			{
				while (PINA==0b11110111);
				a=10;
				lcd_cmd(cmd);
				lcd_num(a);
				_delay_ms(1000);
			}
			PORTC=0x03;
			_delay_ms(10);
			if(PINA==0b11111110)
			{
				while (PINA==0b11111110);
				a=3;
				lcd_cmd(cmd);
				lcd_num(a);
				_delay_ms(1000);
			}
			else if(PINA==0b11111101)
			{
				while (PINA==0b11111101);
				a=6;
				lcd_cmd(cmd);
				lcd_num(a);
				_delay_ms(1000);
			}
			else if(PINA==0b11111011)
			{
				while (PINA==0b11111011);
				a=9;
				lcd_cmd(cmd);
				lcd_num(a);
				_delay_ms(1000);
			}
			else if(PINA==0b11110111)
			{
				while (PINA==0b11110111);
				a=12;
				lcd_cmd(cmd);
				lcd_num(a);
				_delay_ms(1000);
			}
			if(o==98)
			{
				cmd=cmd+1;
				o=0;
			}
		}
	/*	if(PIND==2)
		{
			if(g>1)
			{
				while(PIND==2);
				if(g!=1)
				{
					g=g-1;
				}
				lcd_cmd(0x85);
				lcd_num(g);
				_delay_ms(500);
				h=1;
			}
			h=1;
			clrscr();
		}
		if(PIND==4)
		{
			while(PIND==4);
			if(g<=3)
			g=g+1;
			clrscr();
			lcd_cmd(0x85);
			lcd_num(g);
			_delay_ms(500);
			h=1;
		}
		if(PIND==32)
		{
			h=1;
			t=1;
			PORTC =0x06;
			while(PIND==32);
			_delay_ms(10);
			while(1)
			{
				if(PINA==0b11111110)
				{
					while (PINA==0b11111110);
					b=1;
					clrscr();
					lcd_num(b);
					_delay_ms(1000);
					break;
				}
				else if(PINA==0b11111101)
				{
					while (PINA==0b11111101);
					b=4;
					clrscr();
					lcd_num(b);
					_delay_ms(1000);
					break;
				}
				else if(PINA==0b11111011)
				{
					while (PINA==0b11111011);
					b=7;
					clrscr();
					lcd_num(b);
					_delay_ms(1000);
					break;
				}
				else if(PINA==0b11110111)
				{
					while (PINA==0b11110111);
					b=11;
					clrscr();
					lcd_num(b);
					_delay_ms(1000);
					break;
				}
				PORTC =0x05;
				_delay_ms(10);
				if(PINA==0b11111110)
				{
					while (PINA==0b11111110);
					b=2;
					clrscr();
					lcd_num(b);
					_delay_ms(1000);
					break;
				}
				else if(PINA==0b11111101)
				{	
					while (PINA==0b11111101);
					b=5;
					clrscr();
					lcd_num(b);
					_delay_ms(1000);
					break;
				}
				else if(PINA==0b11111011)
				{
					while (PINA==0b11111011);
					b=8;
					clrscr();
					lcd_num(b);
					_delay_ms(1000);
					break;
				}
				else if(PINA==0b11110111)
				{
					while (PINA==0b11110111);
					b=10;
					clrscr();
					lcd_num(b);
					_delay_ms(1000);
					break;
				}
				PORTC=0x03;
				_delay_ms(10);
				if(PINA==0b11111110)
				{
					while (PINA==0b11111110);
					b=3;
					clrscr();
					lcd_num(b);
					_delay_ms(1000);
					break;
				}
				else if(PINA==0b11111101)
				{
					while (PINA==0b11111101);
					b=6;
					clrscr();
					lcd_num(b);
					_delay_ms(1000);
					break;
				}
				else if(PINA==0b11111011)
				{
					while (PINA==0b11111011);
					b=9;
					clrscr();
					lcd_num(b);
					_delay_ms(1000);
					break;
				}
				else if(PINA==0b11110111)
				{
					while (PINA==0b11110111);
					b=12;
					clrscr();
					lcd_num(b);
					_delay_ms(1000);
					break;
				}
			}
		}
		if(PIND==64)
		{
			break;
		}
		if(h==1)
		{
			if(g==1&&t==0)
			{	
				lcd_cmd(0x85);
				lcd_data('+');
				_delay_ms(500);
				h=0;
			}
			if(g==2&&t==0)
			{
				lcd_cmd(0x85);
				lcd_data('-');
				_delay_ms(500);
				h=0;
			}
			if(g==3&&t==0)
			{
				lcd_cmd(0x85);
				lcd_data('*');
				_delay_ms(500);
				h=0;
			}
			if(g==4&&t==0)
			{
				lcd_cmd(0x85);
				lcd_data('/');
				_delay_ms(500);
				h=0;
			}
			if(g==1&&t==1)
			{
				 c=addition(a,b);
				 a=c;
				 h=0;
				 g=1;
			}
			if(g==2&&t==1)
			{
				 c=subtraction(a,b);
				 a=c;
				 h=0;
				 g=1;
			}
			if(g==3&&t==1)
			{
				c=multiplication(a,b);
				a=c;
				h=0;
				g=1;
			}
			if(g==4&&t==1)
			{
				c=division(a,b);
				a=c;
				h=0;
				g=1;
			}
		}*/
	}
}