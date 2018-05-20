#include"clib.h"
#include"clearX.h"
#include"SE.h"
void menuprint()
{
	system("cls");
	gotoxy(0,4);
	cout<<"                                   疯狂吞噬蛇"<<endl<<endl<<endl;
	cout<<"                                   1.开始游戏"<<endl<<endl;
	cout<<"                                    2.高分榜"<<endl<<endl;
	cout<<"                                   3.游戏帮助"<<endl<<endl;
	cout<<"                                   4.退出游戏"<<endl<<endl;
}
int menu()
{
	menuprint();
	char c=snakeSE("1234",1);
	return c-'0';
}
