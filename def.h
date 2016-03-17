/*************************************************************************
	> File Name: def.h
	> Author: duqinglong
	> Mail: du_303412@163.com 
	> Created Time: 2016年03月15日 星期二 22时00分17秒
 ************************************************************************/

#ifndef _DEF_H_
#define _DEF_H_

#include<stdlib.h>
#include<errno.h>

#define MAXLINE 1024	//输入行最大长度
#define MAXARG	20		//命令的参数最大个数
#define PIPELINE 5		//管道行中命令最多个数
#define MAXNAME 100		//IO重定向文件名的最大长度

#define ERROR(m)	\
	do{perror(m);exit(EXIT_FAILURE);} while (0)

typedef struct command
{
	char *args[MAXARG];		//解析出的命令参数列表
} COMMAND;

#endif
