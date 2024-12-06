#include<iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

static int answer;

// 2명의 Player를 선언하기 위한 클래스
class Person {
  string name;
 
 public:
  Person() {}
  void setName(string name){
    this->name = name;
  }
  string getName() {
    return this->name;
  }
};

// 게임을 진행하기 위한 클래스
class UpAndDownGame{
  Person *p;
 
 public:
  UpAndDownGame();
  ~UpAndDownGame();
  void setPlayer(string name1, string name2);
  void startGame();
};

UpAndDownGame::UpAndDownGame() {
  p = new Person[2];
  int n=rand()%100;
  answer = n;
}

UpAndDownGame::~UpAndDownGame() {
  delete[] p;
}

//플레이어의 이름을 입력받고 게임을 시작하는 함수
void UpAndDownGame::setPlayer(string name1, string name2) {
  p[0].setName(name1);
  p[1].setName(name2);
}

// 게임을 진행하는 함수
void UpAndDownGame::startGame(){
  int top=99;
  int bottom=0;
  int num;
  int i = 0;
 
  while(1){
    cout << "답은 " << bottom << "과 " << top << " 사이에 있습니다" << endl;
    cout << p[i].getName() << ">> ";
    cin >> num;
 
    if(answer > num)
      bottom = num;
    else if(answer < num)
      top = num;
 
    if(num == answer){
      cout << p[i].getName() <<"이(가) 이겼습니다!" << endl;
      break;
    }
    i++;
    if(i > 1) i = 0;
  }
}

int main(int argc, const char *argv[]){
  // 난수를 생성하기 위해 srand()함수를 사용한다
  srand((unsigned)time(0));
  UpAndDownGame udgame;
 
  cout << "Up & Down 게임을 시작합니다" << endl;

  string player1, player2;
  cout << "첫 번째 플레이어의 이름을 입력하세요: ";
  cin >> player1;
  cout << "두 번째 플레이어의 이름을 입력하세요: ";
  cin >> player2;

  udgame.setPlayer(player1, player2);
  udgame.startGame();
  return 0;
}