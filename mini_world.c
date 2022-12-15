#include <stdio.h>
#include <stdbool.h>

struct Sun{
    char is_day_time;
};

struct Tree{};

struct Frog{
    int x;
    int y;
    char is_on_the_grass;
};

struct Grass{
    int area;
};

struct Mini_World{
    struct Sun sun;
    struct Tree tree;
    struct Frog frog;
    struct Grass grass;
};


void Sun(struct Mini_World* ptr, char n){
    (ptr->sun).is_day_time = n;
}

void change_day_time(struct Mini_World* ptr){
    (ptr->sun).is_day_time = !(ptr->sun).is_day_time;
    if((ptr->sun).is_day_time == 1){
        printf("Now it is day time\n");
    }else{
        printf("Now it is night\n");
    }
    return;
}

void make_air(struct Mini_World* ptr){
    if((ptr->sun).is_day_time == 1){
        printf("The tree is making air\n");
    }else{
        printf("The tree is not making air as it is night\n");
    }
    return;
}

void update_frog_position(struct Mini_World* ptr){
    if((ptr->frog).x > 3 && (ptr->frog).y > 3 && (ptr->frog).x < 5 && (ptr->frog).y < 5){
        (ptr->frog).is_on_the_grass = 0;
        return;
    }
    (ptr->frog).is_on_the_grass = 1;
}

void Frog(struct Mini_World* ptr, int x, int y){
    (ptr->frog).x = x;
    (ptr->frog).y = y;
    update_frog_position(ptr);
}

void move_right(struct Mini_World* ptr){
    ((ptr->frog).x)++;
    update_frog_position(ptr);
}

void move_left(struct Mini_World* ptr){
    ((ptr->frog).x)--;
    update_frog_position(ptr);
}

void move_up(struct Mini_World* ptr){
    ((ptr->frog).y)++;
    update_frog_position(ptr);
}

void move_down(struct Mini_World* ptr){
    ((ptr->frog).y)--;
    update_frog_position(ptr);
}

bool is_sleeping(struct Mini_World* ptr){
    return (ptr->sun).is_day_time == 0;
}

void Grass(struct Mini_World* ptr, int area){
    ptr->grass.area = area;
}

void to_be_eaten(struct Mini_World* ptr){
    if((ptr->grass).area <= 0){
        printf("There is no grass. Wait till tommorow\n");
        return;
    }else if(is_sleeping(ptr)){
        printf("The frog can't eat the grass as it is sleeping. Call the sunrise to wake it up\n");
        return;
    }else if(!(ptr->frog).is_on_the_grass){
        printf("The frog can't eat the grass as it is on the lake. Move it to the grass\n");
        return;
    }else{
        ((ptr->grass).area)--;
        printf("The frog ate one m^2 area of grass\n");
    }
}

void add_area(struct Mini_World* ptr){
    if((ptr->sun).is_day_time){
        (ptr->grass).area++;
        printf("1 m^2 area of grass has been added\n");
    }else{
        printf("You can't add area in the night time\n");
    }
}

int main()
{
    struct Mini_World mini_world;
    Sun(&mini_world, 1);
    Frog(&mini_world, 4, 4);
    Grass(&mini_world, 1);
    
    change_day_time(&mini_world);
    change_day_time(&mini_world);
    make_air(&mini_world);
    change_day_time(&mini_world);
    make_air(&mini_world);
    to_be_eaten(&mini_world);
    change_day_time(&mini_world);
    to_be_eaten(&mini_world);
    move_left(&mini_world);
    to_be_eaten(&mini_world);
    to_be_eaten(&mini_world);
    add_area(&mini_world);
    to_be_eaten(&mini_world);
    
    

    return 0;
}
