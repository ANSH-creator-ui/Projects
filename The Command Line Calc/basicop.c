void basic_operations(FILE *file) {
    double a, b, result;
    char op;
    printf("Enter (ex: 5 + 3): ");
    scanf("%lf %c %lf", &a, &op, &b);

    if (op == '+') result = a + b;
    else if (op == '-') result = a - b;
    else if (op == '*') result = a * b;
    else if (op == '/') {
        if (b == 0) { printf("Error: divide by zero!\n"); return; }
        result = a / b;
    } else { printf("Invalid operator!\n"); return; }

    printf("Result: %.2lf\n", result);
    fprintf(file, "Basic: %.2lf %c %.2lf = %.2lf\n", a, op, b, result);
}