#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>

class InternetShop {
private:
    std::string shopName;
    double tvPrice;
    int purchaseCount;

public:
    InternetShop(const std::string& name, double price, int count) {
        setShopName(name);
        setTvPrice(price);
        setPurchaseCount(count);
    }

    void setShopName(const std::string& name) {
        if (name.empty()) {
            throw std::invalid_argument("У магазина должно быть название");
        }
        shopName = name;
    }

    void setTvPrice(double price) {
        if (price <= 0) {
            throw std::invalid_argument("Цена телевизора меньше 0, повышай");
        }
        if (price > 300000) {
            throw std::invalid_argument("Цена телевизора слишком дорогая, понижай");
        }
        tvPrice = price;
    }

    void setPurchaseCount(int count) {
        if (count < 0) {
            throw std::invalid_argument("Товары не могут быть 0 или меньше 0");
        }
        if (count > 100) {
            throw std::invalid_argument("Товаров может быть только 100, не больше");
        }
        purchaseCount = count;
    }

    std::string getShopName() const { return shopName; }
    double getTvPrice() const { return tvPrice; }
    int getPurchaseCount() const { return purchaseCount; }

    double calcRevenue() const {
        return tvPrice * purchaseCount;
    }

    void setRevenueOnly(double revenue) {
        if (revenue < 0) {
            throw std::invalid_argument("Меньше нуля нельзя заработать с продажи");
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        InternetShop shop("PoliTechMarket", 300000, 100);

        std::cout << "Магазин: " << shop.getShopName() << std::endl;
        std::cout << "Цена телевизора: " << std::fixed << std::setprecision(0)
            << shop.getTvPrice() << " руб." << std::endl;
        std::cout << "Количество покупок: " << shop.getPurchaseCount() << std::endl;
        std::cout << "Общая выручка: " << std::fixed << std::setprecision(0)
            << shop.calcRevenue() << " руб." << std::endl;

        shop.setRevenueOnly(300000);


    }
    catch (const std::exception& e) {
        std::cerr << "Одна ошибка, и ты ошибся\n" << e.what() << std::endl;
    }

    return 0;
}
