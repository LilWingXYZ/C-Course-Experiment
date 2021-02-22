#include "CD.h"

class CDPlayer {
public:
	CDPlayer();

	// �ṩ���û�һ���˵�.
	// ͨ������˵����û�����ѡ��
	// 1. ����CD
	// 2. ����CD
	// 3. ����CD
	// 0. �ػ�
	void showButtons();

	// ����CD���β���ָ��CD�����ָ��.
	// ���CDPlayer���Ѿ���CD����ʾ��ȡ��CD;
	// ���CDPlayer��û��CD����ʾ��������λ���ǵ�CD.
	void insertCD(CD* cd);

	// ����CD������ֵ��ָ���CD�����ָ��.
	// ���CDPlayer���Ѿ���CD����ʾ��������λ���ǵ�CD�����ظ�CD��ָ��;
	// ���CDPlayer��û��CD����ʾCDPlayer��û��CD������NULL.
	CD* ejectCD();

	// ����CD.
	// ���CDPlayer���Ѿ���CD����ʾ���ڲ�����λ���ǵ�CD;
	// ���CDPlayer��û��CD����ʾCDPlayer��û��CD��
	// ����ʾ�û�����CD.
	void play();

private:
	CD* cd; // ����CDPlayer�е�CD������ָ��CD�����ָ��
	bool cdIn; // CDPlayer���Ƿ��Ѿ�����CD
};
