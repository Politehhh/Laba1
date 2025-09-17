class InternetShop:
    def __init__(self, store_name, tv_price, purchases):
        self._store_name = store_name
        self.tv_price = tv_price  # проверка в setter
        self.purchases = purchases  # проверка в setter

    @property
    def store_name(self):
        return self._store_name

    @property
    def tv_price(self):
        return self._tv_price

    @tv_price.setter
    def tv_price(self, value):
        if value > 0:
            self._tv_price = value
        else:
            print("Ошибка: цена должна быть положительной! Установлено значение 1.")
            self._tv_price = 1

    @property
    def purchases(self):
        return self._purchases

    @purchases.setter
    def purchases(self, value):
        if value >= 0:
            self._purchases = value
        else:
            print("Ошибка: количество покупок не может быть отрицательным! Установлено значение 0.")
            self._purchases = 0

    def get_revenue(self):
        return self._tv_price * self._purchases


# Данные заданы в коде
shop = InternetShop("BestTV", 1200.5, 15)

print("Магазин:", shop.store_name)
print("Цена телевизора:", shop.tv_price, "BYN")
print("Количество покупок:", shop.purchases)
print("Общая выручка:", shop.get_revenue(), "BYN")
