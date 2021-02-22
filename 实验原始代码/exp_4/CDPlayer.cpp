#include <iostream>
#include <string>
#include "CDPlayer.h"

using namespace std;

CDPlayer::CDPlayer() {
	cd = NULL;
	cdIn = false;
}

void CDPlayer::insertCD(CD *cd) {
	if (cdIn)
		cout << "CD already in, to change, eject it first......\n";
	else {
		CDPlayer::cd = cd;
		cdIn = true;
		cout << "������" << cd->getSinger() << "��CD......\n";
	}
}

CD* CDPlayer::ejectCD() {
	CD* temp = cd;
	if (cdIn) {
		cout << "������" << cd->getSinger() << "��CD......\n";
		cdIn = false;
		cd = 0;
		return temp;
	} else {
		cout << "No CD.\n";
		return NULL;
	}
}

void CDPlayer::play() {
	if (cdIn) {
		cout << "���ڲ���" << cd->getSinger() << "��CD......\n";
		cd->listSongs();
		/*for (int i = 0; i < 6; i++)
		 cout << "  Song" << (i+1) << "#: " << cd->getSong(i) << endl;*/
	} else
		cout << "Please insert CD first\n";
}

void CDPlayer::showButtons() {
	cout << endl;
	cout << "**************************************\n";
	cout << "*  1. ����CD                         *\n";
	cout << "*  2. ����CD                         *\n";
	cout << "*  3. ����CD                         *\n";
	cout << "*  0. �ػ�                           *\n";
	cout << "**************************************\n";
}

int main() {
	string name;
	string songs[6];

	cout << "\n����CD......\n";
	// ����������� 
	cout << "  Singer's Name: ";
	cin >> name; // ���룺�ܽ���

	// ����ø��ֵ����׸������໨�ɡ��ջ�̨�����ڹ��ȣ�
	for (int i = 0; i < 6; i++) {
		cout << "  song" << (i + 1) << "#: ";
		cin >> songs[i];
	}

	// ����CD
	CD cd(name, songs);
	// ��ʾCD������
	cd.listSongs();

	// ����CDplayer
	CDPlayer player;

	// ���ɲ��Ż��İ�ť
	player.showButtons();

	// ����
	player.play(); // ��ӡ��Please insert CD first
	// ����CD
	player.insertCD(&cd); // ��ӡ���������ܽ��׵�CD......
	// ����
	player.play(); // ��ӡ�����ڲ����ܽ��׵�CD......
				   //         song1#: �໨��
				   //         song2#: �ջ�̨
				   //         song3#: ���ڹ�
				   //         song4#: ������
				   //         song5#: ɺ����
				   //         song6#: ����
	player.ejectCD(); // ��ӡ���������ܽ��׵�CD......

	return 0;
}
