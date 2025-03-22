#ifndef CALCULATOR_H  // ��ֹ�ظ�����
#define CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK 100

// ȫ�ֱ����������������ļ���ʹ�� extern ���ʣ�
extern double operand_stack[];
extern int operand_top;
extern char operator_stack[];
extern int operator_top;

// ��������
void push_operand(double value);
double pop_operand();
void push_operator(char op);
char pop_operator();
int get_priority(char op);
void compute(char op);

#endif#pragma once
