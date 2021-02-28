#include <iostream>
#include <clocale>
#include <vector>
#include <algorithm>

void print(std::vector<int> v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
}

void repeat_remover(std::vector<int> &v, int n) // удаляем повторяющиеся элементы
{
    int count = std::count_if(std::begin(v), std::end(v), [n](int elem) {return elem == n; });
    if (count != 1)
    {
        auto it = std::find_if(std::begin(v), std::end(v), [n](int elem) {return elem == n; });
        v.erase(std::remove_if(it + 1, std::end(v), [n](int elem) {return elem == n; }), std::end(v));
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector <int> p1;
    for (size_t i = 0; i < 10; ++i)
    {
        p1.push_back(i + 1);
    }
    int N = 0;
    std::cout << "Сколько чисел хотите ввести?" << std::endl;
    std::cin >> N;
    for (size_t i = 0; i < N; ++i)
    {
        int a = 0;
        std::cout << "Введите " << i + 1 << "-ое число: " << std::endl;
        std::cin >> a;
        p1.push_back(a);
    }

    std::cout << std::endl;

    std::cout << "Последовательность П1: " << std::endl;
    print(p1);
    std::cout << std::endl;

    //std::random_shuffle(std::begin(p1), std::end(p1)); // перемешиваем в случайном порядке
    //print(p1);
    //std::cout << std::endl;

    /*for (size_t i = 0; i < p1.size(); i++)
    {
        repeat_remover(p1, p1[i]);
    }*/

    //int odd_count = std::count_if(std::begin(p1), std::end(p1), [](int elem) {return elem % 2 == 1; });
    //std::cout << "Нечётных чисел в П1: " << odd_count << std::endl;

    int p1_max = p1[0], p1_min = p1[0];
    for (size_t i = 0; i < p1.size(); i++)
    {
        if (p1[i] > p1_max)
        {
            p1_max = p1[i];
        }
        if (p1[i] < p1_min)
        {
            p1_min = p1[i];
        }
    }
    std::cout << "Максимальный элемент П1: " << p1_max << std::endl;
    std::cout << "Минимальный элемент П1: " << p1_min << std::endl;

    //std::cout << "Последовательность П1: " << std::endl;
    //print(p1);
    return EXIT_SUCCESS;
}

