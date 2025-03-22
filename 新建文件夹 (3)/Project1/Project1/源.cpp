#include "head.h"

int main() {
    char expr[100];
    printf("请输入表达式（字符请用英文输入）：");
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
                printf("括号不匹配\n");
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
                printf("非法字符: %c\n", expr[i]);
                exit(1);
            }
            i++;
        }
    }

    while (operator_top >= 0) {
        if (operator_stack[operator_top] == '(') {
            printf("括号不匹配\n");
            exit(1);
        }
        char op = pop_operator();
        compute(op);
    }

    if (operand_top == 0) {
        printf("结果：%.2f\n", operand_stack[operand_top]);
    }
    else {
        printf("表达式错误\n");
    }

    getchar();

    return 0;
}