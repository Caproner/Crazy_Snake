#include"clib.h"
#include"clearX.h"
#include"SE.h"
void score_menu(long long score_first,long long score_second,long long score_third)
{
	system("cls");
	gotoxy(0,4);
	cout<<"                                     �߷ְ�"<<endl<<endl;
	cout<<"                          ��һ����"<<setw(20)<<score_first<<endl;
	cout<<"                          �ڶ�����"<<setw(20)<<score_second<<endl;
	cout<<"                          ��������"<<setw(20)<<score_third<<endl;
	char c=snakeSE("",0);
}
