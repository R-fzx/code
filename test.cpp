#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
string ty[5] = {"", "红桃", "黑桃", "方片", "梅花"};
string winning[3] = {"铜牌胜利！", "银牌胜利！", "金牌胜利！"};
const int PL = 8;  // PL ->pack limit
int tbs, tp, td, tb, jokers = 2, gameover, atk, def, isbd;
struct card {
  string typ;
  int num;  // 11->J, 15->Q, 20->K

  void setype(int t, int n) {
    typ = ty[t];
    num = n;
  };

  void out() {
    cout << typ;
    if (num == 11)
      printf("J");
    else if (num == 15)
      cout << 'Q';
    else if (num == 20)
      cout << 'K';
    else if (num == 1)
      cout << 'A';
    else
      cout << num;
    cout << ' ';
  }
};
card bosses[13], pack[9], deads[100], bar[100], now;
bool cmt(card a, card b) {
  return a.num < b.num;
}
void draw() {
  pack[++tp] = bar[tb--];
}
void csh() {
  bosses[1].setype(1, 11), bosses[2].setype(2, 11), bosses[3].setype(3, 11), bosses[4].setype(4, 11);
  bosses[5].setype(1, 15), bosses[6].setype(2, 15), bosses[7].setype(3, 15), bosses[8].setype(4, 15);
  bosses[9].setype(1, 20), bosses[10].setype(2, 20), bosses[11].setype(3, 20), bosses[12].setype(4, 20);
  srand((unsigned int)(time(NULL)));
  for (int i = 1; i <= 12; i++) {
    int swaper = rand() % 4 + 1;
    if (i >= 5 && i <= 8)
      swaper += 4;
    else if (i >= 9)
      swaper += 8;
    card tmp = bosses[i];
    bosses[i] = bosses[swaper];
    bosses[swaper] = tmp;
  }
  tbs = 1;
  now = bosses[tbs++];
  atk = 10;
  def = 20;
  srand((unsigned int)(time(NULL)));
  for (int i = 0; i < 40; i++) {
    int ttt = i / 10 + 1;
    int nnn = i % 10 + 1;
    bar[i + 1].setype(ttt, nnn);
  }
  tb = 40;
  for (int i = 1; i <= 40; i++) {
    int swaper = rand() % 40 + 1;
    card tmp = bar[i];
    bar[i] = bar[swaper];
    bar[swaper] = tmp;
  }
  for (int i = 1; i <= PL; i++)
    draw();
}

void deal(int dmg, int iH, int iD, int iC, int iS) {
  if (iH && now.typ != "红桃") {
    for (int i = 1; i <= td; i++) {
      int swaper = rand() % td + 1;
      card tmp = deads[i];
      deads[i] = deads[swaper];
      deads[swaper] = tmp;
    }

    card rev[100];
    int tr = 0;

    for (int i = 1; i <= dmg && td > 0; i++)
      rev[++tr] = deads[td--];

    for (int i = 1; i <= tb; i++)
      rev[++tr] = bar[i];

    tb = tr;

    for (int i = 1; i <= tr; i++)
      bar[i] = rev[i];
    cout << "复生了" << dmg << "张牌" << endl;
  }
  if (iD && now.typ != "方片") {
    int ds = 0;
    for (int i = 1; i <= dmg && tp < PL; i++)
      draw(), ds++;
    cout << "摸了" << ds << "张牌" << endl;
  }
  if (iS && now.typ != "黑桃") {
    atk -= dmg;
    if (atk < 0)
      atk = 0;
    cout << "现在BOSS的攻击力被降为了" << atk << endl;
  }
  if (iC && now.typ != "梅花")
    dmg *= 2;
  def -= dmg;
  cout << "造成了" << dmg << "点伤害" << endl;
  if (def == 0) {
    isbd = 1;
    cout << "BOSS被感化了！" << endl;

    bar[++tb] = now;

    if (tbs == 13) {
      cout << "你赢了！" << endl;
      cout << winning[jokers] << endl;
      exit(0);
    }
    now = bosses[tbs++];
    if (tbs - 1 >= 1 && tbs - 1 <= 4) {
      atk = 10;
      def = 20;
    } else if (tbs - 1 >= 5 && tbs - 1 <= 8) {
      atk = 15;
      def = 30;
    } else if (tbs - 1 >= 9 && tbs - 1 <= 12) {
      atk = 20;
      def = 40;
    }
  } else if (def < 0) {
    isbd = 1;
    cout << "BOSS被杀死了！" << endl;
    deads[++td] = now;
    if (tbs == 13) {
      cout << "你赢了！" << endl;
      cout << winning[jokers] << endl;
      exit(0);
    }
    now = bosses[tbs++];
    if (tbs - 1 >= 1 && tbs - 1 <= 4) {
      atk = 10;
      def = 20;
    } else if (tbs - 1 >= 5 && tbs - 1 <= 8) {
      atk = 15;
      def = 30;
    } else if (tbs - 1 >= 9 && tbs - 1 <= 12) {
      atk = 20;
      def = 40;
    }
  }
}

bool check(card checker[], int top) {
  int pet = 0, digit = -1, petail = -1, dm = 0;
  for (int i = 1; i <= top; i++) {
    dm += checker[i].num;
    if (checker[i].num == 1)
      pet = 1;
    else {
      if (checker[i - 1].num == 1)
        petail = i - 1;
      if (checker[i].num != digit && digit != -1)
        return false;
      if (checker[i].num != digit && digit == -1)
        digit = checker[i].num;
      if (checker[i].num == checker[i - 1].num && checker[i].num != 1) {
        if (pet)
          return false;
        if (dm > 10)
          return false;
      }
    }
  }
  return true;
}

void chupai() {
A:
  if (tp == 0) {
    cout << "你输了！";
    exit(0);
  }
  cout << "请出牌（输入你所出的手牌的数量，并依次输入要出的手牌的序号，使用Joker请输入100）：";
  int nn;
  cin >> nn;
  if (nn == 100)
    if (jokers) {
      jokers--;
      while (tp > 0)
        deads[++td] = pack[tp--];
      for (int i = 1; i <= 8 && tb > 0; i++)
        draw();
      cout << "使用了Joker，你的手牌：";
      for (int i = 1; i <= tp; i++) {
        cout << '(' << i << ").";
        pack[i].out();
      }
      cout << endl;
      goto A;
    } else {
      cout << "你没有Joker了！" << endl;
      goto A;
    }
  else {
    int c, numm = 0, H = 0, D = 0, C = 0, S = 0, book[10] = {0}, to = 0, deals[10], tds = 0;
    card isok[10];
    for (int i = 1; i <= nn; i++) {
      cin >> c;
      book[c] = 1;
      if (pack[c].typ == "红桃")
        H = 1;
      if (pack[c].typ == "方片")
        D = 1;
      if (pack[c].typ == "梅花")
        C = 1;
      if (pack[c].typ == "黑桃")
        S = 1;
      if (pack[c].num == 11)
        numm += 10;
      else
        numm += pack[c].num;
      deals[++tds] = c;
      isok[++to] = pack[c];
      //          if(c == tp)
      //              while(book[tp] && tp > 0)
      //                  tp--;
    }
    sort(isok + 1, isok + to + 1, cmt);
    if (check(isok, to)) {
      for (int i = 1; i <= tds; i++)
        deads[++td] = pack[deals[i]];
      while (book[tp] && tp > 0)
        tp--;
      for (int i = 1; i <= tp; i++) {
        if (book[i]) {
          card tmp = pack[i];
          pack[i] = pack[tp];
          pack[tp] = tmp;
          book[i] = 0;
          do {
            tp--;
          } while (book[tp] && tp > 0);
        }
      }
      deal(numm, H, D, C, S);
    } else {
      cout << "出牌不合法！" << endl
           << endl;
      goto A;
    }
  }
}

void damage() {
  int sum = 0;
  for (int i = 1; i <= tp; i++) {
    if (pack[i].num == 11)
      sum += 10;
    else
      sum += pack[i].num;
  }
  if (sum < atk) {
    cout << "你输了！" << endl;
    exit(0);
  }
C:
  cout << "你受到" << atk << "点伤害！请弃牌！" << endl;
  for (int i = 1; i <= tp; i++) {
    cout << '(' << i << ").";
    pack[i].out();
  }
  cout << endl;
  int nn;
  cout << "请输入你要弃掉的牌的数量，并依次输入这些牌的序号（使用Joker请输入100）：";
  cin >> nn;
  if (nn == 100)
    if (jokers) {
      jokers--;
      while (tp > 0)
        deads[++td] = pack[tp--];
      for (int i = 1; i <= 8 && tb > 0; i++)
        draw();
      cout << "使用了Joker，你的手牌：";
      for (int i = 1; i <= tp; i++) {
        cout << '(' << i << ").";
        pack[i].out();
      }
      cout << endl;
      goto C;
    } else {
      cout << "你没有Joker了！" << endl;
      goto C;
    }
  else {
    int c, book[10] = {0}, bloods = 0, deals[10], tds = 0;
    for (int i = 1; i <= nn; i++) {
      cin >> c;
      if (c <= 0 || c > tp || book[c] == 1) {
        cout << "弃牌错误！" << endl;
        goto C;
      }
      book[c] = 1;
      if (pack[c].num == 11)
        bloods += 10;
      else
        bloods += pack[c].num;
      deals[++tds] = c;
    }
    if (bloods < atk) {
      cout << "弃牌不足以抵挡伤害！" << endl;
      goto C;
    }
    for (int i = 1; i <= tds; i++)
      deads[++td] = pack[deals[i]];
    for (int i = 1; i <= tp; i++) {
      while (book[tp] && tp > 0)
        tp--;
      for (int i = 1; i <= tp; i++) {
        if (book[i]) {
          card tmp = pack[i];
          pack[i] = pack[tp];
          pack[tp] = tmp;
          book[i] = 0;
          do {
            tp--;
          } while (book[tp] && tp > 0);
        }
      }
    }
  }
}

void game() {
  while (!gameover) {
    //      cout << endl;
    //      for(int i = 1; i <= td; i++)
    //          deads[i].out();
    //      cout << endl;
    cout << endl
         << endl
         << "当前Boss: ";
    now.out();
    cout << "攻击" << atk << ", 体力" << def << "  城堡内Boss数：" << 12 - tbs + 1 << endl;
    cout << "你的手牌：";
    for (int i = 1; i <= tp; i++) {
      cout << '(' << i << ").";
      pack[i].out();
    }
    cout << endl
         << "Joker剩余：" << jokers << endl;
    cout << "弃牌堆牌数:" << td << ", 酒吧牌数:" << tb << endl;
    chupai();
    if (!isbd && atk)
      damage();
    if (isbd)
      isbd = 0;
  }
}

int main() {
  csh();
  game();
  return 0;
}