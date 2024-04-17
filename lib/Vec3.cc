#include <iostream>
#include <cmath>
using namespace std;

class Vec3 {

    public: 

    double x, y, z;

    Vec3 Vec3::operator+(Vec3 a) const {
        return {x+a.x, y+a.y, z+a.z};
    }

    Vec3 Vec3::operator-(Vec3 a) const {
        return {x-a.x, y-a.y, z-a.z};
    }

    Vec3 Vec3::operator*(double t) const {
        return {x*t, y*t, z*t};
    }

    bool Vec3::operator==(Vec3 a) const {
        return ((x == a.x and y == a.y) and z == a.z);
    }
    void Vec3::print() const {
        cout << x << ", " << y << ", " << z << endl;
    }
    void Vec3::normalize() {
        double r = sqrt(x*x + y*y + z*z);
        x /= r;
        y /= r;
        z /= r;
    }
    double Vec3::abs() const {
        return sqrt(x*x + y*y + z*z);
    }
    static Vec3 Vec3::cross_product(const Vec3& u, const Vec3& v) {
        return {u.y*v.z - u.z*v.y, u.z*v.x - u.x*v.z, u.x*v.y - u.y*v.x};
    }
    static double Vec3::dot_product(const Vec3& u, const Vec3& v) {
        return {u.x*v.x + u.y*v.y + u.z*v.z};
    }
};