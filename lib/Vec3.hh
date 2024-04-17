
class Vec3 {

    public: 

    double x, y, z;
    /// @brief Computes the sum of two vectors
    /// @param a vector
    /// @return [implicit] + a
    Vec3 operator+(Vec3 a) const;

    /// @brief Computes the subtraction of two vectors
    /// @param a vector
    /// @return [implicit] - a
    Vec3 operator-(Vec3 a) const;

    /// @brief Cumputes the product of a vector and a scalar
    /// @param t scalar
    /// @return [implicit]*t
    Vec3 operator*(double t) const;

    /// @brief Checks whether two vectors are equal to one another
    /// @param a vector
    /// @return true if all components of both vectors are the same, false otherwhise.
    bool operator==(Vec3 a) const;

    /// @brief Prints the vector to the console.
    void print() const;

    /// @brief Scales the vector such that its length is 1.
    void normalize();

    /// @brief Calculates the vectors' length
    /// @return length of the implicit vector.
    double abs() const;

    /// @brief Computes the cross product of u and v.
    /// @param u 
    /// @param v 
    /// @return result = u x v
    static Vec3 cross_product(const Vec3& u, const Vec3& v);

    /// @brief Computes the dot product of u and v.
    /// @param u 
    /// @param v 
    /// @return result = u · v
    static double dot_product(const Vec3& u, const Vec3& v);
};