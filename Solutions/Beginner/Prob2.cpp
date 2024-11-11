#include <iostream>

int main()
{
    int num1, num2;

    std::cout << "Enter two integers: ";
    std::cin >> num1 >> num2;

    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    double quotient = 0.0f;
    if (num2 != 0)
    {
       quotient = (double)num1 / num2; // Cast to double for accurate division
    }
    
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quotient: " << quotient << std::endl;

    return 0;
}
