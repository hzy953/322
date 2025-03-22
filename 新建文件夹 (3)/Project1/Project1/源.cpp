#include "head.h"

int main() {
    char expr[100];
    printf("��������ʽ���ַ�����Ӣ�����룩��");
    fgets(expr, sizeof(expr), stdin);

    int i = 0;
    while (i < strlen(expr)) {
        if (isdigit(expr[i]) || expr[i] == '.') {
            char num_str[20];
            int j = 0;
            while (i < strlen(expr) && (isdigit(expr[i]) || expr[i] == '.')) {
                num_str[j++] = expr[i++];
            }
            num_str[j] = '\0';
            double num = atof(num_str);
            push_operand(num);
        }
        else if (expr[i] == ' ') {
            i++;
        }
        else if (expr[i] == '(') {
            push_operator(expr[i]);
            i++;
        }
        else if (expr[i] == ')') {
            while (operator_top >= 0 && operator_stack[operator_top] != '(') {
                char op = pop_operator();
                compute(op);
            }
            if (operator_top >= 0 && operator_stack[operator_top] == '(') {
                pop_operator();
            }
            else {
                printf("���Ų�ƥ��\n");
                exit(1);
            }
            i++;
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            while (operator_top >= 0 && get_priority(operator_stack[operator_top]) >= get_priority(expr[i])) {
                char op = pop_operator();
                compute(op);
            }
            push_operator(expr[i]);
            i++;
        }
        else {
            if (expr[i] != '\n') {
                printf("�Ƿ��ַ�: %c\n", expr[i]);
                exit(1);
            }
            i++;
        }
    }

    while (operator_top >= 0) {
        if (operator_stack[operator_top] == '(') {
            printf("���Ų�ƥ��\n");
            exit(1);
        }
        char op = pop_operator();
        compute(op);
    }

    if (operand_top == 0) {
        printf("�����%.2f\n", operand_stack[operand_top]);
    }
    else {
        printf("���ʽ����\n");
    }

    getchar();

    return 0;
}