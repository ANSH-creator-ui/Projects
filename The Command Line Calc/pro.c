/*
 • ProblemDescription:
 The Command-Line Calculator Program is a C-based application
 designed to perform a wide range of mathematical operations. The
 system begins with a flowchart design to outline the program's
 workflow and logic. It includes basic arithmetic operations such as
 addition, subtraction, multiplication, and division, along with advanced
 mathematical functions like trigonometric calculations (sin, cos, tan)
 and logarithms (base 10). The program also supports matrix operations,
 enabling users to perform matrix addition and multiplication. A result
 management system is implemented to display outputs and store
 them in a file named calculator_results.txt for future reference. This
 project integrates key C programming concepts such as strings,
 pointers, functions and file handling to
 develop an efficient and user-friendly calculator*/


#include <string.h>
 #include <stdio.h>
#include <math.h>
#include "basicop.c"
#include "tri.c"
#include "log.c"
#include "mat.c"
#include "authn.c"
#include "displayhistory.c"
 void basic_operations(FILE *file);
void trigonometric_operations(FILE *file);
void logarithmic_operation(FILE *file);
void matrix_operations(FILE *file);
void register_user();
int login(FILE *file);
//int authenticate(FILE *file);

int main() {
    FILE *file = fopen("calculator_results.txt", "a");
    
    int ch;

    printf("1. Register\n2. Login\nChoose option: ");
    scanf("%d", &ch);

    if (ch == 1) {
        register_user();
        return 0;
    } else if (ch == 2) {
        if (!login(file)) {
            return 1;  // Exit if login fails
        }
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    // After successful login
    printf("\nWelcome to the calculator!\n");
    // Add calculator logic here...


    int choice;


    if (!file) {
        printf("Error opening file!\n");
        return 1;
    }

    do {
        printf("\n=== Calculator Menu ===\n");
        printf("1. Basic (+, -, *, /)\n2. Trigonometry (sin, cos, tan)\n3. Logarithm (base 10)\n4. Matrix (Add, Multiply)\n5. User History\n6. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: basic_operations(file); break;
            case 2: trigonometric_operations(file); break;
            case 3: logarithmic_operation(file); break;
            case 4: matrix_operations(file); break;
            case 5: display_user_report();break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid option!\n");
        }
    } while (choice != 6);

    fclose(file);
    return 0;
}

