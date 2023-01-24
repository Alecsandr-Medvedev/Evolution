#ifndef ANIMAL_H
#define ANIMAL_H
#include <vector>
#include <string>

struct Circle {
  double x, y;
  double r;
  std::vector<int> color;
};

// Struct for a line segment, with coordinates for its endpoints
struct Segment {
  double x1, y1, x2, y2;
};


//int getRandomHexNum(){
//
//}

class Animal {

    public:
              bool operator==(const Animal& other) const {
        return (id == other.id);
    }
    std::string genus;
	float maxSpeed, energy, growthRate, k1 = 0, speedx, speedy, PI, k2 = 10, rad_;
	int pointsPhotosynthesis, pointsPredator, countBeam = 5, tx = -1, ty = -1, id;
	bool photosynthesis, predatoring, is_alive = true, is_concerns = false, is_target = false, is_multiply = false;
	std::vector<Segment> segments;
	std::vector<Animal> circle_segment, circle_circle;
	Circle circle;

	 Animal(float /*size*/, float /*maxSpeed*/, float /*growthRate*/, int /*posX*/, int /*posY*/, int /*pointsPhotosynthesis*/, int /*poitsPredator*/, std::string /*genus*/, int /*r*/, int /*g*/, int /*b*/, int id_);
	 void setPhotosynthesisPoint(float);
	 void update();

	 std::vector<Segment> getSegments();
	 Circle getCircle();
	 void setCircle_segment(std::vector<Animal>);
     void setCircle_circle(std::vector<Animal>);
     void bite(float);
};

#endif // ANIMAL_H
