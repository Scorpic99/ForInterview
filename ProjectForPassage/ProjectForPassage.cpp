#include <iostream>

void Sorted(int* arrA, int lenght) {
    for (int j = 0; j < lenght - 2; ++j) {
        for (int i = 0; i < lenght - 1; ++i) {
            if (arrA[i] > arrA[i + 1]) {
                int temp = arrA[i];
                arrA[i] = arrA[i + 1];
                arrA[i + 1] = temp;
            }
        }
    }
}

void Merge(int* arrA, int p, int q, int length) {//P.S.в ТЗ не понятно было что нужно мёржить
    int* tempArr = new int[length + 1];
    int arrAAA;
    for (int i = 0; i < length; i++) {
        if (p > arrA[i] &&  p <= arrA[i+1]) {
            tempArr[i] = arrA[i];
            tempArr[i + 1] = p;
            for (; i < length - 1; i++)
            {
                tempArr[i + 2] = arrA[i + 1];
            }
        }
        else {
            tempArr[i] = arrA[i];
            arrAAA = arrA[i];
        }
    }
    for (int i = 0; i < length + 1; i++)
    {
        std::cout << tempArr[i] << "\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int A[]{ 5, 2, 4, 6, 1, 3, 2, 6 };
    int p;
    int sizeA = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < sizeA; i++)
    {
        std::cout << A[i] << "\n";
    }
    std::cout << "---------" << std::endl;

    std::cout << "Введите число p: ";
    std::cin >> p;
    if (p < sizeA) {
        int q = (p + sizeA) / 2;//roundHalfDown
        Sorted(A, sizeA);
        for (int i = 0; i < sizeA; i++)
        {
            std::cout << A[i] << "\n";
        }
        std::cout << "---------" << std::endl;
        Merge(A, p, q, sizeA);

    }
    else {
        std::cout << "Число p больше чем длина массива" << std::endl;
    }
}

