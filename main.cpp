#include"snake.h"
long long score_first,score_second,score_third;
int main()
{
	FILE *fp;
	fp=fopen("snake.sav","r+");
	fscanf(fp,"%lld %lld %lld",&score_first,&score_second,&score_third);
	system("mode con cols=80 lines=28");
	while(1)
	{
		switch(menu())
		{
			case 1:game(score_first,score_second,score_third);break;
			case 2:score_menu(score_first,score_second,score_third);break;
			case 3:help_menu();break;
			case 4:goto a;break;
			default:;
		}
	}
a:  fp=fopen("snake.sav","w+");
	fprintf(fp,"%lld %lld %lld",score_first,score_second,score_third);
	fclose(fp);
	return 0;
}
