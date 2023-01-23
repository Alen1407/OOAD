import user_database
import user
import product
import shopping_cart

def log_in(login:str, password:str):
    for user in user_database.User_database.users:
        if user.login == login and user.password == password:
            user.is_active = True

user1 = user.User("Jack", "111111")
user2 = user.User("John", "222222")
log_in("Jack", "111111")
iphone = product.Product("Iphone", 1000)
user1.buy(iphone)
user1.buy(iphone)
user2.buy(iphone)
print(user1.shopping_card.spendings)
user1.shopping_card.remove("Iphone")
print(user1.shopping_card.spendings)
print(user_database.User_database.users)
