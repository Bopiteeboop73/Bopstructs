#include "Vector2.h"

namespace bop {

    Vector2::Vector2(const float p_x, const float p_y): x(p_x), y(p_y) {}

    Vector2 & Vector2::operator+=(const Vector2 &other) {
        x += other.x;
        y += other.y;

        return *this;
    }

    Vector2 & Vector2::operator-=(const Vector2 &other) {
        return *this += -other;
    }

    Vector2 Vector2::operator-() const {
        return {-x, -y};
    }

    Vector2 & Vector2::operator*=(float scale) {
        x *= scale;
        y *= scale;

        return *this;
    }

    Vector2 & Vector2::operator/=(float scale) {
        x /= scale;
        y /= scale;

        return *this;
    }

    float Vector2::sqr_magnitude() const {
        return x * x + y * y;
    }

    float Vector2::magnitude() const {
        return sqrt(sqr_magnitude());
    }

    std::ostream & operator<<(std::ostream &os, const Vector2 &v) {
        return os << "[" << v.x << ", " << v.y << "]";
    }



    Vector2 Vector2::normalised() const {
        if (sqr_magnitude() == 0)
            return {0, 0};

        return *this / magnitude();
    }

    Vector2 Vector2::get_normal() const {
        return {-y, x};
    }

    float Vector2::get_angle(Vector2 other) const {
        return atan2(cross(*this, other), dot(*this, other));
    }

    Vector2 operator+(const Vector2 &vec1, const Vector2 &vec2) {
        return {vec1.x + vec2.x, vec1.y + vec2.y};
    }

    Vector2 operator-(const Vector2 &vec1, const Vector2 &vec2) {
        return vec1 + -vec2;
    }

    Vector2 operator*(const Vector2 &vec, float scale) {
        return {vec.x * scale, vec.y * scale};
    }

    Vector2 operator*(float scale, const Vector2 &vec) {
        return vec * scale;
    }

    Vector2 operator/(const Vector2 &vec, float scale) {
        return {vec.x / scale, vec.y / scale};
    }

    Vector2 operator/(float scale, const Vector2 &vec) {
        return vec / scale;
    }

    bool operator==(const Vector2 &vec1, const Vector2 &vec2) {
        constexpr float EPS = 1e-5f;
        return std::fabs(vec1.x - vec2.x) < EPS &&
               std::fabs(vec1.y - vec2.y) < EPS;
    }

    bool operator!=(const Vector2 &vec1, const Vector2 &vec2) {
        return !(vec1 == vec2);
    }

    float dot(Vector2 vec1, Vector2 vec2) {
        return vec1.x * vec2.x + vec1.y * vec2.y;
    }

    float cross(Vector2 vec1, Vector2 vec2) {
        return vec1.x * vec2.y - vec2.x * vec1.y;
    }
}

