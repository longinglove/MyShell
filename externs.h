/*************************************************************************
	> File Name: externs.h
	> Author: duqinglong
	> Mail: du_303412@163.com 
	> Created Time: 2016年03月15日 星期二 22时05分26秒
 ************************************************************************/

#ifndef _EXTERNS_H_
#define _EXTERNS_H_

#include "def.h"

extern char cmdline[MAXLINE+1];
extern COMMAND cmd[PIPELINE];
extern char avline[MAXLINE+1];
extern char infile[MAXNAME+1];
extern char outfile[MAXNAME+1];
extern int cmd_count;
extern int backgnd;
extern char *lineptr;
extern char *avptr;
extern int append;

#endif
