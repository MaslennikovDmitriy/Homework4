#include <iostream>
#include <clocale>
#include <vector>
#include <algorithm>
#include <numeric>

void print(std::vector<int> v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
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

void sqr_transform(int &n)
{
    n = n * n;
}

void p2_transform(int& n)
{
    n = 1;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector <int> p1;
    //std::vector<int> p1 = { 4, 6, 59, 8, 10};
    for (size_t i = 0; i < 10; ++i)
    {
        p1.push_back(i + 1);
    }
    int N1 = 0;
    std::cout << "Сколько чисел хотите ввести?" << std::endl;
    std::cin >> N1;
    for (size_t i = 0; i < N1; ++i)
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


    /*int p1_max = p1[0], p1_min = p1[0];
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
    std::cout << "Минимальный элемент П1: " << p1_min << std::endl;*/


    /*for (size_t i = 0; i < p1.size(); i++)
    {
        size_t count = 0;
        for (int j = 1; j <= p1[i]; j++)
        {
            if (p1[i] % j == 0)
            {
                count++;
            }
        }
        if (count <= 2)
        {
            std::cout << "Есть простое число: " << i + 1 << "-ый элемент - " << p1[i] << std::endl;
            break;
        }
        else if (i == p1.size() - 1) 
        {
            std::cout << "Нет простых чисел" << std::endl;
        }
    }*/


    //std::for_each(std::begin(p1), std::end(p1), sqr_transform);


    std::vector<int> p2(p1.size());
    for (size_t i = 0; i < p2.size(); i++)
    {
        p2[i] = rand() % 100;
    }


    //int p2_sum = std::accumulate(std::begin(p2), std::end(p2), 0, [](int sum, int elem) {return sum += elem; });
    //std::cout << "Сумма элементов П2: " << p2_sum << std::endl;

    
    /*auto N2 = 0;
    std::cout << "Сколько элементов хотите заменить?" << std::endl;
    std::cin >> N2;
    if (N2 > p2.size())
    {
        std::cerr << "Выход за границу последовательности" << std::endl;
        return EXIT_FAILURE;
    }
    std::for_each(std::begin(p2), std::end(p2) - p2.size() + N2, p2_transform);*/

    std::vector<int> p3(p2.size());
    //std::vector<int> p3 = {2, -87, 56, -90, -567, 345, 23452, -42, 0, -89, 56, -1};
    for (size_t i = 0; i < p3.size(); i++)
    {
        p3[i] = p2[i] - p1[i];
    }


    std::cout << "Последовательность П2: " << std::endl;
    print(p2);
    std::cout << std::endl;
    std::cout << "Последовательность П3: " << std::endl;
    print(p3);
    std::cout << std::endl;

    /*int p3_count = std::count_if(std::begin(p3), std::end(p3), [](int elem) {return elem < 0; });
    for (size_t i = 0; i < p3_count; i++)
    {
        auto it = std::find_if(std::begin(p3), std::end(p3), [](int elem) {return elem < 0; });
        *it = 0;
    }
    std::cout << "Последовательность П3: " << std::endl;
    print(p3);
    std::cout << std::endl;
    p3.erase(std::remove_if(std::begin(p3), std::end(p3), [](int elem) {return elem == 0; }), std::end(p3));
    std::cout << "Последовательность П3: " << std::endl;
    print(p3);
    std::cout << std::endl;*/
    for (size_t i = 0; i < p3.size() / 2; i++)
    {
        std::swap(p3[i], p3[p3.size() - 1 - i]);
    }
    std::cout << "Последовательность П3: " << std::endl;
    print(p3);
    std::cout << std::endl;
    return EXIT_SUCCESS;
}

