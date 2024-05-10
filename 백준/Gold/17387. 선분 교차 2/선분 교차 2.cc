#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;
using Point = pair<int, int>;
#define X first
#define Y second

int CCW(Point &p1, Point &p2, Point &p3) {
    long long res = (long long)p1.X * p2.Y + (long long)p2.X * p3.Y + (long long)p3.X * p1.Y;
    res -= (long long)p2.X * p1.Y + (long long)p3.X * p2.Y + (long long)p1.X * p3.Y;
    return (res > 0) - (res < 0);
}

bool Cross(Point a, Point b, Point c, Point d) {
    int ab = CCW(a, b, c) * CCW(a, b, d);
    int cd = CCW(c, d, a) * CCW(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}

int main() {
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    Point dot1 = make_pair(x1, y1);
    Point dot2 = make_pair(x2, y2);
    Point dot3 = make_pair(x3, y3);
    Point dot4 = make_pair(x4, y4);

    cout << Cross(dot1, dot2, dot3, dot4) << endl;
}
