#include "Matrix3.h"

#include <thread>
#include <functional>


Matrix3::Matrix3(float matrix_[9])
{
	memcpy(matrix, matrix_, 9 * sizeof(float));
}


Matrix3 Matrix3::MultiplySingleThread(const Matrix3& left, const Matrix3& right)
{
	/*float out[9] =
	{
		//  first line
		left[0] * right[0] + left[1] * right[3] + left[2] * right[6],  //  0
		left[0] * right[1] + left[1] * right[4] + left[2] * right[7],  //  1
		left[0] * right[2] + left[1] * right[5] + left[2] * right[8],  //  2

		//  second line
		left[3] * right[0] + left[4] * right[3] + left[5] * right[6],  //  3
		left[3] * right[1] + left[4] * right[4] + left[5] * right[7],  //  4
		left[3] * right[2] + left[4] * right[5] + left[5] * right[8],  //  5

		//  third line
		left[6] * right[0] + left[7] * right[3] + left[8] * right[6],  //  6
		left[6] * right[1] + left[7] * right[4] + left[8] * right[7],  //  7
		left[6] * right[2] + left[7] * right[5] + left[8] * right[8]   //  8
	};

	return Matrix3(out);*/

	Matrix3 out;

	for (int i = 0; i < 9; i++)
	{
		int l = floor(i / 3) * 3;
		int r = i % 3;

		out.matrix[i] = left[l] * right[r] + left[l + 1] * right[r + 3] + left[l + 2] * right[r + 6];
	}

	return out;
}


Matrix3 Matrix3::MultiplyMultiThread(const Matrix3& left, const Matrix3& right)
{
	Matrix3 out;

	std::thread t0(multiplyId, std::ref(out), left, right, 0); 
	std::thread t1(multiplyId, std::ref(out), left, right, 1); 
	std::thread t2(multiplyId, std::ref(out), left, right, 2); 
	std::thread t3(multiplyId, std::ref(out), left, right, 3); 
	std::thread t4(multiplyId, std::ref(out), left, right, 4); 
	std::thread t5(multiplyId, std::ref(out), left, right, 5); 
	std::thread t6(multiplyId, std::ref(out), left, right, 6); 
	std::thread t7(multiplyId, std::ref(out), left, right, 7); 
	std::thread t8(multiplyId, std::ref(out), left, right, 8); 

	t0.join(); 
	t1.join(); 
	t2.join(); 
	t3.join();   
	t4.join(); 
	t5.join(); 
	t6.join();  
	t7.join();
	t8.join(); 

	/*for (int i = 0; i < 9; i++)
	{
		std::thread t(multiplyId, std::ref(out), left, right, i);
		t.join();
	}*/

	return out;
}


float Matrix3::operator[](const int id) const
{
	return matrix[id];
}


void Matrix3::multiplyId(Matrix3& outMat, const Matrix3& left, const Matrix3& right, const int id)
{
	int l = floor(id / 3) * 3;
	int r = id % 3;

	outMat.matrix[id] = left[l] * right[r] + left[l + 1] * right[r + 3] + left[l + 2] * right[r + 6];
}
