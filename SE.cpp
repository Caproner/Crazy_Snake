#include"clib.h"
#include"clearX.h"
char snakeSE(string s,int ct)
{
	static int x=0,y=2,p=1;
	int ok=1;
	char c;
	while(ok)
	{
		if(p)
		{
			if(x==66)p=0;
			gotoxy(x,y);
			cout<<"  ¡ö¡ö¡ö¡ö¡ö¡õ";
			if(p==1)x+=2;
		}
		else
		{
			if(x==0)p=1;
			gotoxy(x,y);
			cout<<"¡õ¡ö¡ö¡ö¡ö¡ö  ";
			if(p==0)x-=2;
		}
		for(int i=0;i<40;i++)
		{
			if(kbhit())
			{
				c=getch();
				int j;
				if(ct==1)
				{
					for(j=0;j<s.length();j++)
				    {
					    if(s[j]==c)
					    {
						    ok=0;
						    break;
					    }
				    }
				    if(j!=s.length())break;
				}
				else
				{
					ok=0;
					break;
				}
			}
			Sleep(15);
		}
	}
	return c;
}
