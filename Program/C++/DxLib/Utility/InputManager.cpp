#include"InputManager.h"
#include"DxLib.h"

InputManager* InputManager::instance = NULL;

InputManager* InputManager::Instance() {
	if (instance == NULL)
		instance = new InputManager();

	return instance;
}

void InputManager::DestroyInstance() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
	}
}

void InputManager::UpdateKey() {
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);//���ׂẴL�[�̓��͏�Ԃ�ۑ�
	int i;
	for (i = 0; i < ARRAYSIZE(tmpKey); i++) {
		if (tmpKey[i] != 0)
			key[i]++;//��������������邽�߂ɃC���N�������g���Ă���
		else if (tmpKey[i] == 0 && key[i] > 0)
			key[i] = -1;
		else
			key[i] = 0;
	}
}

/// <summary>
/// �L�[��������Ă��邩�ǂ���(�������Ή�)
/// </summary>
/// <param name="keyCode"></param>
/// <returns></returns>
bool InputManager::GetKey(int keyCode)
{
	//1�̏ꍇ��GetKeyDown(�����ꂽ����)
	if (key[keyCode] > 1)
		return true;

	return false;
}

/// <summary>
/// �L�[�������ꂽ���ǂ���(�����ꂽ����)
/// </summary>
/// <param name="keyCode"></param>
/// <returns></returns>
bool InputManager::GetKeyDown(int keyCode)
{
	if (key[keyCode] == 1)
		return true;

	return false;
}

/// <summary>
/// �L�[�������ꂽ���ǂ���(�����ꂽ����)
/// </summary>
/// <param name="keyCode"></param>
/// <returns></returns>
bool InputManager::GetKeyUp(int keyCode)
{
	if (key[keyCode] == -1)
		return true;

	return false;
}
