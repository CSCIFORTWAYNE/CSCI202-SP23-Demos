#include <iostream>
#include <string>
#include <climits>

int getInt(std::string, bool (*func)(int, int, int), int = 0, int = 0);
void resetStream();
bool intGreaterThan0(int, int, int);
bool intInRange(int, int, int);
long fibNum(int, int, int, long[]);

int main()
{
    int firstNum, secondNum;
    int n;
    long *sequence;
    firstNum = getInt("Enter the first Fibonacci number:", intInRange, 0, 10);
    secondNum = getInt("Enter the second Fibonacci number:", intInRange, firstNum + 1, firstNum + 10);
    n = getInt("Enter the number of Fibonaci numbers to generate:", intGreaterThan0);
    sequence = new long[n];
    sequence[0] = firstNum;
    sequence[1] = secondNum;
    for (int i = 2; i < n; i++)
    {
        sequence[i] = 0;
    }
    fibNum(firstNum, secondNum, n, sequence);
    for (int i = 0; i < n; i++)
    {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

int getInt(std::string prompt, bool (*func)(int, int, int), int low, int high)
{
    int x;
    std::cout << prompt << " ";
    std::cin >> x;
    std::cout << std::endl;
    if (std::cin && func(x, low, high))
    {
        return x;
    }
    else if (!std::cin)
    {
        resetStream();
    }
    x = getInt(prompt, func, low, high);
    return x;
}

void resetStream()
{

    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "You entered something that is not a number." << std::endl;
}

bool intGreaterThan0(int x, int, int)
{
    if (x < 0)
        std::cout << "The number must be greater than 0." << std::endl;

    return x > 0;
}

bool intInRange(int x, int low, int high)
{
    if (x < low || x > high)
        std::cout << "The number should be between " << low << " and " << high << std::endl;
    return x >= low && x <= high;
}

long fibNum(int first, int second, int n, long seq[])
{

    if (n == 1)
    {
        return first;
    }
    else if (n == 2)
    {
        return second;
    }
    else
    {
        if (seq[n - 1] == 0)
        {
            seq[n - 1] = fibNum(first, second, n - 1, seq) + fibNum(first, second, n - 2, seq);
        }
        return seq[n - 1];
    }
}
