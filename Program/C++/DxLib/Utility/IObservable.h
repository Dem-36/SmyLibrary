#ifndef _IOBSERVABLE_H_
#define _IOBSERVABLE_H_

#include<functional>

/// <summary>
/// �C���^�[�t�F�[�X
/// �o�^�����֐��̎��s����
/// </summary>
template<typename T>
class IObservable {
public:
	//���z�f�X�g���N�^
	virtual ~IObservable(){}

	//�����̓o�^(�������z�֐�)
	//std::function<�߂�l�̌^(�����̌^)> object = �֐�or �����_�� or �֐��I�u�C�F�N�g or�N���X�̃����o�֐�
	virtual void Subscribe(std::function<void(T)> func) = 0;
};

#endif