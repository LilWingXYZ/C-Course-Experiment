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
		cout << "插入了" << cd->getSinger() << "的CD......\n";
	}
}

CD* CDPlayer::ejectCD() {
	CD* temp = cd;
	if (cdIn) {
		cout << "弹出了" << cd->getSinger() << "的CD......\n";
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
		cout << "正在播放" << cd->getSinger() << "的CD......\n";
		cd->listSongs();
		/*for (int i = 0; i < 6; i++)
		 cout << "  Song" << (i+1) << "#: " << cd->getSong(i) << endl;*/
	} else
		cout << "Please insert CD first\n";
}

void CDPlayer::showButtons() {
	cout << endl;
	cout << "**************************************\n";
	cout << "*  1. 播放CD                         *\n";
	cout << "*  2. 插入CD                         *\n";
	cout << "*  3. 弹出CD                         *\n";
	cout << "*  0. 关机                           *\n";
	cout << "**************************************\n";
}

int main() {
	string name;
	string songs[6];

	cout << "\n制造CD......\n";
	// 输入歌手名字 
	cout << "  Singer's Name: ";
	cin >> name; // 输入：周杰伦

	// 输入该歌手的六首歌名（青花瓷、菊花台、三节棍等）
	for (int i = 0; i < 6; i++) {
		cout << "  song" << (i + 1) << "#: ";
		cin >> songs[i];
	}

	// 制造CD
	CD cd(name, songs);
	// 显示CD的内容
	cd.listSongs();

	// 制造CDplayer
	CDPlayer player;

	// 生成播放机的按钮
	player.showButtons();

	// 播放
	player.play(); // 打印：Please insert CD first
	// 插入CD
	player.insertCD(&cd); // 打印：插入了周杰伦的CD......
	// 播放
	player.play(); // 打印：正在播放周杰伦的CD......
				   //         song1#: 青花瓷
				   //         song2#: 菊花台
				   //         song3#: 三节棍
				   //         song4#: 东风破
				   //         song5#: 珊瑚海
				   //         song6#: 稻香
	player.ejectCD(); // 打印：弹出了周杰伦的CD......

	return 0;
}
