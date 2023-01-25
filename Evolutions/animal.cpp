#include "Animal.h"
#include "neiron.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>

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
void Animal::update(std::map<long long int, Animal>& animals)
{
	energy -= circle.r * circle.r * k1;
	if (energy < 0){
        is_alive = false;
	}
	circle.r += growthRate;

    vector<float> vec = neiron(growthRate, maxSpeed, circle.r, pointsPhotosynthesis, pointsPredator, energy, concernsId + 1, tx, ty, circle.x, circle.y);

	speedx = vec[0];
	speedy = vec[1];
	photosynthesis = vec[2];
	predatoring = vec[3];

	circle.x += speedx * maxSpeed;
	circle.y += speedy * maxSpeed;
	if (circle_circle.size()){
        concernsId = circle_circle[0];
	}
	else{
        concernsId = -1;
	}
	if (circle_segment.size()){
        targetId = circle_segment[0];
        tx = *animals[targetId].getCircle().x;
        ty = animals[targetId].getCircle().y;
	}
	else{
        targetId = -1;
	}
	cout << targetId << " " << id << endl;

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

void Animal::setCircle_segment(std::vector<long long int> c_s){
    circle_segment = c_s;

}
void Animal::setCircle_circle(std::vector<long long int> c_c){
    circle_circle = c_c;
}

void Animal::bite(float num){
    circle.r -= num;
    if (circle.r < 0){
        is_alive = false;
    }
}
