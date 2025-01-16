#include <stdio.h>

int add(int a, int b) {
    return a + b;
}
 
int subtract(int a, int b) {
    return a - b;
}
 
int (*get_operation(char op))(int, int) {
    if (op == '+') {
        return &add;
    } else if (op == '-') {
        return &subtract;
    } else {
        return NULL;
    }
}

int main(int argc, char **argv) {
    printf("In the scratch program\n");

    int (*op)(int, int) = get_operation('-');
    int result = op(3, 4);
    printf("Result is %d\n", result);

    int (*plus)(int, int) = get_operation('+');
    printf("Result is %d\n", plus(3, 4));
    return 0;
}
