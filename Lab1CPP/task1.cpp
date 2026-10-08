#include <fstream>
#include <iostream>
#include "array.h"

using namespace std;
//создание и заполнение массива
Array *array_create_and_read(istream &input)
{
    int n;
    if (!(input >> n) || n < 0)
        return nullptr;

    Array *arr = array_create(static_cast<size_t>(n));
    for (size_t i = 0; i < array_size(arr); i++)
    {
        int x;
        if (!(input >> x))
        {
            array_delete(arr);
            return nullptr;
        }
        array_set(arr, i, x);
    }
    return arr;
}

//cчитает положительные, отрицательные и нулевые числа
void task1(const Array *arr)
{
    int positive = 0;
    int negative = 0;
    int zero = 0;

    for (size_t i = 0; i < array_size(arr); i++)
    {
        Data value = array_get(arr, i);
        if (value > 0)
            positive++;
        else if (value < 0)
            negative++;
        else
            zero++;
    }

    cout << "positive: " << positive << ", negative: " << negative << ", zero: " << zero << ".\n";
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "usage: " << argv[0] << " input.txt\n";
        return 1;
    }

    ifstream input(argv[1]);
    if (!input.is_open())
    {
        cout << "cannot open file " << argv[1] << "\n";
        return 1;
    }

    Array *arr = array_create_and_read(input);
    if (arr == nullptr)
    {
        cout << "invalid input data\n";
        return 1;
    }

    task1(arr);
    array_delete(arr);
    return 0;
}