#include"clib.h"
#include"clearX.h"
#include"SE.h"
void help_menu()
{
	system("cls");
	gotoxy(0,4);
	cout<<"                       在游戏中，你便是一条疯狂的吞噬蛇。                       "<<endl;
	cout<<"               在保证自己活着的情况下，尽可能吃更多的食物吧 =w=。               "<<endl;
	cout<<"                   当然，撞到墙或者是自己的身体的话就会死哦。                   "<<endl;
	cout<<"                                 游戏的操作为：                                 "<<endl;
	cout<<"                            WSAD键：控制吞噬蛇的转向                            "<<endl;
	cout<<"                             Q键：让吞噬蛇直接死亡                              "<<endl;
	cout<<"                               空格键：暂停游戏                                 "<<endl;
	cout<<"                             地图上的食物分为几种：                             "<<endl; 
	cout<<"                    ☆：普通食物，吃了会加积分并且使蛇变长。                    "<<endl;
	cout<<"              ◆：压缩食物，吃了会加积分并且使蛇变短四个单位长度。              "<<endl;
	cout<<"                    ▲：减速食物，吃了会加积分并且使蛇减速。                    "<<endl;
	char c=snakeSE("",0);
}
