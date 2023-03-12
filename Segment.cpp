#include <cmath>
#include <vector>
#include <iostream>

using namespace std;
class Segment {
public:
    Segment(vector<double> start, vector<double> end) :
            start_(start), end_(end) {}

    bool contains(const vector<double>& point) const {
        // Проверяем, что точка лежит на отрезке с учётом погрешности вычислений
        const double EPSILON = 1e-9;
        double x1 = start_[0], y1 = start_[1], x2 = end_[0], y2 = end_[1];
        double px = point[0], py = point[1];
        double dx = x2 - x1, dy = y2 - y1;
        double d = dx * dx + dy * dy;
        double t = ((px - x1) * dx + (py - y1) * dy) / d;
        if (t < -EPSILON || t > 1 + EPSILON) {
            return false;
        }
        double x = x1 + t * dx;
        double y = y1 + t * dy;
        double dist = sqrt((px - x) * (px - x) + (py - y) * (py - y));
        return dist < EPSILON;
    }

    double length() const {
        // Вычисляем длину отрезка
        double dx = end_[0] - start_[0];
        double dy = end_[1] - start_[1];
        return sqrt(dx * dx + dy * dy);
    }

private:
    vector<double> start_;
    vector<double> end_;
};
int main(){
    vector<double> start = {0,0};
    vector<double> end = {3,4};
    Segment seg(start, end);
    vector<double> point = {1,2};
    bool isOnSegment = seg.contains(point);
    cout << isOnSegment << endl;
    double len = seg.length();
    cout << len << endl;

}