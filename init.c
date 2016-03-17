/*************************************************************************
	> File Name: init.c
	> Author: duqinglong
	> Mail: du_303412@163.com 
	> Created Time: 2016年03月15日 星期二 21时54分20秒
 ************************************************************************/

#include "init.h"
#include "externs.h"
#include<stdio.h>
#include<signal.h>
#include<string.h>

void setup()
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

void sigint_handler(int sig)
{
	printf("\n[MyShell]$ ");
	fflush(stdout);
}

void init()
{
	memset(cmd, 0, sizeof(cmd));
	memset(cmdline, 0, sizeof(cmdline));
	memset(avline, 0, sizeof(avline));
	memset(infile, 0, sizeof(infile));
	memset(outfile, 0, sizeof(outfile));
	cmd_count = 0;
	backgnd = 0;
	append = 0;
	lineptr = cmdline;
	avptr = avline;
}
