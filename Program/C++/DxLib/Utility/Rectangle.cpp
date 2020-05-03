#include "Rectangle.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Rectangle::Rectangle()
	:x(0), y(0), width(0), height(0)
{
}

/// <summary>
/// �����t���R���X�g���N�^
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="width"></param>
/// <param name="height"></param>
Rectangle::Rectangle(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

/// <summary>
/// �����t���R���X�g���N�^
/// </summary>
/// <param name="position"></param>
/// <param name="size"></param>
Rectangle::Rectangle(Vector2 position, Vector2 size)
{
	this->x = position.x;
	this->y = position.y;
	this->width = size.x;
	this->height = size.y;
}

void Rectangle::Set(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void Rectangle::Set(Vector2 position, Vector2 size)
{
	this->x = position.x;
	this->y = position.y;
	this->width = size.x;
	this->height = size.y;
}

/// <summary>
/// �l�p�`�̏�ӂ�Y���擾����
/// </summary>
/// <returns></returns>
float Rectangle::Top()
{
	return y - (height / 2);
}

/// <summary>
/// �l�p�`�̒�ӂ�Y���擾����
/// </summary>
/// <returns></returns>
float Rectangle::Bottom()
{
	return y + (height / 2);
}

/// <summary>
/// �l�p�`�̉E�ӂ�X���擾����
/// </summary>
/// <returns></returns>
float Rectangle::Right()
{
	return x + (width / 2);
}

/// <summary>
/// �l�p�`�̍��ӂ�X���擾����
/// </summary>
/// <returns></returns>
float Rectangle::Left()
{
	return x - (width / 2);
}

/// <summary>
/// �l�p�`�̉E����̈ʒu���擾
/// </summary>
/// <returns></returns>
Vector2 Rectangle::TopRight()
{
	return Vector2(Right(), Top());
}

/// <summary>
/// �l�p�`�̍�����̈ʒu���擾
/// </summary>
/// <returns></returns>
Vector2 Rectangle::TopLeft()
{
	return Vector2(Left(), Top());
}

/// <summary>
/// �l�p�`�̉E�����̈ʒu���擾
/// </summary>
/// <returns></returns>
Vector2 Rectangle::BottomRight()
{
	return Vector2(Right(), Bottom());
}

/// <summary>
/// �l�p�`�̍������̈ʒu���擾
/// </summary>
/// <returns></returns>
Vector2 Rectangle::BottomLeft()
{
	return Vector2(Left(), Bottom());
}
