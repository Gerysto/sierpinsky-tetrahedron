#include <vector>
#include "Vec3.hh"
#include <iostream>
using namespace std;

class MatrixMath3D {
    public:


    /// @brief If v1 and v2 have the same size, Finds the linear combination of rows given by r*v1 + s*v2
    /// @param r  scalar 
    /// @param v1 vector
    /// @param s  scalar
    /// @param v2 vector
    /// @return result of the linear combination: r*v1 + s*v2
    static vector<double> MatrixMath3D::linear_combination(double r ,const vector<double>& v1, double s, const vector<double>& v2) {
        vector<double> result(v1.size());
        for(int i = 0; i < v1.size(); ++i) result[i] = r*v1[i] + s*v2[i];
        return result;
    }

    /// @brief Finds the inverse of mat (mat has to be invertible)
    /// @param mat is an invertible 3x3 matrix
    /// @return the inverse of mat.
    static vector<vector<double>> MatrixMath3D::inverse(vector<vector<double>> mat) {
        vector<vector<double>> inverse(3,vector<double>(6));
        inverse[0] = {mat[0][0], mat[0][1], mat[0][2], 1 , 0, 0};
        inverse[1] = {mat[1][0], mat[1][1], mat[1][2], 0 , 1, 0};
        inverse[2] = {mat[2][0], mat[2][1], mat[2][2], 0 , 0, 1};

        inverse[1] = linear_combination(inverse[0][0], inverse[1], -inverse[1][0], inverse[0]);
        inverse[2] = linear_combination(inverse[0][0], inverse[2], -inverse[2][0], inverse[0]);

        inverse[0] = linear_combination(inverse[1][1], inverse[0], -inverse[0][1], inverse[1]);
        inverse[2] = linear_combination(inverse[1][1], inverse[2], -inverse[2][1], inverse[1]);

        inverse[0] = linear_combination(inverse[2][2], inverse[0], -inverse[0][2], inverse[2]);
        inverse[1] = linear_combination(inverse[2][2], inverse[1], -inverse[1][2], inverse[2]);

        inverse[0] = linear_combination(0, inverse[0], 1/inverse[0][0], inverse[0]);
        inverse[1] = linear_combination(0, inverse[1], 1/inverse[1][1], inverse[1]);
        inverse[2] = linear_combination(0, inverse[2], 1/inverse[2][2], inverse[2]);

        vector<vector<double>> result(3,vector<double>(3));
        result[0] = {inverse[0][3], inverse[0][4], inverse[0][5]};
        result[1] = {inverse[1][3], inverse[1][4], inverse[1][5]};
        result[2] = {inverse[2][3], inverse[2][4], inverse[2][5]};
        return result;
    }
    
    
    /// @brief solves the system of equations and returns the solution.
    /// @param equations 3x4 matrix describing a system of equations with a single solution.
    /// @return the vector x such that M*x = V.
    static Vec3 MatrixMath3D::solve(vector<vector<double>> equations) {
        // Gaussian Elimination
        equations[1] = linear_combination(equations[0][0], equations[1], -equations[1][0], equations[0]);
        equations[2] = linear_combination(equations[0][0], equations[2], -equations[2][0], equations[0]);
        equations[2] = linear_combination(equations[1][1], equations[2], -equations[2][1], equations[1]);

        // Find the values of z, y, x.
        
        Vec3 result;
        result.z = equations[2][3]/equations[2][2];
        result.y = (equations[1][3] - result.z*equations[1][2])/equations[1][1];
        result.x = (equations[0][3] - result.z*equations[0][2] - result.y*equations[0][1])/equations[0][0];
        return result;
    }

    /// @brief  Calculates the matrix-vector product
    /// @param  mat 3x3 Matrix describing a linear transformation
    /// @param  vec 3-component vector to be transformed by the matrix
    /// @return The column-wise product mat*vec.
    static Vec3 MatrixMath3D::linear_transformation(vector<vector<double>> mat, Vec3 vec) {
        return {vec.x*mat[0][0] + vec.y*mat[0][1] + vec.y*mat[0][2],
                vec.x*mat[1][0] + vec.y*mat[1][1] + vec.z*mat[1][2],
                vec.x*mat[2][0] + vec.y*mat[2][1] + vec.z*mat[2][2]};
    }

};