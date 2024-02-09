#pragma once

class Vector3
{
public:
    float x, y, z;
    Vector3(float x, float y, float z) : x{x}, y{y}, z{z} { }
    
    bool operator==(const Vector3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
    
    bool operator!=(const Vector3& other) const {
        return !(*this == other);
    }
    
    Vector3 operator-() const {
        return Vector3(-x, -y, -z);
    }
    
    Vector3 operator*(float a) const {
        return Vector3(x * a, y * a, z * a);
    }
    
    Vector3 operator/(float a) const {
        return Vector3(x / a, y / a, z / a);
    }
    
    Vector3 operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }
    
    Vector3 operator-(const Vector3& other) const {
            return Vector3(x - other.x, y - other.y, z - other.z);
        }

    float Magnitude() const {
            return sqrt(x * x + y * y + z * z);
    }

    Vector3 Normalize() const {
            return Vector3(x, y, z) / Vector3(x, y, z).Magnitude();
    }

    float SquareMagnitude() const {
            return sqrt(Vector3(x, y, z).Magnitude());
    }

    static float Dot(Vector3& a, Vector3& b) {
            return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    static Vector3 Cross(Vector3& a, Vector3& b) {
            return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
    }

    static float Distance(Vector3& a, Vector3& b) {
            return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
    }
};
