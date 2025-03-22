#include "head.h"

// 全局变量定义（实际内存分配）
double operand_stack[MAX_STACK];
int operand_top = -1;

char operator_stack[MAX_STACK];
int operator_top = -1;

// 压入操作数栈
void push_operand(double value) {
    if (operand_top >= MAX_STACK - 1) {
        printf("操作数栈溢出\n");
        exit(1);
    }
    operand_stack[++operand_top] = value;
}

// 弹出操作数栈
double pop_operand() {
    if (operand_top < 0) {
        printf("操作数栈为空\n");
        exit(1);
    }
    return operand_stack[operand_top--];
}

// 压入运算符栈
void push_operator(char op) {
    if (operator_top >= MAX_STACK - 1) {
        printf("运算符栈溢出\n");
        exit(1);
    }
    operator_stack[++operator_top] = op;
}

// 弹出运算符栈
char pop_operator() {
    if (operator_top < 0) {
        printf("运算符栈为空\n");
        exit(1);
    }
    return operator_stack[operator_top--];
}

// 获取运算符优先级
int get_priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 执行计算
void compute(char op) {
    double b = pop_operand();
    double a = pop_operand();
    switch (op) {
    case '+': push_operand(a + b); break;
    case '-': push_operand(a - b); break;
    case '*': push_operand(a * b); break;
    case '/':
        if (b == 0.0) {
            printf("除数不能为零\n");
            exit(1);
        }
        push_operand(a / b);
        break;
    }
}