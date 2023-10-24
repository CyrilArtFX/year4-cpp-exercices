#pragma once

class Matrix3
{
public:
	Matrix3() {}
	explicit Matrix3(float matrix_[9]);

	static Matrix3 MultiplySingleThread(const Matrix3& left, const Matrix3& right);
	static Matrix3 MultiplyMultiThread(const Matrix3& left, const Matrix3& right);

	float operator[](const int id) const;

	float matrix[9] { 
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	};

private:
	static void multiplyId(Matrix3& outMat, const Matrix3& left, const Matrix3& right, const int id);
};

