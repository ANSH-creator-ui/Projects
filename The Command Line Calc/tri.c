void trigonometric_operations(FILE *file) {
    int choice;
    double angle, result;
    printf("1. sin 2. cos 3. tan\nChoose: ");
    scanf("%d", &choice);
    printf("Enter angle (degrees): ");
    scanf("%lf", &angle);
    double rad = angle * M_PI / 180.0;

    if (choice == 1) result = sin(rad);
    else if (choice == 2) result = cos(rad);
    else if (choice == 3) result = tan(rad);
    else { printf("Invalid!\n"); return; }

    printf("Result: %.4lf\n", result);
    fprintf(file, "Trig: %d :  %.2lf -> %.4lf\n",choice, angle, result);
}
