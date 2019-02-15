#pragma once

class Vec3 {
public:
	float _x, _y, _z;
	
	Vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f) :_x(x), _y(y), _z(z) {};
	
	void Translate(Vec3 & vec) {
		_x += vec._x;
		_y += vec._y;
		_z += vec._z;
	}
};
