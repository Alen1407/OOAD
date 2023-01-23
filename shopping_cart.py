class Shopping_card:
    def __init__(self):
        self.ls = []
        self.spendings = 0

    def remove(self, product:str):
        for i in self.ls:
            if i.name == product:
                self.ls.remove(i)
                self.spendings -= i.price
                break
    
