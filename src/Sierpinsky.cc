#include <iostream>
#include "Tetrahedron.hh"

using namespace std;


/// @brief Recursively generates an array of tetrahedrons making up the 3D fractal.
/// @param T Tetrahedron from which to start recursion.
/// @param vec array of tetrahedrons making up the fractal.
/// @param n number of iterations
void Sierpinsky(const Tetrahedron& T, vector<Tetrahedron>& vec, int n) {
    if (n == 0) return;
    
    // midpoints of all the edges
    Vec3 p0 = (T.b - T.a)*0.5 + T.a;
    Vec3 p1 = (T.c - T.a)*0.5 + T.a;
    Vec3 p2 = (T.d - T.a)*0.5 + T.a;
    Vec3 p3 = (T.b - T.c)*0.5 + T.c;
    Vec3 p4 = (T.c - T.d)*0.5 + T.d;
    Vec3 p5 = (T.d - T.b)*0.5 + T.b;

    Tetrahedron T0(T.a,p0,p1,p2);
    Tetrahedron T1(T.b,p0,p3,p5);
    Tetrahedron T2(T.c,p1,p3,p4);
    Tetrahedron T3(T.d,p2,p4,p5);

    if(n == 1) {
        vec.push_back(T0);
        vec.push_back(T1);
        vec.push_back(T2);
        vec.push_back(T3);
    }

    Sierpinsky(T0, vec, n-1);
    Sierpinsky(T1, vec, n-1);
    Sierpinsky(T2, vec, n-1);
    Sierpinsky(T3, vec, n-1);
}

int main() {

}