#include<vector>
#include <stdlib.h>
#include <iostream>

using namespace std;
typedef float f;
typedef int i;

vector<f> neiron(f growthRate, f maxSpeed, f size, i pointsPhotosynthesis, i pointsPredator, f energy, bool is_concerns, i target_x, i target_y, i x, i y){
    float photosynthesis, speedx, speedy, predatoring, is_multiply;
    if (pointsPredator > pointsPhotosynthesis){

        if (target_x != -1 && target_y != -1){
            cout << 1;
            if (x < target_x){
                speedx = 1;
            }
            else if (x > target_x){
                speedx = -1;
            }
            else if (x == target_x){
                speedx = 0;
            }
            if (y < target_y){
                speedy = 1;
            }
            else if (y > target_y){
                speedy = -1;
            }
            else if (y == target_y){
                speedy = 0;
            }
        }
        else{
        speedx = ((rand() % 200) - 100) / 100.f;
        speedy = ((rand() % 200) - 100) / 100.f;
        }
    }
    else{
        speedx = 0;
        speedy = 0;
    }
    if (energy - size < 0){
        photosynthesis = false;
    }
    else{
        photosynthesis = false;
    }
//    cout << is_concerns;
    if (is_concerns && pointsPredator){
        cout << 1112;
        predatoring = 0;
    }
    else{
        predatoring = 0;
    }
    if (size < energy && size > 3){
        is_multiply = true;
    }
    else {
        is_multiply = false;
    }
    vector<f> ans = {speedx, speedy, photosynthesis, predatoring, is_multiply};
    return ans;
}
