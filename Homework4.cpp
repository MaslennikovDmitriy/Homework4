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
    int N = 0;
    std::cout << "Сколько чисел хотите ввести?" << std::endl;
    std::cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        int a = 0;
        std::cout << "Введите " << i + 1 << "-ое число: " << std::endl;
        std::cin >> a;
        p1.push_back(a);
    }

    //std::cout << "Последовательность П1: " << std::endl;
    //for (size_t i = 1; i < p1.size(); i++)
    //{
    //    std::cout << p1[i] << std::endl;
    //}
    return EXIT_SUCCESS;
}

