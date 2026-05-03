#include <iostream>
using namespace std;

// Function pointer example: estimating time based on number of lines of code
// To use a function pointer, we define a function that takes a pointer to a
// function as an argument. The argument needs to have the same return type and
// parameters as the function pointer we want to use. In this example,
// we have two functions, time1 and time2, that estimate the time based on
// the number of lines of code.
// The estimate function takes an integer representing the number of lines and a
// function pointer that points to either time1 or time2.
void estimate(int lines, double (*func)(int))
{
    cout << "Estimated time: " << func(lines) << " seconds" << endl;
}

double time1(int lines)
{
    return 0.75 * lines;
}

double time2(int lines)
{
    return 0.5 * lines + 10;
}

int main()
{
    int lines = 75;
    estimate(lines, time1);
    estimate(lines, time2);
    return 0;
}