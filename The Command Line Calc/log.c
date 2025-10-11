void logarithmic_operation(FILE *file) {
    double num;
    printf("Enter number: ");
    scanf("%lf", &num);

    if (num <= 0) {
        printf("Error: log undefined for <= 0!\n");
        return;
    }

    double result = log10(num);
    printf("Result: %.4lf\n", result);
    fprintf(file, "Log10(%.2lf) = %.4lf\n", num, result);
}