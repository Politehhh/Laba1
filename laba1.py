class InternetShop:
    def __init__(self, name: str, price: float, count: int):
        self.set_shop_name(name)
        self.set_tv_price(price)
        self.set_purchase_count(count)

    def set_shop_name(self, name: str):
        if not name.strip():
            raise ValueError("У магазина должно быть название")
        self._shop_name = name

    def set_tv_price(self, price: float):
        if price <= 0:
            raise ValueError("Цена телевизора меньше 0, повышай")
        if price > 300_000:
            raise ValueError("Цена телевизора слишком дорогая, понижай")
        self._tv_price = price

    def set_purchase_count(self, count: int):
        if count < 0:
            raise ValueError("Товары не могут быть 0 или меньше 0")
        if count > 100:
            raise ValueError("Товаров может быть только 100, не больше")
        self._purchase_count = count

    def get_shop_name(self) -> str:
        return self._shop_name

    def get_tv_price(self) -> float:
        return self._tv_price

    def get_purchase_count(self) -> int:
        return self._purchase_count

    def calc_revenue(self) -> float:
        return self._tv_price * self._purchase_count

    def set_revenue_only(self, revenue: float):
        if revenue < 0:
            raise ValueError("Меньше нуля нельзя заработать с продажи")
            
def main():
    try:
        shop = InternetShop("PoliTechMarket", 300_000, 100)

        print(f"Магазин: {shop.get_shop_name()}")
        print(f"Цена телевизора: {shop.get_tv_price():.0f} руб.")
        print(f"Количество покупок: {shop.get_purchase_count()}")
        print(f"Общая выручка: {shop.calc_revenue():.0f} руб.")

        shop.set_revenue_only(300_000)

    except ValueError as e:
        print("Одна ошибка, и ты ошибся")
        print(e)


if __name__ == "__main__":
    main()
