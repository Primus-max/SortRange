// В функцию передаётся массив случайных
// чисел в диапазоне от - 20 до + 20. Необходимо найти позиции крайних
// отрицательных элементов(самого левого
// отрицательного элемента и самого правого отрицательного элемента) и отсортировать элементы, находящиеся  между ними.

#include <iostream>
#include <windows.h>
#include <random>
using namespace std;

// Заполнение одномерного массива случайными значениями
template <typename T>
void FillArray(T arr[], int size, int satrtRange, int finishRange);

// Вывод массива на экран
template <typename T>
void PrintArray(T arr[], int size);

// Сортировка массива усовершенствованным пузырьковым методом
template<typename T>
void SortingProgressingBubble(T arr[], int size);

// Сортировка массива усовершенствованным пузырьковым методом
template<typename T>
void SortRage(T arr[], int size);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size = 30;
    int Array[size];
    FillArray(Array, size, -20, 20);
    cout << "Заполненный массив : " << endl;
    PrintArray(Array, size);

    cout << "------------------------------------------------" << endl;

    //SortingProgressingBubble(Array, size);  
    //cout << "Отсортированный массив : " << endl;
    //PrintArray(Array, size);

    //cout << "------------------------------------------------" << endl;

    SortRage(Array, size);
    cout << "Отсортированный массив в диапазоне: " << endl;
    PrintArray(Array, size);
}

template <typename T>
void FillArray(T arr[], int size, int startRange , int finishRange) {
    random_device random;   

    for (size_t i = 0; i < size; i++) {
        arr[i] = random() % (finishRange - startRange + 1) + startRange;
    }
};

template <typename T>
void PrintArray(T arr[], int size) {
    for (size_t i = 0; i < size; i++) {
        cout << "[" << arr[i] << "]";
    }
    cout << endl;
};

template<typename T>
void SortingProgressingBubble(T arr[], int size) {
    for (size_t j = size - 1; j > 0; --j)
    {
        for (size_t i = 0; i < j; ++i)
        {
            T temp = 0;
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
};


template<typename T>
void SortRage(T arr[], int size) {
    // Левый
    int leftNegIndex = -1;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            leftNegIndex = i;
            break;
        }
    }

    // Если нет отрицательных элементов
    if (leftNegIndex == -1) {
        cout << "Отрицательных элементов нет" << endl;
        return;
    }

    // Правый
    int rightNegIndex = -1;
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] < 0) {
            rightNegIndex = i;
            break;
        }
    }

    // Если один отрицательный элемент, возвращаемся
    if (rightNegIndex == leftNegIndex || rightNegIndex == leftNegIndex + 1) {
        cout << "Только один отрицательный элемент в, задача не выполнима" << endl;
        return;
    }

    // Сортировка элементов 
    for (int i = leftNegIndex + 1; i < rightNegIndex; ++i) {
        for (int j = leftNegIndex + 1; j < rightNegIndex; ++j) {
            if (arr[j] < arr[j - 1]) {
                T temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}