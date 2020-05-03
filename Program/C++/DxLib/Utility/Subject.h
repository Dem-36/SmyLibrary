#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include"IObserver.h"
#include"IObservable.h"
#include<list>

template<typename T>
class Subject :public IObservable<T>, public IObserver<T> {
public:
	//�C�x���g�̒ʒm���o�^
	void Subscribe(std::function<void(T)> func) {
		_list.push_back(func);
	}

	//�o�^����Ă���֐������s����
	void OnNext(T value) {
		for (std::function<void(T)> s: _list) {
			//�o�^����Ă���֐����Ăяo��
			s(value);
		}
	}

	/// <summary>
	/// �Ώۂ̃N���A
	/// </summary>
	void Dispose() {
		_list.clear();
	}

private:
	std::list<std::function<void(T)>> _list;
};

#endif