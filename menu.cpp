#include"clib.h"
#include"clearX.h"
#include"SE.h"
void menuprint()
{
	system("cls");
	gotoxy(0,4);
	cout<<"                                   ���������"<<endl<<endl<<endl;
	cout<<"                                   1.��ʼ��Ϸ"<<endl<<endl;
	cout<<"                                    2.�߷ְ�"<<endl<<endl;
	cout<<"                                   3.��Ϸ����"<<endl<<endl;
	cout<<"                                   4.�˳���Ϸ"<<endl<<endl;
}
int menu()
{
	menuprint();
	char c=snakeSE("1234",1);
	return c-'0';
}
