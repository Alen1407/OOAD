import warehouse
class Product:
    def __init__(self, name:str, price:int):
        self.name = name
        self.price = price
        self.features = {}
        warehouse.Warehouse.products.append(self)
        
    def set_features(self, color:str, weight:int):
        self.features["color"] = color
        self.features["weight"] = weight

