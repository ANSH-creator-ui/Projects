
void matrix_operations(FILE *file) {
    int choice;
    printf("1. Add\n2. Multiply\nChoose: ");
    scanf("%d", &choice);

    int r1, c1, r2, c2;
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d%d", &r1, &c1);
    printf("Enter rows and columns of Matrix B: ");
    scanf("%d%d", &r2, &c2);

    if (choice == 1 && (r1 != r2 || c1 != c2)) {
        printf("Error: Sizes must match for addition!\n");
        return;
    }
    if (choice == 2 && (c1 != r2)) {
        printf("Error: Columns of A must equal rows of B for multiplication!\n");
        return;
    }

    int A[r1][c1], B[r2][c2], Result[r1][c2];

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < r1; i++) for (int j = 0; j < c1; j++) scanf("%d", &A[i][j]);
    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < r2; i++) for (int j = 0; j < c2; j++) scanf("%d", &B[i][j]);

    if (choice == 1) {
        printf("Addition Result:\n");
        fprintf(file, "Matrix Addition:\n");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                Result[i][j] = A[i][j] + B[i][j];
                printf("%d ", Result[i][j]);
                fprintf(file, "%d ", Result[i][j]);
            }
            printf("\n"); fprintf(file, "\n");
        }
    } else if (choice == 2) {
        printf("Multiplication Result:\n");
        fprintf(file, "Matrix Multiplication:\n");
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c2; j++) {
                Result[i][j] = 0;
                for (int k = 0; k < c1; k++)
                    Result[i][j] += A[i][k] * B[k][j];
            }

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                printf("%d ", Result[i][j]);
                fprintf(file, "%d ", Result[i][j]);
            }
            printf("\n"); fprintf(file, "\n");
        }
    } else {
        printf("Invalid choice!\n");
    }
}
