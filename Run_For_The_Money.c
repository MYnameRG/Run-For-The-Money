#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#define ROWS 16
#define COLS 80

char a[ROWS][COLS];
char ch;
static int x_pos;
static int y_pos;
static int score;

void boundry();
void fast_output();
void delay(int);
void slow_output();
void initializer();
void controller(char);
void move_right();
void move_up();
void move_left();
void move_down();
void put_block();
void fruit_apply();
void title_logo();
void score_board();

void title_logo()
{
printf("********************************************************************************\n");
printf("                         ******Run For The Money*****                           \n");
printf("                     ******Developed By : Rohit Gupta*****                      \n");
printf("********************************************************************************\n");
}

void score_board()
{
printf("********************************************************************************\n");
printf("                                   SCORE: $%d                         \n",score);
printf("********************************************************************************\n");
}

void boundry()
{
for(int i=0;i<COLS;i++) //Create upper border
{
a[0][i]='#';
}
for(int i=0;i<ROWS;i++) //Create left border 
{
a[i][0]='#';
}
for(int i=COLS;i>=0;i--) //Create down border
{
a[ROWS-1][i]='#';
}
for(int i=0;i<ROWS;i++) //Create right border
{
a[i][COLS-1]='#';
}
slow_output();
}

void fast_output()
{
clrscr();
title_logo();
score_board();
for(int i=0;i<ROWS;i++)
{
for(int j=0;j<COLS;j++)
{
printf("%c",a[i][j]);
}
printf("\n");
}
}

void initializer()
{
for(int i=0;i<ROWS;i++)
{
for(int j=0;j<COLS;j++)
{
a[i][j]=' ';
}
}
}

void delay(int sec)
{
int ms=1000*sec;
clock_t nt=clock();
while(clock() < nt+ms);
}

void slow_output()
{
title_logo();
score_board();
for(int i=0;i<ROWS;i++)
{
for(int j=0;j<COLS;j++)
{
delay(1);
printf("%c",a[i][j]);
}
printf("\n");
}
}

int main()
{
clrscr();
initializer();
boundry();
put_block();
fruit_apply();
}

/*void controller(char ch)
{
switch(ch)
{
case 'w':
//move_up();
break;

case 'a':
break;

case 's':
break;

case 'd':
break;
}*/

void put_block()
{
clrscr();
x_pos=rand()%10;
y_pos=rand()%10;
if((x_pos<80)&&(y_pos<20)){
a[x_pos][y_pos]='*';}
fast_output();
}

void move_right()
{
clrscr();
if(a[x_pos+1][y_pos+1]!='#')
{
a[x_pos][y_pos]='*';
fast_output();
a[x_pos][y_pos]=' ';
y_pos++;
}
else
{
a[x_pos][y_pos]='*';
fast_output();
a[x_pos][y_pos]=' ';
}
}

void move_up()
{
clrscr();
if(a[x_pos-1][y_pos-1]!='#')
{
a[x_pos][y_pos]='*';
fast_output();
a[x_pos][y_pos]=' ';
x_pos--;
}
else
{
a[x_pos][y_pos]='*';
fast_output();
a[x_pos][y_pos]=' ';
}
}

void move_down()
{
clrscr();
if(a[x_pos+1][y_pos+1]!='#')
{
a[x_pos][y_pos]='*';
fast_output();
a[x_pos][y_pos]=' ';
x_pos++;
}
else
{
a[x_pos][y_pos]='*';
fast_output();
a[x_pos][y_pos]=' ';
}
}

void move_left()
{
clrscr();
if(a[x_pos-1][y_pos-1]!='#')
{
a[x_pos][y_pos]='*';
fast_output();
a[x_pos][y_pos]=' ';
y_pos--;
}
else
{
a[x_pos][y_pos]='*';
fast_output();
a[x_pos][y_pos]=' ';
}
}

void fruit_apply()
{
static int x_pos1=0;
static int y_pos1=0;
label:
while(1)
{
if(x_pos1>10 || y_pos1<10){
x_pos1=rand()%10;
y_pos1=rand()%100;
}
else if(x_pos1>10 || y_pos1>10){
x_pos1=rand()%10;
y_pos1=rand()%10;
}
else if(x_pos1<10 || y_pos1>10){
x_pos1=rand()%100;
y_pos1=rand()%10;
}
else if(x_pos1<10 || y_pos1<10){
x_pos1=rand()%100;
y_pos1=rand()%100;
}
if(x_pos1<80 || y_pos1<20)
{
a[x_pos1+3][y_pos1+3]='$';
fast_output();
}
else
{
goto label;
}
while(1)
{
if(getch()=='w')
move_up();
else if(getch()=='a')
move_left();
else if(getch()=='s')
move_down();
else if(getch()=='d')
move_right();
if(a[x_pos1+3][y_pos1+3]==a[x_pos][y_pos])
{
score=score+5;
a[x_pos1+3][y_pos1+3]=' ';
fast_output();
break;
}
}
}
}
