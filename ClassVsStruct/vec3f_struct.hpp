#pragma once

struct Vec3 {
	
	float _x, _y, _z;

	Vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f) : _x(x), _y(y), _z(z) {};

	Vec3& operator +=(const Vec3 & vec) {
		this->_x += vec._x;
		this->_y += vec._y;
		this->_z += vec._z;
		return *this;
	}

	void Translate (const Vec3 & vec) {
		this->_x += vec._x;
		this->_y += vec._y;
		this->_z += vec._z;
	}

};

