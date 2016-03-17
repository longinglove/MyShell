/*************************************************************************
	> File Name: main.c
	> Author: duqinglong
	> Mail: du_303412@163.com 
	> Created Time: 2016年03月15日 星期二 21时33分57秒
 ************************************************************************/

#include"parse.h"
#include"init.h"
#include"def.h"
#include<stdio.h>

char cmdline[MAXLINE+1];
COMMAND cmd[PIPELINE];
char avline[MAXLINE+1];
char infile[MAXNAME+1];
char outfile[MAXNAME+1];
char *lineptr;
char *avptr;
int cmd_count;
int backgnd;
int append;

int main()
{
	setup();
	shell_loop();
	return 0;
}
