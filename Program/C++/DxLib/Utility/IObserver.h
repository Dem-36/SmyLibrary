#ifndef _IOBSERVER_H_
#define _IOBSERVER_H_

/// <summary>
/// �I�u�U�[�o�[�C���^�[�t�F�[�X
/// </summary>
template<typename T>
class IObserver {
public:
	virtual ~IObserver(){}

	//�o�^���ꂽ�����̎��s(�������z�֐�)
	virtual void OnNext(T value) = 0;
};

#endif