#include"clib.h"
#include"game.h"
#include"clearX.h"
int sft_s[29]={20,20,10,10,11,9,7,7,6,6,5,5,4,4,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2};
int sft_t[29]={25,16,25,20,15,16,18,16,17,15,17,15,18,17,21,20,19,18,17,16,15,22,21,20,19,18,17,16,15};
inline bool ismove(char c)
{
	if(c<'a')c+=('a'-'A');
	if(c=='w'||c=='s'||c=='a'||c=='d')return true;
	else return false;
}
void initialize_snake(snake &s)
{
	s.shift=0;
	s.speed=sft_s[0];
	s.slept=sft_t[0];
	s.score=0;
	s.vec='d';
	s.vecf='a';
	s.islong=false;
	s.isshort=false;
	snake_body ss;
	ss.x=3;
	ss.y=6;
	for(int i=0;i<4;i++)
	{
		s.s.push_back(ss);
		ss.y--;
	}
}
void initialize_map(snake s,int map[20][40])
{
	for(list<snake_body>::iterator i=s.s.begin();i!=s.s.end();i++)
	{
		if(i==s.s.begin())map[i->x][i->y]=98;
		else map[i->x][i->y]=99;
	}
	for(int i=0;i<40;i++)map[0][i]=1;
	for(int i=0;i<40;i++)map[19][i]=1;
	for(int i=0;i<20;i++)map[i][0]=1;
	for(int i=0;i<20;i++)map[i][39]=1;
	map[9][9]=2;
	map[11][11]=2;
	map[13][13]=2;
}
void initialize_interface(int score,int map[20][40])
{
	cout<<endl<<"��Ϸ����Ϊ��"<<score;
	gotoxy(38,1);
	cout<<"�����������С�����"<<endl<<endl;
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<40;j++)
		{
			if(i==9&&j==9) cout<<"��";
			else if(i==11&&j==11) cout<<"��";
			else if(i==13&&j==13) cout<<"��";
			else switch(map[i][j])
			{
				case 0:
					cout<<"  ";
					break;
				case 1:;
				case 99:
					cout<<"��";
					break;
				case 98:
					cout<<"��";
					break;
			}
		}
	} 
}
void initialize_food(food &f,int map[20][40])
{
	int x,y;
	while(1)
	{
		x=(rand()%18)+1;
		y=(rand()%38)+1;
		if(map[x][y]==0)break;
	}
	f.x=x;
	f.y=y;
	int r=rand()%100;
	if(r>89)f.type=3;
	else if(r>79)f.type=2;
	else f.type=1;
}
void food_in_map(food f,int map[20][40])
{
	map[f.x][f.y]=2;
	gotoxy(f.y*2,f.x+3);
	switch(f.type)
	{
		case 1:
			cout<<"��";
			break;
		case 2:
			cout<<"��";
			break;
		case 3:
			cout<<"��";
			break;
	}
}
void snake_up(snake &s)
{
	s.vec='w';
	list<snake_body>::iterator i=s.s.begin();
	int x=(i->x)-1,y=i->y;
	for(;i!=s.s.end();i++)
	{
		int xx=i->x,yy=i->y;
		i->x=x;
		i->y=y;
		x=xx;
		y=yy;
	}
	i--;
	if(i->x==x)
	{
		if(i->y<y)s.vecf='d';
		else s.vecf='a';
	}
	else if(i->x<x)s.vecf='s';
	else s.vecf='w';
}
void snake_down(snake &s)
{
	s.vec='s';
	list<snake_body>::iterator i=s.s.begin();
	int x=(i->x)+1,y=i->y;
	for(;i!=s.s.end();i++)
	{
		int xx=i->x,yy=i->y;
		i->x=x;
		i->y=y;
		x=xx;
		y=yy;
	}
	i--;
	if(i->x==x)
	{
		if(i->y<y)s.vecf='d';
		else s.vecf='a';
	}
	else if(i->x<x)s.vecf='s';
	else s.vecf='w';
}
void snake_left(snake &s)
{
	s.vec='a';
	list<snake_body>::iterator i=s.s.begin();
	int x=i->x,y=(i->y)-1;
	for(;i!=s.s.end();i++)
	{
		int xx=i->x,yy=i->y;
		i->x=x;
		i->y=y;
		x=xx;
		y=yy;
	}
	i--;
	if(i->x==x)
	{
		if(i->y<y)s.vecf='d';
		else s.vecf='a';
	}
	else if(i->x<x)s.vecf='s';
	else s.vecf='w';
}
void snake_right(snake &s)
{
	s.vec='d';
	list<snake_body>::iterator i=s.s.begin();
	int x=i->x,y=(i->y)+1;
	for(;i!=s.s.end();i++)
	{
		int xx=i->x,yy=i->y;
		i->x=x;
		i->y=y;
		x=xx;
		y=yy;
	}
	i--;
	if(i->x==x)
	{
		if(i->y<y)s.vecf='d';
		else s.vecf='a';
	}
	else if(i->x<x)s.vecf='s';
	else s.vecf='w';
}
bool isdead(list<snake_body> s)
{
	bool ans=true;
	list<snake_body>::iterator i=s.begin();
	int x=i->x,y=i->y;
	if(x==0||x==19||y==0||y==39)ans=false;
	else
	{
		for(i++;i!=s.end();i++)
		{
			if(x==i->x&&y==i->y)
			{
				ans=false;
				break;
			}
		}
	}
	return !ans;
}
void print_dead(int score)
{
	gotoxy(0,23);
	cout<<endl;
	cout<<"                �������������ջ��ǵ����ˡ��������Ǳ��ҵ�������"<<endl;
	cout<<"                ������շ���Ϊ��"<<score<<endl; 
	Sleep(3000);
}
int iseat(food f[3],snake s)
{
	int ans=0;
	list<snake_body>::iterator i=s.s.begin();
	for(int j=0;j<3;j++)
	{
		if(f[j].x==i->x&&f[j].y==i->y)
		{
			ans=j+1;
			break;
		}
	}
	return ans;
}
void snake_out_map(snake s,int map[20][40])//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	if(s.islong);
	else
	{
		int x=s.cx,y=s.cy;
		map[x][y]=0;
		gotoxy(y*2,x+3);
		cout<<"  ";
	}
	if(s.isshort)
	{
		for(int i=0;i<s.short_length;i++)
		{
			int x=s.x[i],y=s.y[i];
			map[x][y]=0;
			gotoxy(y*2,x+3);
			cout<<"  ";
		}
	}
}
void snake_in_map(snake s,int map[20][40])//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	list<snake_body>::iterator i=s.s.begin();
	map[i->x][i->y]=98;
	gotoxy(i->y*2,i->x+3);
	cout<<"��";
	i++;
	map[i->x][i->y]=99;
	gotoxy(i->y*2,i->x+3);
	cout<<"��";
}
void to_be_long(snake &s)//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	list<snake_body>::iterator i=s.s.end();
	i--;
	snake_body ss;
	ss=*i;
	switch(s.vecf)
	{
		case 'w':
			ss.x--;
			break;
		case 's':
			ss.x++;
			break;
		case 'a':
			ss.y--;
			break;
		case 'd':
			ss.y++;
			break;
	}
	s.s.push_back(ss);
	s.islong=true;
}
void to_be_short(snake &s)//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
{
	int ii=0;
	s.isshort=true;
	s.short_length=0;
	for(list<snake_body>::iterator i=s.s.begin();i!=s.s.end();i++)ii++;
	if(ii>6)
	{
		s.short_length=3;
		list<snake_body>::iterator it=s.s.end();
		it--;
		for(int i=0;i<3;i++)
		{
			s.x[i]=it->x;
			s.y[i]=it->y;
			it--;
			s.s.pop_back();
		}
	}
	else if(ii>4)
	{
		list<snake_body>::iterator it=s.s.end();
		it--;
		for(int i=0;i<ii-4;i++)
		{
			s.x[i]=it->x;
			s.y[i]=it->y;
			it--;
			s.s.pop_back();
			s.short_length++;
		}
	}
	else s.isshort=false;
}
void score_in_interface(int score)
{
	gotoxy(12,1);
	cout<<score<<"                     ";
}
void food_out_map(food &f,int map[20][40])
{
	map[f.x][f.y]=0;
	gotoxy((f.y)*2,(f.x)+3);
	cout<<"  ";
	f.type=0;
}
void snake_cc(snake &s)
{
	list<snake_body>::iterator i=s.s.end();
	i--;
	snake_body ss;
	ss=*i;
	switch(s.vecf)
	{
		case 'w':
			ss.x--;
			break;
		case 's':
			ss.x++;
			break;
		case 'a':
			ss.y--;
			break;
		case 'd':
			ss.y++;
			break;
	}
	s.cx=ss.x;
	s.cy=ss.y;
}
void game(long long &score_first,long long &score_second,long long &score_third)
{
	srand((unsigned int)time(NULL));
	system("cls");
	snake s;
	int map[20][40]={0};//0Ϊ�յأ�1Ϊǽ��2Ϊʳ���ʱֲ�����Ϊ99,98Ϊ��ͷ 
	initialize_snake(s);//��ʼ���� (10)
	initialize_map(s,map);//��ʼ����ͼ (29)
	int isfood=3;
	food f[3];
	f[0].x=9;
	f[0].y=9;
	f[0].type=1;
	f[1].x=11;
	f[1].y=11;
	f[1].type=1;
	f[2].x=13;
	f[2].y=13;
	f[2].type=1;
	initialize_interface(s.score,map);//��ʼ������ (42)
	int prin=1,prin1=1,prin2=1;
	while(1)
	{
		//�ж�ʳ���Ƿ���ʧ�Լ�����ʳ�� 
		if(isfood<3)
		{
			for(int i=0;i<3;i++)
			{
				if(f[i].type==0)
				{
					initialize_food(f[i],map);//����ʳ�� (66)
			        food_in_map(f[i],map);//��ʳ�������ͼ (82)
					isfood++;
				}
			}
		}
		//�ڵȴ�ʱ���ڽ��հ��� 
		char c='0';
		int isexit=0;
		for(int i=0;i<s.speed;i++)
		{
			if(kbhit())
			{
				c=getch();
				if(c=='q'||c=='Q')
				{
					isexit=1;
					break;
				}
				if(c==' ')
				{
					gotoxy(0,23);
					cout<<endl<<"                                    ��Ϸ��ͣ";
					getch();
					gotoxy(0,23);
					cout<<endl<<"                                                                        " ;
				}
				if(ismove(c))
				{
					if(c<'a')c+=('a'-'A');
					if(c=='a'||c=='d')
					{
						if(s.vec=='w'||s.vec=='s')break;
					}
					else if(s.vec=='a'||s.vec=='d')break;
				}
			}
			Sleep(s.slept);
		}
		//���û�����Ч��������ִ�� 
		int imove=0;
		if(ismove(c)&&!isexit)//�ж��Ƿ��ƶ� (4)
		{
			if(c<'a')c+=('a'-'A');
			int okk=1;
			if(c=='a'||c=='d')
			{
				if(s.vec=='a'||s.vec=='d')okk=0;
			}
			else if(s.vec=='w'||s.vec=='s')okk=0;
			if(okk)
			{
				switch(c)
				{
					case 'w':
						snake_up(s);//�������ƶ� (86)
						break;
					case 's':
						snake_down(s);//�������ƶ� (108)
						break;
					case 'a':
						snake_left(s);//�������ƶ� (130)
						break;
					case 'd':
						snake_right(s);//�������ƶ� (152)
						break;
				}
				imove=1;
			}
		}
		//���û�û�н��а���ʱ���������ƶ� 
		if(!imove&&!isexit)
		{
			switch(s.vec)
			{
				case 'w':
					snake_up(s);
					break;
				case 's':
					snake_down(s);
					break;
				case 'a':
					snake_left(s);
					break;
				case 'd':
					snake_right(s);
					break;
			}
			imove=1;
		}
		snake_cc(s);
		//�ж����Ƿ������Լ���������ߵ��ƺ��� 
		if(isdead(s.s)||isexit)//�ж�����û��ײǽ����ײ���� (174)
		{
 			print_dead(s.score);//��Ϸ�������� (193)
			if(s.score>score_third)
			{
				int t=score_second;
				if(s.score>score_second)
				{
					int tt=score_first;
					if(s.score>score_first)
					{
						score_first=s.score;
						score_second=tt;
						score_third=t;
					}
					else
					{
						score_second=s.score;
						score_third=t;
					}
				}
				else score_third=s.score;
			}
			getch();
			break;
		}
		//�ж�ʳ���Ƿ񱻳Ե��Լ�ִ��ʳ��Ĺ��� 
		int et=iseat(f,s);//�ж���ͷ�Ƿ���ʳ���ص� (200)
		if(et)
		{
			isfood--;
			switch(f[et-1].type)
			{
				case 1:
					s.score++;
					to_be_long(s);//�����߱����쳤һ����λ 
					break;
				case 2:
					s.score++;
					to_be_short(s);//�����߱��������ĸ���λ
					break;
				case 3:
					s.score++;
					if(s.shift-5>=0)s.shift-=5;
					else s.shift=0;
			}
			if(s.shift<28&&f[et-1].type==1)
			{
				if(s.shift<3)s.shift++;
				else if(s.score>=20&&s.shift<8)s.shift++;
				else if(s.score>=50&&s.shift<18)s.shift++;
				else if(s.score>=100)s.shift++;
			}
			s.speed=sft_s[s.shift];
			s.slept=sft_t[s.shift];
			food_out_map(f[et-1],map);//��ʳ���Ƴ���ͼ 
			score_in_interface(s.score);//������������� 
		}
		snake_out_map(s,map);//�����Ƴ���ͼ 
		snake_in_map(s,map);//���������ͼ 
		s.islong=false;
		s.isshort=false;
		//gotoxy(0,23);
		//cout<<setw(10)<<"Speed Data:"<<1000.0/(double)s.speed/(double)s.slept<<"bit/s          ";
		if(s.score>=20&&prin)
		{
			gotoxy(38,1);
			cout<<"�����߸о��Լ����ٶȿ�������ͻ���ˣ�";
			prin=0;
		}
		else if(s.score>=50&&prin1)
		{
			gotoxy(38,1);
			cout<<"�����߳������㹻��ʳ���ÿ��Ը����ˣ�";
			prin1=0;
		}
		else if(s.score>=100&&prin2)
		{
			gotoxy(36,1);
			cout<<"�����߳����˸����ʳ��ٶȸ���ͻ���ͽ���";
			prin2=0;
		}
	}
}
