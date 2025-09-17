#include <iostream>
#include <string>
using namespace std;

class InternetShop {
private:
    string storeName;
    double tvPrice;
    int purchases;

public:
    // Конструктор с проверкой
    InternetShop(string name, double price, int count) {
        storeName = name;
        setTvPrice(price);
        setPurchases(count);
    }

    // Геттеры
    string getStoreName() { return storeName; }
    double getTvPrice() { return tvPrice; }
    int getPurchases() { return purchases; }

    // Сеттеры с проверкой
    void setTvPrice(double price) {
        if (price > 0) tvPrice = price;
        else {
            cout << "Ошибка: цена должна быть положительной! Установлено значение 1.\n";
            tvPrice = 1;
        }
    }

    void setPurchases(int count) {
        if (count >= 0) purchases = count;
        else {
            cout << "Ошибка: количество покупок не может быть отрицательным! Установлено значение 0.\n";
            purchases = 0;
        }
    }

    // Метод подсчета выручки
    double getRevenue() {
        return tvPrice * purchases;
    }
};

int main() {
    // Данные заданы в коде
    InternetShop shop("BestTV", 1200.5, 15);

    cout << "Магазин: " << shop.getStoreName() << endl;
    cout << "Цена телевизора: " << shop.getTvPrice() << " BYN" << endl;
    cout << "Количество покупок: " << shop.getPurchases() << endl;
    cout << "Общая выручка: " << shop.getRevenue() << " BYN" << endl;

    return 0;
}
