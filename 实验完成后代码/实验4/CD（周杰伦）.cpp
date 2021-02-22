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
    string getSonger() {return songer;}   // ��ø��ֵ�����
    string getSong(int index) {return songs[index];}// ���ĳ�׸�ĸ���
    void listSongs() ;  // �г�CD������
private:
    string songer;  // ���ֵ����֡�
    string songs[6];  // ÿ��ר��6�׸�����֡�
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
    bool cdIn;  // CDPlayer���Ƿ��Ѿ�����CD
};

void CDPlayer::showButtons() {
    cout<<"*********************************"<<endl;
    cout<<"*  1. ���� CD                   *"<<endl;
    cout<<"*  2. ���� CD                   *"<<endl;
    cout<<"*  3. ���� CD                   *"<<endl;
    cout<<"*  0. �ػ�                      *"<<endl;
    cout<<"*********************************"<<endl;
}

void CDPlayer::insertCD(CD *cd0) {
    if (cd != NULL) cout<<"Ӧ��ȡ��CD"<<endl;
    else {
        cd = cd0;
        cout<<"������"<<(*cd).getSonger()<<"��CD....."<<endl;
    }
    cout << endl;
}
void CDPlayer::play(){
    if (cd != NULL) {
            cout << "���ڲ���" << (*cd).getSonger() <<"��CD......"<< endl;
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
        cout<<"������"<<(*temp).getSonger()<<"��CD......"<<endl;
        return temp;
    }
    else {
        cout<<"û��CD......"<<endl;
        return NULL;
    }
}

int main() {
    string name;
    string songs[6];

    cout << "\n����CD......\n"; // �����������
    cout << "  Songer's Name: ";
    cin >> name;  // ���룺�ܽ���

    // ����ø��ֵ����׸������໨�ɡ��ջ�̨�����ڹ��ȣ�
    for (int i = 0; i < 6; i++) {
        cout << "  song" << (i+1) << "#: ";
        cin >> songs[i];
    }

    CD cd1(name, songs);
    cd1.listSongs();

    CDPlayer player;
    player.showButtons();
    /* ���� */
    player.play();
    /* ����CD */
    player.insertCD(&cd1);
    /* ���� */
    player.play();
    player.ejectCD();

    cout << "\n����CD......\n";
    cout << "  Songer's Name: ";
    cin >> name;                            //�����������
    for (int i = 0; i < 6; i++) {
        cout << "  song" << (i+1) << "#: "; //�������
        cin >> songs[i];
    }

    CD cd2(name, songs);
    player.insertCD(&cd2);
    player.play();
    return 0;
}
