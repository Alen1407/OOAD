#include <stdio.h>
#include <stdbool.h>

struct Sun{
    char is_day_time;
};

void Sun(struct Sun* sun, char n){
    sun->is_day_time = n;
}

void change_day_time(struct Sun* ptr){
    ptr->is_day_time = !ptr->is_day_time;
    if(ptr->is_day_time == 1){
        printf("Now it is day time\n");
    }else{
        printf("Now it is night\n");
    }
    return;
}

struct Tree{};

void make_air(struct Tree* ptr, struct Sun* sun){
    if(sun->is_day_time == 1){
        printf("The tree is making air\n");
    }else{
        printf("The tree is not making air as it is night\n");
    }
    return;
}

struct Frog{
    int x;
    int y;
    char is_on_the_grass;
};

void update_frog_position(struct Frog* frog){
    if(frog->x > 3 && frog->y > 3 && frog->x < 5 && frog->y < 5){
        frog->is_on_the_grass = 0;
        return;
    }
    frog->is_on_the_grass = 1;
}

void Frog(struct Frog* frog, int x, int y){
    frog->x = x;
    frog->y = y;
    update_frog_position(frog);
}

void move_right(struct Frog* frog){
    (frog->x)++;
    update_frog_position(frog);
}

void move_left(struct Frog* frog){
    (frog->x)--;
    update_frog_position(frog);
}

void move_up(struct Frog* frog){
    (frog->y)++;
    update_frog_position(frog);
}

void move_down(struct Frog* frog){
    (frog->y)--;
    update_frog_position(frog);
}

bool is_sleeping(struct Frog* frog, struct Sun* sun){
    return sun->is_day_time == 0;
}


struct Grass{
    int area;
};


void Grass(struct Grass* grass, int area){
    grass->area = area;
}

void to_be_eaten(struct Grass* grass, struct Frog* frog, struct Sun* sun){
    if(grass->area <= 0){
        printf("There is no grass. Wait till tommorow\n");
        return;
    }else if(is_sleeping(frog, sun)){
        printf("The frog can't eat the grass as it is sleeping. Call the sunrise to wake it up\n");
        return;
    }else if(!frog->is_on_the_grass){
        printf("The frog can't eat the grass as it is on the lake. Move it to the grass\n");
        return;
    }else{
        (grass->area)--;
        printf("The frog ate one m^2 area of grass\n");
    }
}

void add_area(struct Grass* grass, struct Sun* sun){
    if(sun->is_day_time){
        grass->area++;
        printf("1 m^2 area of grass has been added\n");
    }else{
        printf("You can't add area in the night time\n");
    }
}



int main()
{
    struct Sun sun;
    Sun(&sun, 1);
    struct Tree tree;
    struct Frog frog;
    Frog(&frog, 4, 4);
    struct Grass grass;
    Grass(&grass, 1);
    
    change_day_time(&sun);
    change_day_time(&sun);
    make_air(&tree, &sun);
    change_day_time(&sun);
    make_air(&tree, &sun);
    to_be_eaten(&grass, &frog, &sun);
    change_day_time(&sun);
    to_be_eaten(&grass, &frog, &sun);
    move_left(&frog);
    to_be_eaten(&grass, &frog, &sun);
    to_be_eaten(&grass, &frog, &sun);
    add_area(&grass, &sun);
    to_be_eaten(&grass, &frog, &sun);
    
    

    return 0;
}
