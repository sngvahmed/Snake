#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//////////Snake
int size = 3, speed = 100;
void boord_snake();
void sanke();
COORD apple();
void move(COORD snake[1500], COORD p);
void dirction(COORD snake[1500], char c);
void gameover(int score);
void start();
char manu();
char top_score();
int sped();

int main(int argc, char *argv[]) {
system("cls");
char op2 = 8, ch2;
bool t = true;
while (t = true) {
if (op2 = 8) {
size = 3;
ch2 = manu();
}
op2 = ' ';
if (ch2 == 'a') {
start();
} else if (ch2 == 'b') {
top_score();
} else if (ch2 == 'c') {
sped();
} else if (ch2 == 'd') {
return 8;
}
if (kbhit()) {
op2 = getch();
if (op2 == -32)
op2 = getch();
}
}


return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////Snake
int sped()///////// to choose the speed and level
{
COORD show;
char op, move;
system("cls");
show.X = 23;
show.Y = 10;
SetConsoleCursorPosition(hConsole, show);
cout << "Easy";
show.X = 23;
show.Y = 11;
SetConsoleCursorPosition(hConsole, show);
cout << "mediam";
show.X = 23;
show.Y = 12;
SetConsoleCursorPosition(hConsole, show);
cout << "hard";
int x;
if (speed == 100) {
x = 10;}
 else if (speed == 50) {
x = 11;}
 else if (speed == 30) {
x = 12;}
show.X = 20;
show.Y = x;
SetConsoleCursorPosition(hConsole, show);
cout << (char) 4;
SetConsoleCursorPosition(hConsole, show);
for (;;) {
if (kbhit()) {
move = getch();
if (move == -32)
move = getch();
}
if (move == 8) {
return 8;
} else if (move == 80) {
SetConsoleCursorPosition(hConsole, show);
cout << "  ";
if (show.Y == 12) {
show.X = 20;
show.Y = 10;
} else {
show.X = 20;
show.Y = show.Y + 1;
}
SetConsoleCursorPosition(hConsole, show);
cout << (char) 4;
} else if (move == 72) {
SetConsoleCursorPosition(hConsole, show);
cout << "  ";
if (show.Y == 10) {
show.X = 20;
show.Y = 12;
} else {
show.X = 20;
show.Y = show.Y - 1;
}
SetConsoleCursorPosition(hConsole, show);
cout << (char) 4;
} else if (show.Y == 10 && move == 13) {
speed = 100;
return 8;
} else if (show.Y == 11 && move == 13) {
speed = 50;
return 8;
} else if (show.Y == 12 && move == 13) {
speed = 30;
return 8;
}
move = ' ';
}
}
///////////////////////////////////////////////////////////////////////
char top_score()/////about in sanke menu
{
char op;
COORD show;
int c1 = 0, c2 = 0;
string player_name[5];
int player_score[5];
system("cls");

fstream myfile;
myfile.open("Snake top score.txt", ios::in);
for (int i = 1; i <= 10; i++) {
if (i % 2 == 1) {
myfile >> player_name[c1];
c1++;} 
else 
{myfile >> player_score[c2];
c2++;}
}
myfile.close();

show.X = 15;
show.Y = 7;
SetConsoleCursorPosition(hConsole, show);
cout << "Top Score";
show.Y = 8;
for (int i = 0; i < 5; i++) {
show.X = 23;
show.Y = show.Y + 1;
SetConsoleCursorPosition(hConsole, show);
cout << i + 1 << "  " << player_name[i] << " " << player_score[i]
<< endl;
}
for (;;) {
if (kbhit()) {
op = getch();
if (op == -32)
op = getch();
}
if (op == 8) {
return 8;
}
}
Sleep(1000);
}
/////////////////////////////////////////////////////////////////////
char manu() {
COORD show;
char move, op;
bool t = true;

system("cls");
show.X = 30;
show.Y = 13;
SetConsoleCursorPosition(hConsole, show);
cout << "WelCome";
show.X = 30;
show.Y = 14;
SetConsoleCursorPosition(hConsole, show);
cout << "Start Game";
show.X = 30;
show.Y = 15;
SetConsoleCursorPosition(hConsole, show);
cout << "Top Score";
show.X = 30;
show.Y = 16;
SetConsoleCursorPosition(hConsole, show);
cout << "Speed";
show.X = 30;
show.Y = 17;
SetConsoleCursorPosition(hConsole, show);
cout << "Exit";
show.X = 27;
show.Y = 14;
SetConsoleCursorPosition(hConsole, show);
cout << (char) 4;

while (t = true) {

if (kbhit()) {
move = getch();
if (move == -32)
move = getch();
}
if (move == 80) {
SetConsoleCursorPosition(hConsole, show);
cout << "  ";
if (show.Y == 17) {
show.X = 27;
show.Y = 14;
} else {
show.X = 27;
show.Y = show.Y + 1;
}
SetConsoleCursorPosition(hConsole, show);
cout << (char) 4;
} else if (move == 72) {
SetConsoleCursorPosition(hConsole, show);
cout << "  ";
if (show.Y == 14) {
show.X = 27;
show.Y = 17;
} else {
show.X = 27;
show.Y = show.Y - 1;
}
SetConsoleCursorPosition(hConsole, show);
cout << (char) 4;
} 
else if (show.Y == 14 && move == 13) {
return 'a';
} else if (show.Y == 15 && move == 13) {
return 'b';
} else if (show.Y == 16 && move == 13) {
return 'c';
} else if ((show.Y == 17 && move == 13) || (move == 8)) {
return 'd';
}
move = ' ';
}
}

/////////////////////////////////////////////////////////////
void start() {
system("cls");
COORD snake[1500], p;
srand ( time(NULL));
int x = rand() % 30 + 20;
int y = rand() % 19 + 1;
for (int i = 0; i < size; i++) {
snake[i].X = x--;
snake[i].Y = y;
SetConsoleCursorPosition(hConsole, snake[i]);
cout << "*";
}
boord_snake();
p = apple();
move(snake, p);
}
/////////////////////////////
void boord_snake() {
COORD point;
for (int i = 0; i <= 70; i++) {
SetConsoleCursorPosition(hConsole, point);
point.X = i;
point.Y = 0;
cout << (char) 178;
SetConsoleCursorPosition(hConsole, point);
point.X = i;
point.Y = 20;
cout << (char) 178;
}
for (int i = 0; i <= 20; i++) {
SetConsoleCursorPosition(hConsole, point);
point.X = 0;
point.Y = i;
cout << (char) 178;
SetConsoleCursorPosition(hConsole, point);
point.X = 70;
point.Y = i;
cout << (char) 178;
}
}
//////////////////////////////////////////////////////
COORD apple() {
COORD p;
srand ( time(NULL));
p.X = rand() % 69 + 1;
p.Y = rand() % 19 + 1;
SetConsoleCursorPosition(hConsole, p);
cout << (char) 3 << "\a";
return p;
}
////////////////////////////////////////////////////////
void move(COORD snake[1500], COORD p) {
char c = 'd', op;
COORD bor, s;
bool t;
int score = 0;
while (t = true) {
if (kbhit()) {
c = getch();
if (c == -32)
c = getch();
}
if (c == 'r')
{c = op;}

if (c !='p')/////////////// to not go revers direction
{
if ((c == 77 || c == 'd' || c == 'D') && (op == 75 || op == 'a'|| op == 'A')) {
c = 75;
}
 else if ((c == 75 || c == 'A' || c == 'a') && (op == 77 || op== 'd' || op == 'D')) {
c = 77;
} else if ((c == 80 || c == 's' || c == 'S') && (op == 72 || op== 'w' || op == 'W')) {
c = 72;} 
else if ((op == 80 || op == 's' || op == 'S') && (c == 72 || c== 'w' || c == 'W')) {
c = 80;
}
op = c;
Sleep(speed);
dirction(snake, c);
s.X = 5;
s.Y = 21;
SetConsoleCursorPosition(hConsole, s);
cout << "your score: " << score;

s.X = 25;
s.Y = 21;
SetConsoleCursorPosition(hConsole, s);
cout << "pause press p , resume press r" << endl;

////// if the apple print on his body
for (int i = 1; i <= size; i++)
{
if (snake[i].X == p.X && snake[i].Y == p.Y) 
{p = apple();}
}

for (int y = 1; y <= size; y++)///// to check if he eat himself
{
if (snake[0].X == snake[y].X && snake[0].Y == snake[y].Y) 
{gameover(score);
return;}
}

///////to check if he eat the apple
if (snake[0].X == p.X && snake[0].Y == p.Y) 
{p = apple();
size++;
score += 5;}


// to check if he hit the border
for (int i = 0; i <= 70; i++) {
if (((snake[0].X == i) && (snake[0].Y == 0)) || ((snake[0].X== i) && (snake[0].Y == 20))) {
gameover(score);
return;
}

}
for (int i = 0; i <= 20; i++) {
if (((snake[0].X == 0) && (snake[0].Y == i)) || ((snake[0].X== 70) && (snake[0].Y == i))) {
gameover(score);
return;
}
}
}
}
}
///////////////////////////////////////////////////////////
void dirction(COORD snake[1500], char c)///to make the sanke move
{
for (int i = size; i > 0; i--)
{snake[i] = snake[i - 1];
SetConsoleCursorPosition(hConsole, snake[i]);
cout << "*";}

if (c == 72 || c == 'w' || c == 'W') {
if (speed == 100 && snake[0].Y == 1)////to make him go through the border
{
Sleep(50);
snake[0].X = snake[0].X;
snake[0].Y = 19;
} else {
snake[0].Y = snake[0].Y-1;
}
} else if (c == 80 || c == 's' || c == 'S') {
if (speed == 100 && snake[0].Y == 19)////to make him go through the border
{
Sleep(50);
snake[0].X = snake[0].X;
snake[0].Y = 1;
} else {
snake[0].Y = snake[0].Y + 1;
}
} else if (c == 77 || c == 'd' || c == 'D') {
if (speed == 100 && snake[0].X == 69)////to make him go through the border
{
Sleep(50);
snake[0].X = 1;  
snake[0].Y = snake[0].Y;
} else {
snake[0].X = snake[0].X + 1;
}

} else if (c == 75 || c == 'A' || c == 'a') {
if (speed == 100 && snake[0].X == 1)////to make him go through the border
{
Sleep(50);
snake[0].X = 69;
snake[0].Y = snake[0].Y;
} else {
snake[0].X = snake[0].X - 1;
}
}
SetConsoleCursorPosition(hConsole, snake[0]);
cout << "*";
SetConsoleCursorPosition(hConsole, snake[size]);
cout << " ";
}

////////////////////////////////////////////
void gameover(int score)//// to design gameover in sanke
{
string player_name;
system("cls");
COORD show;
show.X = 30;
show.Y = 10;
SetConsoleCursorPosition(hConsole, show);
cout << "GameOver";
show.X = 30;
show.Y = 12;
SetConsoleCursorPosition(hConsole, show);
cout << "your score " << score;
show.X = 30;
show.Y = 15;
SetConsoleCursorPosition(hConsole, show);
cout << "enter you name";
show.X = 30;
show.Y = 17;
SetConsoleCursorPosition(hConsole, show);
cin >> player_name;

int player_score[5];
int c2 = 0, c1 = 0;
string player_name2[5];
fstream myfile;
myfile.open("Snake top score.txt", ios::in);
for (int i = 1; i <= 10; i++) {
if (i % 2 == 1) {
myfile >> player_name2[c1];
c1++;
} else {
myfile >> player_score[c2];
c2++;
}
}
myfile.close();
string last_n, nnn;
int last_s, sss;
///// to check the frist score
for (int i = 0; i < 5; i++) {
if (player_score[i] < score) {
last_s = player_score[i];
last_n = player_name2[i];
player_score[i] = score;
player_name2[i] = player_name;
for (int y = i + 1; y <= 4; y++) {
sss = player_score[y];
player_score[y] = last_s;
last_s = sss;
nnn = player_name2[y];
player_name2[y] = last_n;
last_n = nnn;
}
break;
}
}

fstream my;
my.open("Snake top score.txt", ios::out);
for (int i = 0; i < 5; i++) {
my << player_name2[i] << " " << player_score[i] << endl;
}
my.close();
}
