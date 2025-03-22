#include "head.h"

// ȫ�ֱ������壨ʵ���ڴ���䣩
double operand_stack[MAX_STACK];
int operand_top = -1;

char operator_stack[MAX_STACK];
int operator_top = -1;

// ѹ�������ջ
void push_operand(double value) {
    if (operand_top >= MAX_STACK - 1) {
        printf("������ջ���\n");
        exit(1);
    }
    operand_stack[++operand_top] = value;
}

// ����������ջ
double pop_operand() {
    if (operand_top < 0) {
        printf("������ջΪ��\n");
        exit(1);
    }
    return operand_stack[operand_top--];
}

// ѹ�������ջ
void push_operator(char op) {
    if (operator_top >= MAX_STACK - 1) {
        printf("�����ջ���\n");
        exit(1);
    }
    operator_stack[++operator_top] = op;
}

// ���������ջ
char pop_operator() {
    if (operator_top < 0) {
        printf("�����ջΪ��\n");
        exit(1);
    }
    return operator_stack[operator_top--];
}

// ��ȡ��������ȼ�
int get_priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// ִ�м���
void compute(char op) {
    double b = pop_operand();
    double a = pop_operand();
    switch (op) {
    case '+': push_operand(a + b); break;
    case '-': push_operand(a - b); break;
    case '*': push_operand(a * b); break;
    case '/':
        if (b == 0.0) {
            printf("��������Ϊ��\n");
            exit(1);
        }
        push_operand(a / b);
        break;
    }
}