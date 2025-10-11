
void display_user_report() {
    char search_user[50];
    char line[256];
    FILE *file = fopen("calculator_results.txt", "r");

    if (!file) {
        printf("Error opening results file.\n");
        return;
    }

    printf("Enter username to view report: ");
    scanf("%s", search_user);

    printf("\n--- History of %s ---\n", search_user);
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, search_user)) {
            printf("%s", line);
            found = 1;
        }
    }

    if (!found) {
        printf("No records found for user: %s\n", search_user);
    }

    fclose(file);
}