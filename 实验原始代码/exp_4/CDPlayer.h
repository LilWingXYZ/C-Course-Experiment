#include "CD.h"

class CDPlayer {
public:
	CDPlayer();

	// 提供给用户一个菜单.
	// 通过这个菜单，用户可以选择
	// 1. 插入CD
	// 2. 播放CD
	// 3. 弹出CD
	// 0. 关机
	void showButtons();

	// 插入CD，形参是指向CD对象的指针.
	// 如果CDPlayer中已经有CD，提示先取出CD;
	// 如果CDPlayer中没有CD，显示插入了哪位歌星的CD.
	void insertCD(CD* cd);

	// 弹出CD，返回值是指向该CD对象的指针.
	// 如果CDPlayer中已经有CD，显示弹出了哪位歌星的CD，返回该CD的指针;
	// 如果CDPlayer中没有CD，提示CDPlayer中没有CD，返回NULL.
	CD* ejectCD();

	// 播放CD.
	// 如果CDPlayer中已经有CD，显示正在播放哪位歌星的CD;
	// 如果CDPlayer中没有CD，显示CDPlayer中没有CD，
	// 并提示用户插入CD.
	void play();

private:
	CD* cd; // 插入CDPlayer中的CD，它是指向CD对象的指针
	bool cdIn; // CDPlayer中是否已经插入CD
};
