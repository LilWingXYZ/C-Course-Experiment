#include <string>
using namespace std;

class CD {
public:

	CD(string name, string songs[]);

	string getSinger();
	string getSong(int index);
	void listSongs();

private:
	string singer; // ���ֵ����֡�
	string songs[6]; // ÿ��ר��6�׸�����֡�
};
