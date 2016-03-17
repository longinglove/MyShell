/*************************************************************************
	> File Name: parse.c
	> Author: duqinglong
	> Mail: du_303412@163.com 
	> Created Time: 2016年03月15日 星期二 21时34分18秒
 ************************************************************************/

#include "parse.h"
#include "externs.h"
#include "init.h"
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

void get_command(int i);
int check(const char *str);
void getname(char *name);
void print_command();

void shell_loop()
{
	while (1)
	{
		printf("[MyShell]$ ");
		fflush(stdout);
		init();
		if (read_command() == -1)
			break;
		parse_command();
		print_command();
		execute_command();
	}
	printf("\nexit\n");
}

int read_command()
{
	if (fgets(cmdline, MAXLINE, stdin) == NULL)
		return -1;
	return 0;
}

int parse_command()
{
	int i;
	if (check("\n"))
		return 0;
	/* cat < test.txt | grep -n public > test2.txt & */
	//解析第一条简单命令
	get_command(0);
	//判定是否有输入重定向符
	if (check("<"))
		getname(infile);
	//判定是否有管道，解析管道
	for (i = 1; i < PIPELINE; i++)
	{
		if (check("|"))
			get_command(i);
		else
			break;
	}
	//判定是否有输出重定向符
	if (check(">"))
	{
		if (check(">"))
			append = 1;
		getname(outfile);
	}
	//判定是否后台作业
	if (check("&"))
		backgnd = 1;
	//判定命令结束
	if (check("\n"))
	{
		cmd_count = i;
		return cmd_count;
	}
	else
	{
		fprintf(stderr, "Command error\n");
		return -1;
	}
	return 0;
}

int execute_command()
{
	return 0;
}

//解析简单命令到cmd[i],提取命令参数到avline数组中
void get_command(int i)
{
	int j = 0;
	int inword;
	while (*lineptr != '\0')
	{
		while (*lineptr == ' ' || *lineptr == '\t')
			lineptr++;
		//i 为命令 j为参数
		cmd[i].args[j] = avptr;
		while (*lineptr != '\0' && *lineptr != ' ' 
				&& *lineptr != '\t' && *lineptr != '>'
				&& *lineptr != '<' && *lineptr != '|'
				&& *lineptr != '&' && *lineptr != '\n')
		{
			*avptr++ = *lineptr++;
			inword = 1;
		}
		*avptr++ = '\0';
		switch (*lineptr)
		{
			case ' ':
			case '\t':
				inword = 0;
				j++;
				break;
			case '<':
			case '>':
			case '|':
			case '&':
			case '\n':
				if (inword == 0)
					cmd[i].args[j] = NULL;
				return;
			default:		// '\0'
				return;
		}
	}
}
int check(const char *str)
{
	char *p;
	while (*lineptr == ' ' || *lineptr == '\t')
		lineptr++;
	p = lineptr;
	while (*str != '\0' && *str == *p)
	{
		str++;
		p++;
	}
	if (*str == '\0')
	{
		lineptr = p;
		return 1;
	}
	return 0;
}
void getname(char *name)
{
	while (*lineptr == ' ' || *lineptr == '\t')
		lineptr++;
	while (*lineptr != '\0' && *lineptr != ' ' 
			&& *lineptr != '\t' && *lineptr != '>'
			&& *lineptr != '<' && *lineptr != '|'
			&& *lineptr != '&' && *lineptr != '\n')
		*name++ = *lineptr++;
	*name = '\0';
}


void print_command()
{
	int i, j;
	printf("cmd_count = %d\n", cmd_count);
	if (infile[0] != '\0')
		printf("infile = [%s]\n", infile);
	if (outfile[0] != '\0')
		printf("outfile = [%s]\n", outfile);
	for (i = 0; i < cmd_count; i++)
	{
		j = 0;
		while (cmd[i].args[j] != NULL)
		{
			printf("[%s] ", cmd[i].args[j]);
			j++;
		}
		printf("\n");
	}
}
