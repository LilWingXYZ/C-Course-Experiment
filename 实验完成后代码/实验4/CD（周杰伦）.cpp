#include<iostream>
#include<cstring>
using namespace std;

class CD {
public:
    CD(string name, string songs0[]) {
        songer = name;
        for (int i = 0; i<6; i++){
            songs[i] = songs0[i];
        }
    }
    string getSonger() {return songer;}   // 获得歌手的名称
    string getSong(int index) {return songs[index];}// 获得某首歌的歌名
    void listSongs() ;  // 列出CD的内容
private:
    string songer;  // 歌手的名字。
    string songs[6];  // 每张专辑6首歌的名字。
};

void CD::listSongs(){
    cout << "Songer:" << getSonger() <<endl;
    for (int i = 0; i<6; i++){
    cout<<" "<< i+1 <<". "<< getSong(i) <<endl;
    }
    cout << endl;
}

class CDPlayer {
public:
    CDPlayer(){
        cd = NULL;
        cdIn = false;
    };
    void showButtons();
    void insertCD(CD *cd);
    CD *ejectCD();
    void play();
private:
    CD *cd;
    bool cdIn;  // CDPlayer中是否已经插入CD
};

void CDPlayer::showButtons() {
    cout<<"*********************************"<<endl;
    cout<<"*  1. 播放 CD                   *"<<endl;
    cout<<"*  2. 插入 CD                   *"<<endl;
    cout<<"*  3. 弹出 CD                   *"<<endl;
    cout<<"*  0. 关机                      *"<<endl;
    cout<<"*********************************"<<endl;
}

void CDPlayer::insertCD(CD *cd0) {
    if (cd != NULL) cout<<"应先取出CD"<<endl;
    else {
        cd = cd0;
        cout<<"插入了"<<(*cd).getSonger()<<"的CD....."<<endl;
    }
    cout << endl;
}
void CDPlayer::play(){
    if (cd != NULL) {
            cout << "正在播放" << (*cd).getSonger() <<"的CD......"<< endl;
            (*cd).listSongs();
        }
    else {
        cout<< "Please insert CD first" << endl;
    }
    cout << endl;
}
CD *CDPlayer::ejectCD() {
    CD *temp;
    if (cd != NULL) {
        temp = cd;
        cd = NULL;
        cout<<"弹出了"<<(*temp).getSonger()<<"的CD......"<<endl;
        return temp;
    }
    else {
        cout<<"没有CD......"<<endl;
        return NULL;
    }
}

int main() {
    string name;
    string songs[6];

    cout << "\n制造CD......\n"; // 输入歌手名字
    cout << "  Songer's Name: ";
    cin >> name;  // 输入：周杰伦

    // 输入该歌手的六首歌名（青花瓷、菊花台、三节棍等）
    for (int i = 0; i < 6; i++) {
        cout << "  song" << (i+1) << "#: ";
        cin >> songs[i];
    }

    CD cd1(name, songs);
    cd1.listSongs();

    CDPlayer player;
    player.showButtons();
    /* 播放 */
    player.play();
    /* 插入CD */
    player.insertCD(&cd1);
    /* 播放 */
    player.play();
    player.ejectCD();

    cout << "\n制造CD......\n";
    cout << "  Songer's Name: ";
    cin >> name;                            //输入歌手名字
    for (int i = 0; i < 6; i++) {
        cout << "  song" << (i+1) << "#: "; //输入歌曲
        cin >> songs[i];
    }

    CD cd2(name, songs);
    player.insertCD(&cd2);
    player.play();
    return 0;
}
