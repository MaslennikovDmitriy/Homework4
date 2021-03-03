#include <iostream>
#include <clocale>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

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

    // Пункт 1

    std::vector <int> p1;
    //std::vector<int> p1 = { 4, 6, 59, 8, 10};
    for (size_t i = 0; i < 10; ++i) 
    {
        p1.push_back(i + 1);
    }
    std::cout << "Создана последовательность целых чисел П1: " << std::endl;
    print(p1);
    std::cout << std::endl;

    // Пункт 2

    int N1 = 0;
    std::cout << "Сколько чисел хотите ввести?" << std::endl;
    std::cin >> N1;
    std::istream_iterator<int> ii(std::cin);
    for (int i = 0; i < N1; i++)
    {
        p1.push_back(*ii);
        *ii++;
    }
    std::cout << "Добавили "<< N1 <<" чисел в конец последовательности П1: " << std::endl;
    print(p1);
    std::cout << std::endl;

    // Пункт 3

    std::random_shuffle(std::begin(p1), std::end(p1)); // перемешиваем в случайном порядке
    std::cout << "Перемешали П1 произвольным образом: " << std::endl;
    print(p1);
    std::cout << std::endl;

    // Пункт 4

    for (size_t i = 0; i < p1.size(); i++) // удаляем дубликаты в П1
    {
        repeat_remover(p1, p1[i]);
    }
    std::cout << "Удалили дубликаты в П1: " << std::endl;
    print(p1);
    std::cout << std::endl;

    // Пункт 5

    int odd_count = std::count_if(std::begin(p1), std::end(p1), [](int elem) {return elem % 2 == 1; });
    std::cout << "Нечётных чисел в П1: " << odd_count << std::endl;

    // Пункт 6

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

    // Пункт 7

    for (size_t i = 0; i < p1.size(); i++)
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
    }

    // Пункт 8

    std::for_each(std::begin(p1), std::end(p1), sqr_transform);
    std::cout << "Заменили все числа в П1 их квадратами: " << std::endl;
    print(p1);
    std::cout << std::endl;

    // Пункт 9

    std::vector<int> p2(p1.size());
    for (size_t i = 0; i < p2.size(); i++)
    {
        p2[i] = rand() % 100;
    }
    std::cout << "Создали последовательность П2 из " << p1.size() << " случайных чисел: " << std::endl;
    print(p2);
    std::cout << std::endl;

    // Пункт 10

    int p2_sum = std::accumulate(std::begin(p2), std::end(p2), 0, [](int sum, int elem) {return sum += elem; });
    std::cout << "Сумма элементов П2: " << p2_sum << std::endl;

    // Пункт 11
    
    auto N2 = 0;
    std::cout << "Сколько элементов хотите заменить?" << std::endl;
    std::cin >> N2;
    if (N2 > p2.size())
    {
        std::cerr << "Выход за границу последовательности" << std::endl;
        return EXIT_FAILURE;
    }
    std::for_each(std::begin(p2), std::end(p2) - p2.size() + N2, p2_transform);
    std::cout << "Заменили первые " << N2 << " чисел в П2 на единицу: " << std::endl;
    print(p2);
    std::cout << std::endl;

    // Пункт 12

    std::vector<int> p3(p1.size());
    //std::vector<int> p3 = {2, -87, 56, -90, -567, 345, 23452, -42, 0, -89, 56, -1};
    //for (size_t i = 0; i < p3.size(); i++)
    //{
    //    p3[i] = p2[i] - p1[i]; // обычная разность
    //}

    std::sort(std::begin(p1), std::end(p1));
    std::sort(std::begin(p2), std::end(p2));
    std::set_difference(std::begin(p1), std::end(p1), std::begin(p2), std::end(p2), std::begin(p3)); // логическая разность
    std::cout << "Создали последовательность П3 как разность П1 и П2: " << std::endl;
    print(p3);
    std::cout << std::endl;

    // Пункт 13

    int p3_count = std::count_if(std::begin(p3), std::end(p3), [](int elem) {return elem < 0; });
    for (size_t i = 0; i < p3_count; i++)
    {
        auto it = std::find_if(std::begin(p3), std::end(p3), [](int elem) {return elem < 0; });
        *it = 0;
    }
    std::cout << "Заменили все отрицательные элементы последовательности П3 нулем: " << std::endl;
    print(p3);
    std::cout << std::endl; 

    // Пункт 14

    p3.erase(std::remove_if(std::begin(p3), std::end(p3), [](int elem) {return elem == 0; }), std::end(p3));
    std::cout << "Удалили все нулевые элементы в последовательности П3: " << std::endl;
    print(p3);
    std::cout << std::endl;

    // Пункт 15

    for (size_t i = 0; i < p3.size() / 2; i++) // обратный порядок
    {
        std::swap(p3[i], p3[p3.size() - 1 - i]);
    }
    std::cout << "Изменили порядок элементов в последовательности П3 на обратный: " << std::endl;
    print(p3);
    std::cout << std::endl;

    // Пункт 16

    std::sort(std::begin(p3), std::end(p3), [](int a, int b) {return a > b; });
    std::cout << "3 максимальных элемента П3: " << p3[0] << " " << p3[1] << " " << p3[2] << std::endl;

    // Пункт 17

    std::sort(std::begin(p1), std::end(p1));
    std::sort(std::begin(p2), std::end(p2));
    std::cout << "Отсортировали последовательность П1 по возрастанию: " << std::endl;
    print(p1);
    std::cout << std::endl;
    std::cout << "Отсортировали последовательность П2 по возрастанию: " << std::endl;
    print(p2);
    std::cout << std::endl;

    // Пункт 18

    std::vector<int> p4(p1.size() + p2.size());
    std::merge(p1.begin(), p1.end(), p2.begin(), p2.end(), p4.begin());
    std::cout << "Создали последовательность П4 как слияние П1 и П2: " << std::endl;
    print(p4);
    std::cout << std::endl;

    // Пункт 19

    std::sort(p4.begin(), p4.end());
    size_t p4_counter = 0;
    for (size_t i = 0; i < p4.size(); i++)
    {
        if ((p4[i] <= 1) && (p4[i] >= 0))
        {
            p4_counter++;
        }
    }
    std::cout << "Диапазон для упорядоченной вставки 1 в П4: " << p4_counter << std::endl;

    // Пункт 20
    std::cout << "Последовательность П1: " << std::endl;
    std::unique_copy(p1.cbegin(), p1.cend(), std::ostream_iterator <int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "Последовательность П2: " << std::endl;
    std::unique_copy(p2.cbegin(), p2.cend(), std::ostream_iterator <int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "Последовательность П3: " << std::endl;
    std::unique_copy(p3.cbegin(), p3.cend(), std::ostream_iterator <int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "Последовательность П4: " << std::endl;
    std::unique_copy(p4.cbegin(), p4.cend(), std::ostream_iterator <int>(std::cout, " "));
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

