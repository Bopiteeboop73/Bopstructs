#pragma once

#include <ostream>

namespace bop {
    struct Vector2 {
        Vector2(float p_x, float p_y);

        float x, y;

        Vector2& operator+=(const Vector2 &other);
        Vector2& operator-=(const Vector2 &other);
        Vector2 operator-() const;
        Vector2& operator*=(float scale);
        Vector2& operator/=(float scale);

        friend std::ostream& operator<<(std::ostream& os, const Vector2& v);

        [[nodiscard]] float sqr_magnitude() const;
        [[nodiscard]] float magnitude() const;
        [[nodiscard]] Vector2 normalised() const;
        [[nodiscard]] Vector2 get_normal() const;

        [[nodiscard]] float get_angle(Vector2 other = {1, 0}) const;

    };

    Vector2 operator+(const Vector2 &vec1, const Vector2 &vec2);

    Vector2 operator-(const Vector2 &vec1, const Vector2 &vec2);


    Vector2 operator*(const Vector2 &vec, float scale);
    Vector2 operator*(float scale, const Vector2 &vec);

    Vector2 operator/(const Vector2 &vec, float scale);
    Vector2 operator/(float scale, const Vector2 &vec);

    bool operator==(const Vector2 &vec1, const Vector2 &vec2);
    bool operator!=(const Vector2 &vec1, const Vector2 &vec2);


    float dot(Vector2 vec1, Vector2 vec2);
    float cross(Vector2 vec1, Vector2 vec2);


}