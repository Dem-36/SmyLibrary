#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

class InputManager {
private:
	//�R���X�g���N�^��private�ɂ��A
	//�O������C���X�^���X����������Ȃ��悤�ɂ���
	InputManager(){}
	InputManager(const InputManager&){}
public:
	static InputManager* Instance();
	static void DestroyInstance();
public:
	void UpdateKey();
	bool GetKey(int);
	bool GetKeyDown(int);
	bool GetKeyUp(int);
private:
	char key[256];//�L�[���ۑ�
	static InputManager* instance;
};

#endif