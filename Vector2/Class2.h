#pragma once

#include <math.h>
#include <cmath>
#include <iostream>

# define M_PI 3.141592653589793238462643383279502884L /* pi */

class Vector2
{
public:
	float v_x; 
	float v_y;

	Vector2(float x = 0.0, float y = 0.0)
	{
		v_x = x;
		v_y = y;
	}

/*
	~Vector2()
	{
		std::cout << "The destructor has been called\n";
	}
*/

	float getX() { return v_x; }
	float getY() { return v_y; }

	Vector2 operator+ (const Vector2& other) const
	{
		Vector2 res;
		res.v_x = this->v_x + other.v_x;
		res.v_y = this->v_y + other.v_y;
		return res;
	}

	Vector2& operator+= (const Vector2& other)
	{
		this->v_x += other.v_x;
		this->v_y += other.v_y;
		return *this;
	}

	Vector2 operator- (const Vector2& other) const
	{
		Vector2 res;
		res.v_x = this->v_x - other.v_x;
		res.v_y = this->v_y - other.v_y;
		return res;
	}

	Vector2& operator-= (const Vector2& other)
	{
		this->v_x -= other.v_x;
		this->v_y -= other.v_y;
		return *this;
	}

	float operator* (const Vector2& other) const
	{
		return this->v_x * other.v_x + this->v_y * other.v_y;
	}

	float operator^ (const Vector2& other) const
	{
		return this->v_x * other.v_y - this->v_y * other.v_x;
	}

	Vector2 operator* (const float& val) const
	{
		Vector2 res;
		res.v_x = this->v_x * val;
		res.v_y = this->v_y * val;
		return res;
	}

	friend Vector2 operator* (const float& val, const Vector2& vec);

	Vector2 operator/ (const float& other) const
	{
		Vector2 res;
		res.v_x = this->v_x / other;
		res.v_y = this->v_y / other;
		return res;
	}

	Vector2 norm() const
	{
		Vector2 res;
		res.v_x = v_x / sqrt(v_x * v_x + v_y * v_y);
		res.v_y = v_y / sqrt(v_x * v_x + v_y * v_y);
		return res;
	}

	Vector2 perp() const
	{
		Vector2 res;
		res.v_x = v_y;
		res.v_y = -v_x;
		return res;
	}

	float len() const
	{
		return sqrt(v_x * v_x + v_y * v_y);
	}

	float squareLen() const
	{
		return v_x * v_x + v_y * v_y;
	}

	Vector2 operator-() const
	{
		Vector2 res;
		res.v_x = - v_x;
		res.v_y = -v_y;
		return res;
	}

	Vector2& rotate(const float& corner)
	{
		float rad_corner = corner * M_PI / 180;
		float tempx = this->v_x;
		float tempy = this->v_y;
		this->v_x = tempx * cos(rad_corner) - tempy * sin(rad_corner);
		this->v_y = tempy * cos(rad_corner) + tempx * sin(rad_corner);
		return *this;
	}

	Vector2 getRotated(const float& corner) const
	{
		float rad_corner = corner * M_PI / 180;
		Vector2 res;
		res.v_x = this->v_x * cos(rad_corner) - this->v_y * sin(rad_corner);
		res.v_y = this->v_y * cos(rad_corner) + this->v_x * sin(rad_corner);
		return res;
	}
};

Vector2 operator* (const float& val, const Vector2& vec)
{
	Vector2 res;
	res.v_x = val * vec.v_x;
	res.v_y = val * vec.v_y;
	return res;
}