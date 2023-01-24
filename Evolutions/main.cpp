#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "animal.h"
#include <stdlib.h>
#include <cmath>
#include <sstream>
#include <map>

using namespace sf;
using namespace std;


float FPS = 10;
long long int last_id = 0;
map<long long int, Animal> animals;

ostream& operator<<(ostream& os, vector<long long int>& l){
    for (long long int el: l){
        os << el << "\t";
    }
    os << endl;
    return os;
}
ostream& operator<<(ostream& os, vector<vector<long long int>>& l){
    for (vector<long long int> el1: l){
         cout << el1;
    }
    return os;
}

string getRandomGen(){
    string line = "", az = "0123456789ABCDEF";
    for (int i = 0; i < 6; i++){
        line += az[rand() % az.size() - 1];
    }
    return line;
}

vector<int> getColor(string line){
    vector<int> col;
    int n = 0;
    map <char, int> sl {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}};
    for (int j = 0; j < 6; j += 2){
        n = 0;
        for (int i = 0; i < 2; i++){
            n += sl[line[i + j]] * pow(16, 1 - i);
        }
    col.push_back(n);
    }

    return col;
}


bool circleSegmentIntersect(Circle c, Segment s) {
  // Find the distance from the center of the circle to the line defined by the segment
  double dist = abs((s.y2 - s.y1) * c.x - (s.x2 - s.x1) * c.y + s.x2 * s.y1 - s.y2 * s.x1) / sqrt((s.y2 - s.y1) * (s.y2 - s.y1) + (s.x2 - s.x1) * (s.x2 - s.x1));
  // If the distance is greater than the radius of the circle, they do not intersect
  if (dist > c.r) return false;
  // Check if any of the endpoints of the segment are within the circle
  if (sqrt((c.x - s.x1) * (c.x - s.x1) + (c.y - s.y1) * (c.y - s.y1)) <= c.r || sqrt((c.x - s.x2) * (c.x - s.x2) + (c.y - s.y2) * (c.y - s.y2)) <= c.r) return true;
  // If the distance is less than the radius and neither endpoint is within the circle, they must intersect
  return true;
}

// Function to find the centers of circles that intersect with at least one line segment
vector<long long int> findIntersectingCirclesSegments(map<long long int, Animal> animals, vector<Segment> segments, long long int circ) {
  vector<long long int> intersectingCircles;


  // Loop through each circle and segmen
  for (map<long long int, Animal>::iterator it = animals.begin(); it != animals.end(); it++) {
        if (it->first == circ) continue;
    for (auto s : segments) {
      // If the circle and segment intersect, add the center of the circle to the list of intersecting centers
      if (circleSegmentIntersect(it->second.getCircle(), s)) intersectingCircles.push_back(it->first);
    }
  }
  return intersectingCircles;
}

bool circlesIntersect(Circle c1, Circle c2) {
  // Calculate the distance between the centers of the circles
  double dist = sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));
  // If the distance is greater than the sum of the radii, the circles do not intersect
  if (dist > c1.r + c2.r) return false;
  // Otherwise, they intersect
//  cout << 1 << endl;
  return true;
}

// Function to find the circles in a list that intersect with a given circle
std::vector<long long int> findIntersectingCircles(map<long long int, Animal> animals, Animal an) {
  std::vector<long long int> intersectingCircles;
  // Loop through each circle in the list
  for (map<long long int, Animal>::iterator it = animals.begin(); it != animals.end(); it++) {
    if (it->first == an.id) continue;
    if (circlesIntersect(it->second.getCircle(), an.getCircle()))
        { intersectingCircles.push_back(it->first);}
  }
  return intersectingCircles;
}


void renderingThread(sf::RenderWindow* window)
{
    // activate the window's context
    window->setActive(true);

    // the rendering loop
    while (window->isOpen())
    {
        window->clear(Color(0, 0, 0));
        for (auto& animal : animals){
            Animal an = animal.second;
            CircleShape cricle;
            Circle circ = an.getCircle();
            cricle.setRadius(circ.r * 2);
            cricle.setOrigin(circ.r * 2.f, circ.r * 2.f);
            cricle.setPosition(circ.x, circ.y);
            vector<int> r = circ.color;
            cricle.setFillColor(Color(r[0], r[1], r[2], 150));
            vector<Segment> segs = an.getSegments();
            for (int i = 0; i < segs.size(); i++)
            {
                CircleShape cr;
                cr.setRadius(2);
                cr.setOrigin(2, 2);
                cr.setFillColor(Color(r[0], r[1], r[2], 150));
                cr.setPosition(segs[i].x2, segs[i].y2);
                window->draw(cr);
             }

            window->draw(cricle);
        }
        window->display();
    }
}


int main()
{

    int WIDTH = VideoMode::getFullscreenModes()[0].width, HEIGHT = VideoMode::getFullscreenModes()[0].height;
    srand ( time(NULL) );
    Clock clock;
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Evolutions");
    vector<long long int> ids;

    window.setActive(false);

    Thread thread(&renderingThread, &window);
    thread.launch();

	for (int i = 0; i < 1; i++){
        float size = (rand() % 10 + 100) / 10.f;
        int pointsPhotosynthesis = 0;
        int poitsPredator = 100 - pointsPhotosynthesis;
        float maxSpeed = rand() % 100;
        float growthRate = (rand() % 1) / 100.f;
//        int posX = (rand() % WIDTH);
//        int posY = (rand() % HEIGHT);
        int posX = rand() % 100;
        int posY = rand() % 100;
        string gen = getRandomGen();
        vector<int> col = getColor(gen);
        Animal an = Animal(size, maxSpeed, growthRate, posX, posY, pointsPhotosynthesis, poitsPredator, gen, col[0], col[1], col[2], last_id);
        animals.insert(make_pair(last_id, an));
        ids.push_back(last_id);

        last_id++;

	}

	while (window.isOpen())
	{
//        window.clear(Color(0, 0, 0));
		Event event;
		while (window.pollEvent(event))
{
            // проверяем тип события...
            switch (event.type)
            {
                // закрытие окна
                case Event::Closed:
                    window.close();
                    break;

                // нажатие клавиши
                case Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Right)
                        {
                            cout << "the right button was pressed" << endl;
                            cout << "mouse x: " << event.mouseButton.x << endl;
                            cout << "mouse y: " << event.mouseButton.y << endl;
                        }
                    break;

                // мы не обрабатываем другие типы событий
                default:
                    break;
            }
}
		int c = 0;
//		while (c < animals.size()){
//            if (!animals[c].is_alive){
//                animals.erase(next(animals.begin(), c));
//                continue;
//            }
//            else c++;
//
//		}
        for (auto& animal : animals){
            Animal& an = animal.second;
            an.update();
            vector<long long int> circle_segment = findIntersectingCirclesSegments(animals, an.getSegments(), animal.first);
            vector<long long int> circle_circle = findIntersectingCircles(animals, an);
//            CircleShape cricle;
//            Circle circ = an.getCircle();
//            cricle.setRadius(circ.r * 2);
//            cricle.setOrigin(circ.r * 2.f, circ.r * 2.f);
//            cricle.setPosition(circ.x, circ.y);
//            vector<int> r = circ.color;
//            cricle.setFillColor(Color(r[0], r[1], r[2], 150));
//            vector<Segment> segs = an.getSegments();
//            for (int i = 0; i < segs.size(); i++)
//            {
//                CircleShape cr;
//                cr.setRadius(2);
//                cr.setOrigin(2, 2);
//                cr.setFillColor(Color(r[0], r[1], r[2], 150));
//                cr.setPosition(segs[i].x2, segs[i].y2);
//                window.draw(cr);
//             }

//            window.draw(cricle);
        }
//        cout << animals[0].getCircle() << endl;
//        cout << animals[0].getSegments() << endl << endl;
//        window.display();
		// timer
       Int32 frame_duration = clock.getElapsedTime().asMilliseconds();
       Int32 time_to_sleep = int(1000.f/FPS) - frame_duration;
       if (time_to_sleep > 0) {
            sleep(milliseconds(time_to_sleep));
        }
        clock.restart();
	}

	return 0;
}
