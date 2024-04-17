#include <vector>
#include <iostream>
#include "Vec3.hh"
using namespace std;

class MatrixMath3D {
    public:

    /// @brief Pre: If v1 and v2 have the same size, Finds the linear combination of rows given by r*v1 + s*v2
    /// @param r  scalar 
    /// @param v1 vector
    /// @param s  scalar
    /// @param v2 vector
    /// @return result of the linear combination: r*v1 + s*v2
    static vector<double> MatrixMath3D::linear_combination(double r ,const vector<double>& v1, double s, const vector<double>& v2);

    /// @brief Finds the inverse of mat (mat has to be invertible)
    /// @param mat is an invertible 3x3 matrix
    /// @return the inverse of mat.
    static vector<vector<double>> MatrixMath3D::inverse(vector<vector<double>> mat);
    
    
    /// @brief solves the system of equation and returns the solution.
    /// @param System 3x4 matrix describing a system of equations with a single solution.
    /// @return the vector x such that M*x = V.
    static Vec3 MatrixMath3D::solve(vector<vector<double>> System);


    /// @brief  Calculates the matrix-vector product
    /// @param  mat 3x3 Matrix describing a linear transformation
    /// @param  vec 3-component vector to be transformed by the matrix
    /// @return The column-wise product mat*vec.
    static Vec3 MatrixMath3D::linear_transformation(vector<vector<double>> mat, Vec3 vec);
    
};