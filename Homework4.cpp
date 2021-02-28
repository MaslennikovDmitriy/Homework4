#include <iostream>
#include <clocale>
#include <vector>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector <int> p1(11);
    for (size_t i = 1; i <= 10; i++)
    {
        p1[i] = i;
    }
    return EXIT_SUCCESS;
}

