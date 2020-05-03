#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include<math.h>
#include"Vector2.h"

class Algorithm {
public:
	//�N�����v����
	static float Clamp(float x, float min, float max) {
		if (x < min)
			return min;
		else if (x > max)
			return max;
		else
			return x;
	}

	//Z�������̉�]�s��
	static Vector2 RotationMatrix_Z(Vector2 value, float angle) {
		float c = static_cast<float>(cos(angle));
		float s = static_cast<float>(sin(angle));
		return Vector2(
			value.x * c - value.y * s,
			value.x * s + value.y * c);
	}
};

#endif