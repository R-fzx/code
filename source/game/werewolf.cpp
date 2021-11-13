/*
狼人杀V2.0
更新平票系统、警长 
代码整理 
各种Bug修复
*/
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;

const int daytime = 0, night = 1;
int day = 0, during_time = daytime, player_number, my_number;
HWND hwnd = GetForegroundWindow();  //窗口定义

/*设置颜色*/
const int blue = 0, yellow = 1, red = 2, green = 3, purple = 4, white = 5;  //颜色常量
void color(int c) {
  switch (c) {
    case red:
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
      break;
    case green:
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
      break;
    case yellow:
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
      break;
    case blue:
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
      break;
    case white:
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
      break;
    case purple:
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
      break;
  }
}
int idx_police = -1;

/*控制光标在控制台的位置 */
void gotoxy(int x, int y) {
  COORD position;
  position.X = x;
  position.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

/*初始化窗口*/
void init_Show_Window() {
  system("mode con lines=60 cols=188");  //全屏
  ShowWindow(hwnd, SW_MAXIMIZE);         //窗口最大化
  DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_BYCOMMAND);
  DrawMenuBar(GetConsoleWindow());  //删除×字符
}

/*玩家类*/
const int nvwu = 0, cunmin = 1, yuyanjia = 2, langren = 3, lieren = 4, shouwei = 5, good = 6, die = 1, life = 2;
class player {
 public:
  int type;
  int die_or_life;
  int how() {
    return die_or_life;
  }
  int is_light;  //是否已经公布
  int killer;
};
player players[1000];

/*转换白天模式*/
void change_daytime() {
  during_time = daytime;
  day++;
}

/*转换黑夜模式*/
void change_night() {
  during_time = night;
}
int nnvwu = 0, ncunmin = 0, nyuyanjia = 0, nlangren = 0, nlieren = 0, nshouwei = 0;
int idxnvwu, idxshouwei, idxyuyanjia, idxlieren, idxlangren[4] = {-1, -1, -1, -1};

/*b是否在Arr中*/
bool is_include(int arr[], int b, int l) {
  for (int i = 0; i < l; i++) {
    if (arr[i] == b)
      return true;
  }
  return false;
}

/*初始化人数*/
void init_players() {
  my_number = rand() % player_number;
  if (player_number == 12)
    nlangren = 4;
  else if (player_number >= 10)
    nlangren = 3;
  else
    nlangren = 2;
  for (int i = 0; i < player_number; i++) {
    players[i].die_or_life = life;
    players[i].is_light = 0;
    players[i].type = -1;
    players[i].killer = 2147483647;
  }
  for (int i = 0; i < nlangren; i++) {
    int p = rand() % player_number;
    if (!is_include(idxlangren, p, 4))
      idxlangren[i] = p, players[p].type = langren;
    else
      i--;
    Sleep(rand() % 80 + 100);
  }
  if (player_number == 12) {
    do {
      idxshouwei = rand() % player_number;
    } while (players[idxshouwei].type != -1);
    players[idxshouwei].type = shouwei;
  }
  do {
    idxnvwu = rand() % player_number;
  } while (players[idxnvwu].type != -1);
  players[idxnvwu].type = nvwu;
  if (player_number >= 10) {
    do {
      idxlieren = rand() % player_number;
    } while (players[idxlieren].type != -1);
    players[idxlieren].type = lieren;
  }
  do {
    idxyuyanjia = rand() % player_number;
  } while (players[idxyuyanjia].type != -1);
  players[idxyuyanjia].type = yuyanjia;
  for (int i = 0; i < player_number; i++)
    if (players[i].type == -1)
      players[i].type = cunmin,
      ncunmin++;
  if (players[my_number].type == langren) {
    for (int i = 0; i < nlangren; i++) {
      players[idxlangren[i]].is_light = 1;
    }
  }
  players[my_number].is_light = 1;
}

/*在屏幕上打印东西*/
void print() {
  gotoxy(0, 0);
  cout << "作者：洛谷393864";
  gotoxy(90, 0);
  if (during_time == night)
    color(red);
  else
    color(blue);
  printf("第%d天 | ", day);
  if (during_time == night)
    cout << "黑夜";
  else
    cout << "白天";

  gotoxy(0, 3);
  color(blue);
  cout << " 我的号位:" << my_number + 1;
  for (int i = 0; i < player_number; i++) {
    gotoxy(i * 8 + 1, 4);
    if (i == idx_police)
      color(yellow);
    else
      color(blue);
    cout << i + 1 << "号位";
    gotoxy(i * 8 + 1, 5);
    if (players[i].how() == die) {
      color(red);
      cout << "死 亡";
    } else {
      color(green);
      cout << "存 活";
    }
    gotoxy(i * 8 + 1, 6);
    color(blue);
    if (players[i].is_light) {
      if (players[i].is_light == 1) {
        switch (players[i].type) {
          case nvwu:
            cout << "女 巫";
            break;
          case yuyanjia:
            cout << "\b预言家";
            break;
          case cunmin:
            cout << "村 民";
            break;
          case langren:
            cout << "狼 人";
            break;
          case lieren:
            cout << "猎 人";
            break;
          case shouwei:
            cout << "守 卫";
            break;
        }
      } else {
        cout << "好人";
      }

    } else {
      cout << "未知";
    }
  }
}

/*判断是否结束,没结束返回0  好人胜利返回1  狼人胜利返回2   平局返回3*/
int is_end() {
  int die_bad = 0;
  int die_people = 0;
  int die_god = 0;
  for (int i = 0; i < player_number; i++) {
    if ((players[i].type == nvwu || players[i].type == yuyanjia || players[i].type == shouwei) && players[i].die_or_life == die)
      die_god++;
    else if (players[i].type == langren && players[i].die_or_life == die)
      die_bad++;
    else if (players[i].type == cunmin && players[i].die_or_life == die)
      die_people++;
  }
  if ((die_bad == die_people || die_bad == die_god) && (die_bad >= nlangren))
    return 3;
  if (die_bad >= nlangren)
    return 1;
  if (die_people >= ncunmin || die_god >= (player_number >= 10 ? 3 : 2))
    return 2;
  return 0;
}

/*游戏开始前的骚操作*/
void before_game() {
  srand(time(NULL));
  init_Show_Window();
  color(green);
  cout << "欢迎来到狼人杀游戏\t\t\t为了更好的游戏体验,请右键点击上方↑↑,点击\"属性\",点击\"字体\"栏目,将字体修改为宋体或新宋体,将字号改为20\n作者：洛谷393864\n请勿私自转载,违者依法追究法律责任  注：10 11 12人局开设猎人  12人局开设守卫警长\n______________________\n";
  cout << "请输入玩家人数(8-12人):";
  cin >> player_number;
  while (player_number < 8 || player_number > 12) {
    cout << "请重新输入！\n";
    cin >> player_number;
  }
  system("cls");
  cout << "初始化身份中，请稍等.";
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 12; j++) {
      cout << ".";
      Sleep(50);
    }
    cout << "\b\b\b\b\b\b\b\b\b\b\b\b            \b\b\b\b\b\b\b\b\b\b\b\b";
  }
  system("cls");

  init_players();
  cout << "我的号位:" << my_number + 1 << endl
       << "我的身份:";
  switch (players[my_number].type) {
    case nvwu:
      cout << "女巫\n";
      break;
    case yuyanjia:
      cout << "预言家\n";
      break;
    case cunmin:
      cout << "村民\n";
      break;
    case langren:
      cout << "狼人\n";
      break;
    case lieren:
      cout << "猎人\n";
      break;
    case shouwei:
      cout << "守卫\n";
      break;
  }
  change_daytime();
  system("pause");
  system("cls");
  cout << "游戏加载中.";
  int ppppp = rand() % 3 + 2;
  for (int i = 0; i < ppppp; i++) {
    for (int j = 0; j < 6; j++) {
      cout << ".";
      Sleep(rand() % 100 + 150);
    }
    cout << "\b\b\b\b\b\b      \b\b\b\b\b\b";
  }
  print();
}

/*每一天开始前的操作*/
void something_before_everyday() {
  change_night();
  system("cls");
  print();
  int langrensha = -1, NVWUDU = -1, nvwujiu = -1, shouweishou = -1;
  gotoxy(0, 7);
  cout << "________________________";
  gotoxy(0, 8);
  color(white);
  cout << "天黑~请闭眼~~~\n";
}

/*守卫操作*/
int shouweishou = 0;
int ShouWei() {
  color(blue);
  cout << "守卫~请睁眼~~\n";
  Sleep(1500);
  cout << "你要守护的是?\n";
  if (players[my_number].type == shouwei && players[my_number].die_or_life == life) {
    cin >> shouweishou;
    while (!(shouweishou >= 1 && shouweishou <= player_number && players[shouweishou - 1].die_or_life == life)) {
      cout << "请重新输入！\n";
      cin >> shouweishou;
    }
    cout << "你今晚要守护的是" << shouweishou << "号\n";
    Sleep(1500);
    shouweishou--;
  } else {
    if (players[idxshouwei].die_or_life == life) {
      shouweishou = rand() % 10;
      while (!(shouweishou >= 1 && shouweishou <= player_number && players[shouweishou - 1].die_or_life == life)) {
        shouweishou = rand() % 10;
      }
    }
  }
  Sleep(2000);
  cout << "守卫请闭眼" << endl
       << endl;
  return shouweishou;
}

/*狼人操作*/
int LangRen() {
  int langrensha = -1;
  color(red);
  cout << "狼人~请睁眼~~~\n";
  Sleep(1500);
  cout << "你们今晚要杀~谁~~??\n";
  if (players[my_number].type == langren && players[my_number].die_or_life == life) {
    cin >> langrensha;
    while (!(langrensha >= 1 && langrensha <= player_number && players[langrensha - 1].die_or_life == life)) {
      cout << "请重新输入!\n";
      cin >> langrensha;
    }
    cout << "你们今晚要杀的是" << langrensha-- << "号\n";
    Sleep(3500);
  } else {
    while (langrensha == -1 || players[langrensha].die_or_life == die || players[langrensha].type == langren) {
      langrensha = rand() % player_number;
    }
    Sleep(3000);
  }
  cout << "狼人请~闭眼~~\n\n";
  return langrensha;
}

/*女巫操作*/
int nvwujiu = 0, nvwudu = 0, is_nvwujiu = 0, is_nvwudu = 0;
int NvWu(int langrensha) {
  color(purple);
  cout << "女巫~~请睁眼~~\n";
  Sleep(2000);
  if (players[my_number].type == nvwu && players[my_number].die_or_life == life) {
    if (is_nvwujiu)
      cout << "你已经用过解药\n", Sleep(1500);
    else {
      cout << "今晚" << langrensha + 1 << "号死了,你想用解药吗？(1想 / 2不想)\n";
      int is_nvwujie = 0;
      cin >> is_nvwujie;
      while (is_nvwujie != 1 && is_nvwujie != 2) {
        cout << "请重新输入\n";
        cin >> is_nvwujie;
      }
      if (is_nvwujie == 1) {
        Sleep(1000);
        cout << "已经解救" << langrensha + 1 << "号\n";
        nvwujiu = langrensha;
      }
      is_nvwujiu = 1;
    }
    Sleep(1500);
    if (::is_nvwudu)
      cout << "你已经用过解药\n", Sleep(1500);
    else {
      cout << "你想用毒药吗？（1想 / 2不想）\n";
      Sleep(1500);
      int is_nvwudu = 0;
      cin >> is_nvwudu;
      while (is_nvwudu != 1 && is_nvwudu != 2) {
        cout << "请重新输入\n";
        cin >> is_nvwudu;
      }
      if (is_nvwudu == 1) {
        Sleep(1500);
        cout << "你想毒谁？\n";
        cin >> nvwudu;
        while (!(nvwudu >= 1 && nvwudu <= player_number && players[nvwudu].die_or_life == life)) {
          cout << "请重新输入\n";
          cin >> nvwudu;
        }
        nvwudu--;
        Sleep(1500);
        cout << "已经毒死了" << nvwudu + 1 << "号\n";
      }
      ::is_nvwudu = 1;
    }
  } else {
    if (players[idxnvwu].die_or_life == life) {
      if (!is_nvwujiu) {
        int is_jiu = rand() % 8;
        if (is_jiu == 0) {
          nvwujiu = langrensha;
          is_nvwujiu = 1;
        }
      }
      if (!is_nvwudu) {
        int is_du = rand() % 4;
        if (is_du == 0) {
          int num = rand() % player_number;
          nvwudu = num;
          is_nvwudu = 1;
        }
      }
    }
  }
  cout << "女巫~请闭眼~~\n\n";
  return nvwujiu * 10000 + nvwudu;  //传回两个变量，“加密”操作
}

int yuyanjiabixutoupiao = -1;
/*预言家操作*/
void YuYanJia() {
  color(green);
  cout << "预言家~请睁眼~~\n";
  Sleep(2000);
  if (players[my_number].type == yuyanjia && players[my_number].die_or_life == life) {
    cout << "请问你想查验谁的身份\n";
    int p;
    cin >> p;
    while (!(p >= 1 && p <= player_number)) {
      cout << "请重新输入！\n";
      cin >> p;
    }
    Sleep(2000);
    cout << p << "号的身份是——";
    Sleep(1000);
    if (players[p - 1].type == langren) {
      cout << "狼人\n";
      players[p - 1].is_light = 1;
    } else {
      cout << "好人\n";
      players[p - 1].is_light = 2;
    }
  } else {
    int p = -1;
    while (p == -1 || players[p].die_or_life == die || p == idxlieren)
      p = rand() % player_number;
    if (players[p].type == langren)  //锁定目标!
    {
      yuyanjiabixutoupiao = p;
    }
  }
  cout << "预言家~~请闭眼~~\n";
}

/*黑夜操作*/
int LANGRENSHA = -1, NVWUDU = -1, NVWUJIU = -1, SHOUWEISHOU = -1;
void Night() {
  LANGRENSHA = -1, NVWUDU = -1, NVWUJIU = -1, SHOUWEISHOU = -1;

  //如果有12人局，添加守卫
  if (player_number == 12) {
    SHOUWEISHOU = ShouWei();
    Sleep(2000);
  }
  /*狼人部分*/
  LANGRENSHA = LangRen();
  Sleep(3500);
  /*女巫部分*/
  int nvwu = NvWu(LANGRENSHA);
  NVWUDU = nvwu % 10 + nvwu / 10 % 10;
  NVWUJIU = nvwu / 10000 % 10 + nvwu / 100000 % 10;
  Sleep(3000);
  /*预言家部分*/
  YuYanJia();
  Sleep(2000);
}

/*猎人操作*/
void Lieren() {
  int lierendai = -1;
  cout << idxlieren + 1 << "号是猎人\n";

  players[idxlieren].is_light = 1;
  Sleep(1000);
  if (idxlieren == my_number) {
    cout << "你想带走几号？\n";
    cin >> lierendai;
    while (lierendai < 1 || lierendai > player_number || players[lierendai].die_or_life == die) {
      cout << "请重新输入！\n";
      cin >> lierendai;
    }
    lierendai--;
  } else {
    lierendai = rand() % player_number;
    while (players[lierendai].die_or_life == die) {
      lierendai = rand() % player_number;
    }
  }
  Sleep(2000);
  cout << "猎人选择带走" << lierendai + 1 << "号\n";
  Sleep(2000);
  players[lierendai].die_or_life = die;
}

void police_die();
/*判断谁死了*/
void panduansiwang() {
  system("cls");
  print();
  gotoxy(0, 7);
  cout << "________________________\n";
  Sleep(3000);
  color(white);
  cout << "天亮了\n";
  Sleep(2000);
  gotoxy(0, 9);
  cout << "昨晚";
  bool is_die[15] = {false}, is_die_lieren = false, flag = false;
  for (int i = 0; i < player_number; i++) {
    if (players[i].die_or_life == life) {
      if (i == LANGRENSHA || i == NVWUDU) {
        if (players[i].type == lieren) is_die_lieren = true;
        players[i].killer = (i == LANGRENSHA ? langren : nvwu);
        players[i].die_or_life = die;
        is_die[i] = true;
      }
      if (i == SHOUWEISHOU || i == NVWUJIU) {
        if (players[i].type == lieren) is_die_lieren = false;
        players[i].killer = -1;
        players[i].die_or_life = life;
        is_die[i] = false;
      }
    }
  }
  bool is_police_die = false;
  for (int i = 0; i < player_number; i++) {
    if (is_die[i]) {
      if (flag)
        cout << "和" << i + 1 << "号";
      else
        cout << i + 1 << "号", flag = true;
      if (i == idx_police)
        is_police_die = true;
    }
  }
  if (flag)
    cout << "死了\n";
  else
    cout << "是平安夜\n";

  if (is_die_lieren) Lieren();
  if (is_police_die) police_die();
}

/*选警长*/
void choose_police() {
  system("cls");
  print();
  color(blue);
  gotoxy(0, 7);
  cout << "________________________\n";
  color(yellow);
  cout << "下面开始选举警长，各位不能选举自己~\n";
  int tong[100] = {0}, cannot[100], must[100] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  memset(cannot, -1, sizeof(cannot));
CHOOSE:
  color(yellow);
  Sleep(1500);
  for (int i = 0; i < player_number; i++) {
    if (players[i].die_or_life == life && !is_include(cannot, i, player_number)) {
      if (i == my_number) {
        cout << "你要选举几号？\n";
        int n;
        cin >> n;
        while (n < 1 || n > player_number || n == i + 1 || players[n - 1].die_or_life == die || !is_include(must, n - 1, player_number)) {
          cout << "请重新输入!\n";
          cin >> n;
        }
        cout << i + 1 << "号选举" << n-- << "号\n";
        tong[n]++;
      } else {
        int n = rand() % player_number;
        while (n == i || players[n].die_or_life == die || !is_include(must, n, player_number))
          n = rand() % player_number;
        cout << i + 1 << "号选举" << n + 1 << "号\n";
        tong[n]++;
      }
      Sleep(1500);
    }
  }
  int idx_max = -1, maxn = -1, len = 0;
  for (int i = 0; i < player_number; i++)
    if (maxn < tong[i]) {
      maxn = tong[i];
      idx_max = i;
    }
  int maxn_arr[15] = {0};
  for (int i = 0; i < player_number; i++) {
    if (tong[i] == maxn) {
      maxn_arr[len++] = i;
    }
  }
  color(blue);
  if (len > 1) {
    for (int i = 0; i < len; i++) {
      if (i == len - 1) {
        cout << maxn_arr[i] + 1 << "号平票\n";
      } else {
        cout << maxn_arr[i] + 1 << "号,";
      }
    }
    for (int i = 0; i < len; i++)
      cannot[i] = maxn_arr[i];
    for (int i = 0; i < player_number; i++) {
      if (is_include(cannot, i, len))
        must[i] = i;
      else
        must[i] = -1;
    }
    color(white);
    goto CHOOSE;
  }
  cout << "恭喜" << idx_max + 1 << "号当选警长\n";
  Sleep(3000);
  idx_police = idx_max;
  return;
}

/*投票*/
int toupiao() {
  int tong[100] = {0}, cannot[100] = {}, must[100] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  memset(cannot, -1, sizeof(cannot));
  gotoxy(0, 7);
  color(blue);
  cout << "________________________\n";
  color(white);
  cout << "下面进入投票环节\n";
  memset(tong, 0, sizeof(tong));
  Sleep(2000);
TOUPIAO:
  for (int i = 0; i < player_number; i++) {
    if (players[i].die_or_life == life && !is_include(cannot, i, player_number)) {
      if (i == my_number) {
        color(white);
        cout << "你要投几号？\n";
        int n;
        cin >> n;
        while (!(n >= 1 && n <= player_number && is_include(must, n - 1, player_number))) {
          cout << "请重新输入！\n";
          cin >> n;
        }
        Sleep(2000);
        cout << setw(2) << my_number + 1 << "号投了" << setw(2) << n << "号";
        if (my_number == n - 1) color(red), cout << "快来看！这有个疯子投自己！";
        if (i == idx_police)
          color(yellow), cout << "(警长)\n";
        else
          cout << "\n";
        if (i == idx_police) tong[n - 1]++;
        tong[n - 1]++;
      } else {
        color(white);
        int t = -1;
        while (t == -1 || players[t].die_or_life == die || t == i || !is_include(must, t, player_number)) {
          if (i == idxyuyanjia && yuyanjiabixutoupiao != -1) {
            t = yuyanjiabixutoupiao;
            yuyanjiabixutoupiao = -1;
            continue;
          }
          t = rand() % player_number;
          if (is_include(idxlangren, i, nlangren)) {
            if (players[t].type == langren)
              t = -1;
          }
        }
        cout << setw(2) << i + 1 << "号"
             << "投了" << setw(2) << t + 1 << "号";
        if (i == idx_police)
          cout << "(警长2票)\n";
        else
          cout << "\n";
        if (i == idx_police) tong[t]++;
        tong[t]++;
      }

      Sleep(rand() % 1000 + 1000);
    }
  }
  int idx_max = -1, maxn = -1, len = 0;
  for (int i = 0; i < player_number; i++)
    if (maxn < tong[i]) {
      maxn = tong[i];
      idx_max = i;
    }
  int maxn_arr[15] = {0};
  for (int i = 0; i < player_number; i++) {
    if (tong[i] == maxn) {
      maxn_arr[len++] = i;
    }
  }
  color(blue);
  if (len > 1) {
    for (int i = 0; i < len; i++) {
      if (i == len - 1) {
        cout << maxn_arr[i] + 1 << "号平票\n";
      } else {
        cout << maxn_arr[i] + 1 << "号,";
      }
    }
    for (int i = 0; i < len; i++)
      cannot[i] = maxn_arr[i];
    for (int i = 0; i < player_number; i++) {
      if (is_include(cannot, i, len))
        must[i] = i;
      else
        must[i] = -1;
    }
    color(white);
    goto TOUPIAO;
  }

  cout << idx_max + 1 << "号"
       << "出局\n";
  Sleep(4000);
  players[idx_max].die_or_life = die;
  players[idx_max].killer = good;
  return idx_max;
}

/*警长死亡*/
void police_die() {
  color(yellow);
  int type;
  if (idx_police == my_number) {
    Sleep(1550);
    cout << "你是想撕毁警徽还是移交警徽？（撕毁输入1，移交输入2)";

    cin >> type;
    while (!(type == 1 || type == 2)) {
      cout << "请重新输入！\n";
      cin >> type;
    }
  } else {
    type = rand() % 3 + 1;
  }
  if (type == 1) {
    cout << "警长选择撕毁警徽\n";
    Sleep(1000);
    idx_police = -1;
  } else {
    int lucky = -1;
    while (lucky == -1 || players[lucky].die_or_life == die)
      lucky = rand() % player_number;
    cout << "警长选择把警徽移交给" << lucky + 1 << "号\n";
    Sleep(1500);
    idx_police = lucky;
  }
}

/*故事的最后*/
void the_end() {
  system("cls");
  switch (is_end()) {
    case 1:
      cout << "好人胜利\n\n";
      break;
    case 2:
      cout << "狼人胜利\n\n";
      break;
    case 3:
      cout << "本局平局\n\n";
      break;
  }
  for (int i = 0; i < player_number; i++) {
    cout << i + 1 << "号位:\t";
    switch (players[i].type) {
      case nvwu:
        cout << "女巫\t";
        break;
      case yuyanjia:
        cout << "预言家\t";
        break;
      case cunmin:
        cout << "村民\t";
        break;
      case langren:
        cout << "狼人\t";
        break;
      case lieren:
        cout << "猎人\t";
        break;
      case shouwei:
        cout << "守卫\t";
        break;
    }
    cout << "最终";
    switch (players[i].killer) {
      case nvwu:
        cout << "被女巫毒死\n";
        break;
      case langren:
        cout << "被狼人杀死\n";
        break;
      case good:
        cout << "被投票出局\n";
        break;
      case lieren:
        cout << "被猎人带走\n";
        break;
      default:
        cout << "存活\n";
    }
    cout << endl;
  }
}

/*主函数*/
int main() {
  int wheel = 0;
  before_game();
  while (!is_end()) {
    //黑夜准备
    something_before_everyday();
    Sleep(1500);

    //黑夜部分
    Night();           //进入黑夜！
    change_daytime();  //换天

    //天亮了
    panduansiwang();  //判断谁死了
    Sleep(2000);
    system("cls");
    print();
    if (is_end()) break;

    //选警长
    if (!wheel && player_number == 12) {
      choose_police();
      system("cls");
      print();
    }

    //投票环节
    int idx_max = toupiao();  //票数最多的人
    int lierendai = -1;
    if (idx_max == idx_police) {
      police_die();
    }
    if (players[idx_max].type == lieren) {  //启动猎人程序
      Lieren();
      if (is_end()) break;
    }
    system("cls");
    print();
    wheel++;
  }

  the_end();
  system("pause");
  return 0;
}