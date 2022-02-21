//Homework 2: Vector2

#include "Class2.h"
#include <iostream>
#include <iomanip>

std::ostream& operator << (std::ostream& stream, const Vector2& vec)
{
	stream << "Vector2(" << vec.v_x << ", " << vec.v_y << ")";
	return stream;
}

std::istream& operator >> (std::istream& stream, Vector2& vec)
{
	stream >> vec.v_x;
	stream >> vec.v_y;
	return stream;
}

using namespace std;

int main()
{
	std::cout << "Vec1: (10, 0), Vec2: (0, 0) - constructor call (with default values)\n";
	Vector2 vec1(10);
	Vector2 vec2;
	std::cout << "Vec1: " << vec1 << "\n";
	std::cout << "Vec2: " << vec2 << "\n";

	std::cout << "Initialize vec1 and vec2: ";
	std::cin >> vec1;
	std::cin >> vec2;
	std::cout << "Vec1: " << vec1 << "\n";
	std::cout << "Vec2: " << vec2 << "\n";

	Vector2 temp1 = vec1;
	Vector2 temp2 = vec2;

	std::cout << "+: " << vec1 + vec2 << "\n";
	vec1 += vec2;
	std::cout << "+=: " << vec1 << "\n";

	vec1 = temp1;

	std::cout << "-: " << vec1 - vec2 << "\n";
	vec1 -= vec2;
	std::cout << "-=: " << vec1 << "\n";

	vec1 = temp1;

	std::cout << "Scalar product: " << vec1 * vec2 << "\n";
	std::cout << "Vector product: " << (vec1 ^ vec2) << "\n";

	std::cout << "Product by scalar 5: vec1 * 5: " << vec1 * 5 << "\n";
	std::cout << "Product by scalar 5: 5 * vec1: " << 5 * vec1 << "\n";
	std::cout << "Division by a scalar 5 vec1: " << vec1 / 5 << "\n";

	std::cout << "Norm vec1: " << vec1.norm() << "\n";
	std::cout << "Perpendicular vec1: " << vec1.perp() << "\n";

	std::cout << "Len vec1: " << vec1.len() << "\n";
	std::cout << "SquareLen vec1: " << vec1.squareLen() << "\n";

	std::cout << "Un -vec1: " << -vec1 << "\n";

	float corner = 0.0;
	std::cout << "Inizialize corner (degress): ";
	std::cin >> corner;

	vec1.rotate(corner);
	std::cout << "Vec1.rotate(corner): " << fixed << setprecision(5) << vec1 << "\n";
	vec1 = temp1;
	std::cout << "Vec1.getRotated(corner): " << fixed << setprecision(5) << vec1.getRotated(corner) << "\n";

	return 0;
}