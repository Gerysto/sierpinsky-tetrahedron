#include <iostream>
#include <algorithm>
#include "MatrixMath3D.hh"

struct Tetrahedron {
    public:
    // vertices of the Tetrahedron:
    Vec3 a, b, c, d;

    /// @brief default constructor (all vertices inicialized to {0,0,0}).
    Tetrahedron::Tetrahedron();

    /// @brief Constructs a tetrahedron from its four vertices
    /// @param a vertex
    /// @param b vertex
    /// @param c vertex
    /// @param d vertex
    Tetrahedron::Tetrahedron(Vec3 a, Vec3 b, Vec3 c, Vec3 d);

    /// @brief Changes the tetrahedrons vertices
    /// @param a vertex
    /// @param b vertex
    /// @param c vertex
    /// @param d vertex
    void Tetrahedron::set_vertices(Vec3 a, Vec3 b, Vec3 c, Vec3 d);
    
    /// @brief Returns a new tetrahedron with its vertices organized as specified in the custom compare object.
    /// @tparam Compare 
    /// @param comp custom compare object
    /// @return new tetrahedron with its vertices organized as specified.
    template<class Compare> Tetrahedron Tetrahedron::change_order(Compare comp) const;

    /// @brief Finds the distance from a point P to the furthest vertex of the tetrahedron
    /// @param P point from which to compute the distance
    /// @return largest distance from any vertex of the tetrahedron to P. 
    double Tetrahedron::furthest_vertex_distance(Vec3 P) const;

    /// @brief Returns a vector containing the normal vector of each of the tetrahedrons' faces in the following order:
    /// abc, abd, acd, bcd.
    /// @return All four normal vectors returned by this function are normalized.
    vector<Vec3> Tetrahedron::getNormals() const;
};