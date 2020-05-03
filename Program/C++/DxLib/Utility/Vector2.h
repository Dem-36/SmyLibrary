#ifndef _VECTOR2_H_
#define _VECTOR2_H_

struct Vector2 {
public:
	//�R���X�g���N�^
	Vector2();
	Vector2(float x, float y);

	//�����o�֐�
	float Length() const; //���������߂�
	Vector2& Normalize();//���K��(����������̂ŃA�h���X)
	float Dot(const Vector2& v) const;//����

	static float Distance(const Vector2& v1, const Vector2& v2);

	//�P�����Z�q
	Vector2 operator +()const;
	Vector2 operator -()const;
	//������Z�q
	Vector2& operator +=(const Vector2& v);
	Vector2& operator -=(const Vector2& v);
	Vector2& operator *= (float s);
	Vector2& operator /= (float s);
public:
	float x, y;
};

//�񍀉��Z�q(operator�ň���������邽��)
const Vector2 operator + (const Vector2& v1, const Vector2& v2);
const Vector2 operator - (const Vector2& v1, const Vector2& v2);
const Vector2 operator * (const Vector2& v, float s);
const Vector2 operator * (float s , const Vector2& v);
const Vector2 operator / (const Vector2& v, float s);

#endif