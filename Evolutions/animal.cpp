#include "Animal.h"
#include "neiron.h"
#include <iostream>
#include <cmath>
#include <algorithm>

ostream& operator<<(ostream& os, vector<Segment> l){
    for (Segment el: l){
        os << el.x1 << " " << el.y1 << " " << el.x2 << " " << el.y2 << "\t";
    }
    os << endl;
    return os;
}
ostream& operator<<(ostream& os, Circle l){
    os << l.x << " " << l.y << " " << l.r << "\t";
    os << endl;
    return os;
}

ostream& operator<<(ostream& os, Animal l){
    cout << l.getCircle();
    os << endl;
    return os;
}


// Инициализация класса животного
Animal::Animal(float s, float mS, float gR, int x, int y, int pPh, int pPr, std::string g_, int r, int g, int b, int id_) {
	pointsPhotosynthesis = pPh;
	pointsPredator = pPr;
	maxSpeed = mS;
	growthRate = gR;
	circle.x = x;
	circle.y = y;
	circle.r = s;
	energy = s;
	PI = acos(-1.0);
	rad_ = 2 * PI / countBeam;
	genus = g_;
	circle.color.push_back(r);
    circle.color.push_back(g);
	circle.color.push_back(b);
	id = id_;
}
// Обновление животного
void Animal::update()
{
//    cout << circle_circle.size() << endl;
	energy -= circle.r * circle.r * k1;
    if (circle_circle.size()){
        is_concerns = true;
//        target_concerns[1] = circle_circle[0];
	}
	else{
        is_concerns = false;
	}
	if (circle_segment.size()){
//        if (is_target && std::find(circle_segment.begin(), circle_segment.end(), target_concerns[0]) != circle_segment.end()){

//        }
//        else{
//            is_target = true;
////            target_concerns[0] = circle_segment[0];
//        }
	}
	else{
            is_target = false;
	}
	if (energy < 0){
        is_alive = false;
	}
	circle.r += growthRate;
    if (is_target != NULL){
//        tx = target_concerns[0].getCircle().x;
//        ty = target_concerns[0].getCircle().y;
    }
    else{
        tx = -1;
        ty = -1;
    }
    vector<float> vec = neiron(growthRate, maxSpeed, circle.r, pointsPhotosynthesis, pointsPredator, energy, is_concerns, tx, ty, circle.x, circle.y);

	speedx = vec[0];
	speedy = vec[1];
	photosynthesis = vec[2];
	predatoring = vec[3];
	if (!is_multiply){
        is_multiply =  vec[4];
	}
	if (photosynthesis){
            cout << 1;
        speedx = 0;
        speedy = 0;
        energy += circle.r * pointsPhotosynthesis;
	}
	if (predatoring){
	    cout << 2;
        speedx = 0;
        speedy = 0;
        if (is_concerns){
//        target_concerns[1].bite(pointsPredator);
        energy += circle.r * pointsPredator;
        }

	}

//    std::cout << speedx * maxSpeed << " " << speedy * maxSpeed << endl;
	circle.x += 10;
	circle.y += 10;

}

Circle Animal::getCircle(){
    return circle;
}

std::vector<Segment> Animal::getSegments(){
    segments.clear();
    for (int i = 0; i < countBeam; i++){
        Segment s;
        s.x1 = circle.x;
        s.y1 = circle.y;
        s.x2 = cos(i * rad_) * circle.r * k2 + circle.x;
        s.y2 = sin(i * rad_) * circle.r * k2 + circle.y;
        segments.push_back(s);
    }
    return segments;
}

void Animal::setCircle_segment(std::vector<Animal> c_s){
    circle_segment = c_s;

}
void Animal::setCircle_circle(std::vector<Animal> c_c){
    circle_circle = c_c;
}

void Animal::bite(float num){
    circle.r -= num;
    if (circle.r < 0){
        is_alive = false;
    }
}
