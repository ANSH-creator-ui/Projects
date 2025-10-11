/*

int authenticate(FILE *file) {
    char username[20], password[20];
    char user[20],pass[20];

    printf("=== Register User Authentication ===\n");
    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);
    printf("=== Login User Authentication ===\n");
    printf("enter user ");
    scanf("%s",user);
    printf("enter pass");
    scanf("%s",pass);


    // Hardcoded credentials for simplicity
    if (strcmp(username,user) == 0 && strcmp(password,pass) == 0) {
        printf("Login successful!\n");
        fprintf(file," %s ",user);
        return 1;
    } else {
        printf("Authentication failed! Exiting program.\n");
        return 0;
    }
}
*/

#include <stdio.h>
#include <string.h>

// Function to register a new user (writes to file)
void register_user() {
    char username[50], password[50];
    FILE *fp = fopen("credentials.txt", "a");  // "w" creates or overwrites

    if (!fp) {
        printf("Error creating credentials file.\n");
        return;
    }

    printf("=== Register ===\n");
    printf("Choose a username: ");
    scanf("%s", username);

    printf("Choose a password: ");
    scanf("%s", password);

    fprintf(fp, "%s %s\n", username, password);  // Save to file
    fclose(fp);

    printf("Registration successful!\n");
}

// Function to login (reads from file)

int login(FILE *file) {
    char stored_user[50], stored_pass[50];
    char input_user[50], input_pass[50];
    FILE *fp = fopen("credentials.txt", "r");

    if (!fp) {
        printf("No registered user found. Please register first.\n");
        return 0;
    }

    printf("=== Login ===\n");
    printf("Username: ");
    scanf("%s", input_user);

    printf("Password: ");
    scanf("%s", input_pass);
    //fprintf(file,"%s",input_user);

    int found = 0;
    while (fscanf(fp, "%s %s", stored_user, stored_pass) != EOF) {
        if (strcmp(stored_user, input_user) == 0 && strcmp(stored_pass, input_pass) == 0) {
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found) {
        printf("Login successful!\n");
        fprintf(file, "%s ", input_user);  // Log username
        return 1;
    } else {
        printf("Login failed. Invalid credentials.\n");
        return 0;
    }
}
