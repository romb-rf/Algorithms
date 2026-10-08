#include <fstream>
#include <iostream>
#include "array.h"

using namespace std;

const int MAX_VALUE = 1000;


Array *array_create_and_read(istream &input)
{
    int n;
    if (!(input >> n) || n < 0)
        return nullptr;

    Array *arr = array_create(static_cast<size_t>(n));
    for (size_t i = 0; i < array_size(arr); i++)
    {
        int x;
        if (!(input >> x) || x < 0 || x > MAX_VALUE)
        {
            array_delete(arr);
            return nullptr;
        }
        array_set(arr, i, x);
    }
    return arr;
}

//выводит элементы которые встречаются в массиве ровно один раз
void task2(const Array *arr)
{
    int counts[MAX_VALUE + 1] = {0};

    for (size_t i = 0; i < array_size(arr); i++)
        ++counts[array_get(arr, i)];

    cout << "unique:";
    for (size_t i = 0; i < array_size(arr); ++i)
    {
        Data value = array_get(arr, i);
        if (counts[value] == 1)
            cout << " " << value;
    }
    cout << ".\n";
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

    task2(arr);
    array_delete(arr);
    return 0;
}