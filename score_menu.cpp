#include"clib.h"
#include"clearX.h"
#include"SE.h"
void score_menu(long long score_first,long long score_second,long long score_third)
{
	system("cls");
	gotoxy(0,4);
	cout<<"                                     高分榜"<<endl<<endl;
	cout<<"                          第一名："<<setw(20)<<score_first<<endl;
	cout<<"                          第二名："<<setw(20)<<score_second<<endl;
	cout<<"                          第三名："<<setw(20)<<score_third<<endl;
	char c=snakeSE("",0);
}
