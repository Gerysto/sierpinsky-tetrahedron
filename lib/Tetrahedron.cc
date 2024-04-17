#include <iostream>
#include <algorithm>
#include "MatrixMath3D.hh"

struct Tetrahedron {
    private:

    Vec3 a, b, c, d;

    static int sign_of(double val) {
        if(val < 0) return -1;
        if(val > 0) return  1;
        else return 0;
    }
    
    public:

    /// @brief default constructor (all vertices inicialized to {0,0,0}).
    Tetrahedron() {
        a = {0,0,0};
        b = {0,0,0};
        c = {0,0,0};
        d = {0,0,0};
    }
    /// @brief Constructs a tetrahedron from its four vertices
    /// @param a vertex
    /// @param b vertex
    /// @param c vertex
    /// @param d vertex
    Tetrahedron(Vec3 a, Vec3 b, Vec3 c, Vec3 d) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    /// @brief Changes the tetrahedrons vertices
    /// @param a vertex
    /// @param b vertex
    /// @param c vertex
    /// @param d vertex
    void set_vertices(Vec3 a, Vec3 b, Vec3 c, Vec3 d) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    
    /// @brief Returns a new tetrahedron with its vertices organized as specified in the custom compare object.
    /// @tparam Compare 
    /// @param comp custom compare object
    /// @return new tetrahedron with its vertices organized as specified.
    template<class Compare> Tetrahedron change_order(Compare comp) const{
        vector<Vec3> vertices = {a, b, c, d};
        sort(vertices.begin(), vertices.end(), comp);
        return Tetrahedron{vertices[0],vertices[1],vertices[2],vertices[3]};
    }

    /// @brief Finds the distance from a point P to the furthest vertex of the tetrahedron
    /// @param P point from which to compute the distance
    /// @return largest distance from any vertex of the tetrahedron to P. 
    double furthest_vertex_distance(Vec3 P) const {
        float max_dist = (P - a).abs(); 
        if((P - b).abs() > max_dist) max_dist = (P - b).abs();
        if((P - c).abs() > max_dist) max_dist = (P - c).abs();
        if((P - d).abs() > max_dist) max_dist = (P - d).abs();
        return max_dist;
    }

    /// @brief Returns a vector containing the normal vector of each of the tetrahedrons' faces in the following order:
    /// abc, abd, acd, bcd.
    /// @return All four normal vectors returned by this function are normalized.
    vector<Vec3> getNormals() const {
        vector<Vec3> vec(4);
        vec[0] = Vec3::cross_product(b-a,c-a);
        vec[1] = Vec3::cross_product(b-a,d-a);
        vec[2] = Vec3::cross_product(c-a,d-a);
        vec[3] = Vec3::cross_product(c-b,d-b);

        for(int i = 0; i < 4; ++i) vec[i].normalize();

        vec[0] = vec[0]*-sign_of(Vec3::dot_product(vec[0],d-a));
        vec[1] = vec[1]*-sign_of(Vec3::dot_product(vec[1],c-a));
        vec[2] = vec[2]*-sign_of(Vec3::dot_product(vec[2],b-a));
        vec[3] = vec[3]*-sign_of(Vec3::dot_product(vec[3],a-b));

        return vec;
    }
};