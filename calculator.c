#include <stdio.h>
#include <math.h>

void print_menu();
double divide(double, double);
double modulus(int, int);

int main()
{
    while (1)
    {
        int choice;
        print_menu();

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            continue;
        }

        if (choice == 7)
        {
            break;
        }

        if (choice < 1 || choice > 7)
        {
            printf("Please enter a valid operation number\n");
            continue;
        }

        double first, second, result;

        printf("enter the first number : ");
        scanf("%lf", &first);
        printf("enter the second number : ");
        scanf("%lf", &second);

        switch (choice)
        {
        case 1: // Add
            result = first + second;
            break;

        case 2: // Subtract
            result = first - second;
            break;

        case 3: // Multiply
            result = first * second;
            break;

        case 4: // Divide
            result = divide(first, second);
            break;

        case 5: // Modulus
        {
            printf("Note: Modulus uses integer values.\n");
            int a = (int)first;
            int b = (int)second;
            result = modulus(a, b);
            break;
        }

        case 6: // Power
            result = pow(first, second);
            break;
        }

        if (!isnan(result))
        {
            printf("The result of the operation is : %.2f\n", result);
        }
    }
    return 0;
}

void print_menu()
{
    printf("\n=== Simple Calculator ===\n");
    printf("\nChoose what operation you want to perform");
    printf("\n1.Add");
    printf("\n2.Subtract");
    printf("\n3.Multiply");
    printf("\n4.Divide");
    printf("\n5.Modulus");
    printf("\n6.Power");
    printf("\n7.Exit");
    printf("\nEnter the operation number : ");
}

double divide(double a, double b)
{
    if (b == 0)
    {
        fprintf(stderr, "division by zero is not valid\n");
        return NAN;
    }
    return a / b;
}

double modulus(int a, int b)
{
    if (b == 0)
    {
        fprintf(stderr, "modulus by zero is not valid\n");
        return NAN;
    }
    return a % b;
}