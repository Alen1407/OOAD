#include <iostream>
#include <cstring>

using namespace std;

class Dog{
    int age;
    char* name;
    int energy;
    
public:
    Dog(char*, int);
    char* getname() const;
    void bark() const;
    void rest();
    void bring_the_ball();
    
};

Dog::Dog(char* c, int n) : name(c), age(n), energy(5) {}

char* Dog::getname() const{
    return name;
}

void Dog::bark() const{
    std::cout << "Haf Haf" << std::endl;
}

void Dog::rest(){
    energy++;
}

void Dog::bring_the_ball(){
    if(energy <= 0){
        std::cout << "No, I'm tired" << std::endl;
        return;
    }
    
    energy--;
    std::cout << "Done!" << std::endl;
}

//------------------------------------------------------------------------------

class Helicopter{
    char* model;
    char* location;
    int capacity;

public:
    Helicopter(char*, char*, int);
    char* getmodel() const;
    char* getlocation() const;
    int getcapacity();
    
    void fly(char*);
};

Helicopter::Helicopter(char* model, char* location, int cap) 
    : model(model)
    , location(location)
    , capacity(cap){}
    
char* Helicopter::getmodel() const{
    return model;
}

char* Helicopter::getlocation() const{
    return location;
}

void Helicopter::fly(char* loc){
    location = loc;
}

//------------------------------------------------------------------------------

class Hospital{
    string name;
    string location;
    int floors;
    int available_rooms;
    
public:
    Hospital(string, string, int, int);
    string getlocation() const;
    int getfloors() const;
    int getavailablerooms() const;
    void new_client();
    void treat();
};

Hospital::Hospital(string name, string loc, int floors = 3, int a_r = 10) 
    : name(name)
    , location(loc)
    , floors(floors)
    , available_rooms(a_r){}
    
string Hospital::getlocation() const { return location; }
int Hospital::getfloors() const { return floors; }
int Hospital::getavailablerooms() const { return available_rooms; }

void Hospital::new_client(){ 
    available_rooms--;
    cout << "New client registered!" << endl;
}

void Hospital::treat(){
    available_rooms++;
    cout << "One client is treated" << endl;
}

int main()
{
    cout << "--------------------------Dog-------------------------------" << endl;
    
    char name[] = "Jack";
    Dog dog(name, 5);
    std::cout << dog.getname() << std::endl;
    for(int i = 0; i < 6; i++){
        dog.bring_the_ball();
    }
    dog.rest();
    dog.bring_the_ball();
    
    cout << "--------------------------Helicopter-------------------------------" << endl;
    
    Helicopter helicopter("fly", "Yerevan", 5);
    std::cout << helicopter.getlocation() << std::endl;
    std::cout << helicopter.getmodel() << std::endl;
    helicopter.fly("London");
    std::cout << helicopter.getlocation() << std::endl;
    
    cout << "--------------------------Hospital-------------------------------" << endl;
    
    Hospital hospital("Erebuni", "Yerevan");
    cout << hospital.getlocation() << endl;
    cout << hospital.getfloors() << endl;
    cout << hospital.getavailablerooms() << endl;
    hospital.new_client();
    cout << hospital.getavailablerooms() << endl;
    hospital.treat();
    cout << hospital.getavailablerooms() << endl;

    return 0;
}

