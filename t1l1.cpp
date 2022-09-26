/*7.Product: Наименование, Производитель, Цена, Срок хранения, Количество.
Создать массив объектов. 
Вывести:
а) список товаров для заданного наименования; 
б) список товаров для заданного наименования, цена которых не превышает указанной;
в) список товаров, срок хранения которых больше заданного.*/

#include <conio.h>
#include <string.h>
#include <iostream>
#include <windows.h>


using namespace std;

class product {
    char ProductName[30] /*Наименование продукта*/, Manufacturer[30]; /*Производитель*/
    int Price /*Цена*/, ShelfLife /*Срок хранения*/, Amount /*Количество*/;

public:

    product(); /*Конструктор по умолчанию*/
    void set(); /*Иницилизация переменных*/
    char* getProductName(); /*Возвращаем наименование продукта*/
    int getShelfLife(); /*Возвращаем срок хранения*/
    int getPrice(); /*Возвращаем цену*/
    void show(); /*Выводим список продуктов с описанием*/
};

product::product() /*Конструктор*/ {
    *ProductName = '\0';
    *Manufacturer = '\0'; 
    Price = 0; 
    ShelfLife = 0; 
    Amount = 0; 
}

void product::set() /*Иницилизация переменных*/ {
    cout << "Наименование: ";
    cin >> ProductName;
    cout << "Производитель: ";
    cin >> Manufacturer;
    cout << "Цена: ";
    cin >> Price;
    cout << "Срок хранения: ";
    cin >> ShelfLife;
    cout << "Количество: ";
    cin >> Amount;
    cout << endl;
}

void product::show() /*Вывод списка продуктов с описанием*/ {
    cout << "Наименование: " << ProductName << endl;
    cout << "Производитель: " << Manufacturer << endl;
    cout << "Цена: " << Price << endl;
    cout << "Срок хранения: " << ShelfLife << endl;
    cout << "Количество: " << Amount << endl;
}

    char* product::getProductName() {
        return ProductName;
    }

    int product::getShelfLife() {
        return ShelfLife;
    }

    int product::getPrice() {
        return Price;
    }



void ListProductName(product list[], int n) /*Вывод списка товаров для заданного наименования*/ {
    char InputProductName[30];
    cout << "А) Введите наименование товара: ";
    cin >> InputProductName;
    cout << "\nСписок товаров с заданным названием:\n";
    for (int i(0); i < n; i++) /*Перебираем все списки товаров*/
        if (strcmp(list[i].getProductName(), InputProductName) == 0) /*Если наименование из списка совпадает с введённым*/
            cout << list[i].getProductName() << i + 1 << endl; /*Вывод i наименования с индексом i */
}

void ListNameLessPrice(product list[], int n) /*Вывод списка товаров заданного наименования, цена которых не превышает указанной*/ {
    char InputProductName[30];
    int InputPrice;
    cout << "Б) Введите наименование товара: ";
    cin >> InputProductName;
    cout << "\nВведите цену: ";
    cin >> InputPrice;
    cout << "\nСписок товаров не превышающих стоимости " << InputPrice << "\n";
    for (int i(0); i < n; i++) /*Перебираем все списки товаров*/
        if ((strcmp(list[i].getProductName(), InputProductName) == 0) && list[i].getPrice() <= InputPrice) /*Если наименование совпадает с заданным и цена  не превышает указанной*/
            cout << list[i].getProductName() << i + 1 << endl; /*Вывод i наименования с индексом i*/
}

void ListShelfLife(product list[], int n) /*Вывод списка товаров, срок хранения которых больше заданного*/ {
    int InputShelfLife;
    cout << "В) Введите срок хранения: ";
    cin >> InputShelfLife;
    cout << "\nСписок товаров, срок которых больше " << InputShelfLife << " дней:\n";
    for (int i(0); i < n; i++) /*Перебираем все списки товаров*/
        if (list[i].getShelfLife() > InputShelfLife) /*Если срок хранения больше введённого*/
            cout << list[i].getProductName() << i + 1 << endl; /*Вывод i наименования с индексом i*/
}

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    product* list; /*Массив объектов класса product*/
    
    int n;
    cout << "Количество товаров: ";
    cin >> n;
    list = new product[n]; /*Создание динамического массива списков товаров*/

    for (int i(0); i < n; i++) /*Перебираем все списки товаров*/
        list[i].set(); /*Иницилизация переменных*/

    for (int i(0); i < n; i++) /*Вывод списка товаров*/ {
        cout << "------------------------------" << endl;
        list[i].show();
    }

    ListProductName(list, n); /*Передаем в функцию массив из списка и количество товаров*/
    ListNameLessPrice(list, n); /*Передаем в функцию массив из списка и количество товаров*/
    ListShelfLife(list, n); /*Передаем в функцию массив из списка и количество товаров*/

    delete[] list; /*Удаляем динамическое выделение*/
    system("pause");
    return 0;
}