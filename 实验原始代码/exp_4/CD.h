#include <string>
using namespace std;

class CD {
public:

	CD(string name, string songs[]);

	string getSinger();
	string getSong(int index);
	void listSongs();

private:
	string singer; // 歌手的名字。
	string songs[6]; // 每张专辑6首歌的名字。
};
