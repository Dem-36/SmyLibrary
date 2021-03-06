#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include"IObserver.h"
#include"IObservable.h"
#include<list>

template<typename T>
class Subject :public IObservable<T>, public IObserver<T> {
public:
	//イベントの通知先を登録
	void Subscribe(std::function<void(T)> func) {
		_list.push_back(func);
	}

	//登録されている関数を実行する
	void OnNext(T value) {
		for (std::function<void(T)> s: _list) {
			//登録されている関数を呼び出す
			s(value);
		}
	}

	/// <summary>
	/// 対象のクリア
	/// </summary>
	void Dispose() {
		_list.clear();
	}

private:
	std::list<std::function<void(T)>> _list;
};

#endif