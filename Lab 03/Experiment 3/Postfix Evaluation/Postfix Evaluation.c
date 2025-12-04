#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

// push value onto stack
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack[++top] = val;
}

// pop value from stack
int pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack[top--];
}

// evaluate postfix expression
int evaluatePostfix(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (isspace(c)) continue; // ignore spaces

        if (isdigit(c)) {
            // operand → push
            push(c - '0');   // works for single-digit operands
        } else {
            // operator → pop two operands
            int val2 = pop();
            int val1 = pop();
            int res;

            switch (c) {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/': res = val1 / val2; break;
                case '^': res = (int)pow(val1, val2); break;
                default:
                    printf("Invalid operator: %c\n", c);
                    exit(1);
            }
            push(res);
        }
    }
    return pop();
}

int main() {
    char postfix[100];

    printf("Enter postfix expression (single-digit operands): ");
    fgets(postfix, sizeof(postfix), stdin);

    int result = evaluatePostfix(postfix);
    printf("Result = %d\n", result);

    return 0;
}
