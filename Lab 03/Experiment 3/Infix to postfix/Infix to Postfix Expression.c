#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack for characters
typedef struct {
    char items[MAX];
    int top;
} Stack;

void initStack(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
int isFull(Stack *s) { return s->top == MAX-1; }
void push(Stack *s, char c) { if (!isFull(s)) s->items[++s->top] = c; }
char pop(Stack *s) { if (!isEmpty(s)) return s->items[s->top--]; return '\0'; }
char peek(Stack *s) { if (!isEmpty(s)) return s->items[s->top]; return '\0'; }

// Return precedence of operators
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Check if operator is right-associative (only '^' here)
int isRightAssociative(char op) {
    return (op == '^');
}

// Check if character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Convert infix to postfix. Assumes single-char operands (letters/digits).
void infixToPostfix(const char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int k = 0; // index for postfix

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isspace((unsigned char)c)) continue; // ignore spaces

        if (isalnum((unsigned char)c)) {
            // operand -> add to output
            postfix[k++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            // pop until '('
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            if (!isEmpty(&s) && peek(&s) == '(') pop(&s); // remove '('
        } else if (isOperator(c)) {
            // pop while top has operator of higher precedence, or equal precedence when left-assoc
            while (!isEmpty(&s) && isOperator(peek(&s))) {
                char topOp = peek(&s);
                int precTop = precedence(topOp);
                int precCur = precedence(c);

                if ( (precTop > precCur) ||
                     (precTop == precCur && !isRightAssociative(c)) ) {
                    postfix[k++] = pop(&s);
                } else break;
            }
            push(&s, c);
        } else {
            // unsupported character
            fprintf(stderr, "Warning: ignoring unsupported char '%c'\n", c);
        }
    }

    // pop remaining operators
    while (!isEmpty(&s)) {
        char t = pop(&s);
        if (t == '(' || t == ')') continue; // ignore unmatched parentheses
        postfix[k++] = t;
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter infix expression (single-char operands, operators ^*/+- and parentheses):\n");
    if (!fgets(infix, sizeof(infix), stdin)) return 0;
    // remove newline if present
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);
    return 0;
}
