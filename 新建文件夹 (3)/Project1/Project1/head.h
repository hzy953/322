#ifndef CALCULATOR_H  // 防止重复包含
#define CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK 100

// 全局变量声明（在其他文件中使用 extern 访问）
extern double operand_stack[];
extern int operand_top;
extern char operator_stack[];
extern int operator_top;

// 函数声明
void push_operand(double value);
double pop_operand();
void push_operator(char op);
char pop_operator();
int get_priority(char op);
void compute(char op);

#endif#pragma once
