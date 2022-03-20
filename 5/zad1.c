#include <stdio.h>
int main()
{
    double num1, num2;
    char op;
    while (scanf("%lf %c %lf", &num1, &op, &num2) != EOF)
    {
        if (op == '+')
        {
            printf("%.2lf\n", num1 + num2);
        }    
        else if (op == '-')
        {
            printf("%.2lf\n", num1 - num2);
        }
        else if (op == 'x')
        {
            printf("%.2lf\n", num1 * num2);
        }
        else if (op == '/')
        {
            if (num2 == 0)
            {
                fprintf(stderr, "Zero divide error!\n");
                return -1;
            }
            printf("%.2lf\n", num1 / num2);
        }
        else 
        {
            fprintf(stderr, "Invalid operation!\n");
            return -1;
        }
    }
    return 0;
}