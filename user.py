import shopping_cart
import product
import user_database
import warehouse
class User:
    def __init__(self, login:str, password:str):
        self.login = login
        self.password = password
        self.shopping_card = shopping_cart.Shopping_card()
        self.is_active = False
        user_database.User_database.users.append(self)

    def buy(self, smth:product.Product):
        if self.is_active:
            if smth in warehouse.Warehouse.products:
                self.shopping_card.ls.append(smth)
                self.shopping_card.spendings += smth.price
                warehouse.Warehouse.products.remove(smth)
            else:
                print("There is no product left")
        else:
            print("Log in into the system")

    def exit_user(self):
        self.is_active = False
