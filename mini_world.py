class Sun:
    is_day_time = True
    def change_day_time(self):
        self.is_day_time = not self.is_day_time
        print("Now it is day time") if self.is_day_time else print("Now it is night") 
        
class Tree:
    def make_air(self, sun : Sun):
        print("The tree is making air") if sun.is_day_time else print("The tree is not making air as it is night")
        
class Frog:
    x = 0
    y = 0
    is_on_the_grass = True
    def update_frog_position(self):
        if self.x > 3 and self.y > 3 and self.x < 5 and self.y < 5:
            self.is_on_the_grass = False
            return
        self.is_on_the_grass = True
    
    def move_right(self):
        self.x += 1
        self.update_frog_position()
    def move_left(self):
        self.x -= 1
        self.update_frog_position()
    def move_up(self):
        self.y += 1
        self.update_frog_position()
    def move_down(self):
        self.y -= 1
        self.update_frog_position()
    
    def is_sleeping(self, sun : Sun):
        return True if not sun.is_day_time else False
        
class Grass:
    area = 10
    def to_be_eaten(self, frog : Frog):
        if self.area <= 0:
            print("There is no grass. Wait till tommorow")
        elif frog.is_sleeping(sun):
            print("The frog can't eat the grass as it is sleeping. Call the sunrise to wake it up")
        elif not frog.is_on_the_grass:
            print("The frog can't eat the grass as it is on the lake. Move it to the grass")
        else:
            self.area -= 1
            print("The frog ate one m^2 area of grass")
    
    def add_area(self, sun : Sun):
        if sun.is_day_time:
            self.area += 1
            print("1 m^2 area of grass has been added")
        else:
            print("You can't add area in the night time")
    
sun = Sun()
tree = Tree()
grass = Grass()
frog = Frog()

sun.change_day_time()
tree.make_air(sun)
grass.to_be_eaten(frog)
sun.change_day_time()
for i in range(4):
    frog.move_right()
    frog.move_up()
grass.to_be_eaten(frog)
frog.move_left()
frog.move_left()
for i in range(11):
    grass.to_be_eaten(frog)
sun.change_day_time()
grass.add_area(sun)
sun.change_day_time()
grass.add_area(sun)
grass.to_be_eaten(frog)
