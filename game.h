#include"clib.h"
struct snake_body
{
	int x,y;
};
struct snake
{
	list<snake_body> s;
	int speed;
	int slept;
	int shift;
	int score;
	char vec,vecf;
	bool islong,isshort;
	int short_length,x[4],y[4];
	int cx,cy;
};
struct food
{
	int x,y;
	int type;
};
