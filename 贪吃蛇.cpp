#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
using namespace std;
const int MAP_H =20;
const int MAP_W =20;
// 1 2 3 4 分别代表4个方向。
const int FX_UP = 1;
const int FX_DOWN = 2;
const int FX_LEFT = 3;
const int FX_RIGHT = 4;
const int FOOD = -1;
int iFangXiang = FX_RIGHT;
int iShuDu=150;
int iSnakeHeadx = 3;
int iSnakeHeady = 10;
int iSnakeZhi = 1;
int iSnakeWeiBax = iSnakeHeadx;
int iSnakeWeiBay = iSnakeHeady;
int iFoodX = 1;
int iFoodY = 1;
int iLength = 3;
int iSnakeSum = 0;
int iMap[MAP_H][MAP_W]={};
int iInput = 0;
int iInput1 = 0;
bool iGame_INIT = false;
bool iGameRun = true;
bool bHP = true ;
bool bSnakeJia = true;
/*1.10.0更新部分*/
bool ibegin = true ;
bool iNanDu = false ;
bool iOver = false ;
bool Over = false ;
bool iCaiDan = false ;
int nandu = 0 ;
void GameNanDuXuanZe() ;
void GameCaiDanDaYin() ;
void GameCaiDan()
{
for(;;)
{
Sleep(100);
if ( GetAsyncKeyState(' ') && ibegin == true )
{
goto begin ;
}
else if ( GetAsyncKeyState(' ') && iNanDu == true )
{
GameNanDuXuanZe() ;
continue ;
}
else if ( GetAsyncKeyState(' ') && iOver == true )
{
goto begin ;
}
else if ( GetAsyncKeyState('S') && ibegin == true )
{
ibegin = false ;
iNanDu = true ;
system("cls");
GameCaiDanDaYin() ;
continue ;
}
else if ( GetAsyncKeyState('S') &&iNanDu == true )
{
iNanDu = false ;
iOver = true ;
system("cls");
GameCaiDanDaYin() ; 
continue ;
}
else if ( GetAsyncKeyState('W') && iOver == true )
{
iOver = false ;
iNanDu = true ;
system("cls");
GameCaiDanDaYin() ; 
continue ;
}
else if ( GetAsyncKeyState('W') && iNanDu == true )
{
iNanDu = false ;
ibegin = true ;
system("cls");
GameCaiDanDaYin() ; 
continue ;
}
}
begin: ;
}
/*1.20.0更新部分*/ 
void GameCaiDanDaYin()
{
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<"Snack"<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
if ( ibegin == true )
{
cout<<" ------------"<<endl;
cout<<" # Start #"<<endl;
cout<<" ------------"<<endl;
}
else
{
cout<<endl;
cout<<" Start "<<endl;
cout<<endl;
}
if (iNanDu ==true)
{
cout<<" -----------------"<<endl;
cout<<" # choose :"; 
if ( nandu == 0 ) cout<<"easy";
else if ( nandu == 1 ) cout<<"normal";
else if ( nandu == 2 ) cout<<"hard"; 
cout<<"#"<<endl;
cout<<" -----------------"<<endl;
}
else
{
cout<<endl;
cout<<" choose :"; 
if ( nandu == 0 ) cout<<"easy";
else if ( nandu == 1 ) cout<<"normal";
else if ( nandu == 2 ) cout<<"hard";
cout<<endl;
cout<<endl;
}
if ( iOver == true )
{
cout<<" ------------"<<endl; 
cout<<" # exit #"<<endl;
cout<<" ------------"<<endl;
}
else
{
cout<<endl;
cout<<" exit"<<endl;
cout<<endl; 
}
//	GameCaiDan();
}
/*1.30.0*/
void GameNanDuXuanZe()
{
int one = 0 ;
system("cls");
goto DaYin;
ShuRu:
Sleep(100); 
if ( GetAsyncKeyState('S') && nandu == 1 )
{
nandu = 2 ;
one = 1 ; 
goto DaYin;
}
else if ( GetAsyncKeyState('S') && nandu == 0 )
{
nandu = 1 ;
one = 1 ; 
goto DaYin ;
}
else if ( GetAsyncKeyState('W') && nandu == 1 )
{
nandu = 0 ;
one = 1 ; 
goto DaYin ;
}
else if ( GetAsyncKeyState('W') && nandu == 2 )
{
nandu =1 ;
one = 1 ; 
goto DaYin ;
}
else if ( GetAsyncKeyState(' ') && one == 1 )
{
system("cls");
ibegin = true ;
iNanDu = false ;
goto Over;
}
else goto ShuRu; 
DaYin :
system("cls");
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<" choose"<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
if ( nandu == 0 )
{
cout<<" --------"<<endl;
cout<<" # easy #"<<endl;
cout<<" --------"<<endl;
}
else
{
cout<<endl;
cout<<" easy"<<endl;
cout<<endl;
}
if ( nandu == 1 )
{
cout<<" --------"<<endl;
cout<<" # normal #"<<endl;
cout<<" --------"<<endl;
}
else
{
cout<<endl;
cout<<" normal"<<endl;
cout<<endl;
}
if ( nandu == 2 )
{
cout<<" --------"<<endl;
cout<<" # hard #"<<endl;
cout<<" --------"<<endl;
}
else
{
cout<<endl;
cout<<" hard"<<endl;
cout<<endl;
}
goto ShuRu;
Over:;
}
//初始化数据。
void GameShuJu()
{
iFangXiang = FX_RIGHT;
iSnakeHeadx = 3;
iShuDu=150;
iSnakeHeady = 10;
iSnakeZhi = 1;
iSnakeWeiBax = iSnakeHeadx;
iSnakeWeiBay = iSnakeHeady;
iFoodX = 1;
iFoodY = 1;
iLength = 3;
iSnakeSum = 0;
iGame_INIT = false;
iInput = 0;
iInput1 = 0;
bHP = true ;
bSnakeJia = true;
iCaiDan = false ;
}
//不闪屏打印。
void BuShanPing ( int iX ,int iY )
{
COORD Pos = { iX,iY };
HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取标准输出设备句柄
SetConsoleCursorPosition(Handle, Pos);//设置光标位置
CONSOLE_CURSOR_INFO CurSor;
GetConsoleCursorInfo(Handle, &CurSor);//获取光标信息
CurSor.bVisible = false;//使光标不可见
SetConsoleCursorInfo(Handle, &CurSor);//设置光标信息
}
// 改变背景的颜色。
void YANSE( unsigned short a ,unsigned short b )
{
HANDLE Handle=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(Handle, a + b* 0x10 );
}
//初始化地图。
void GameChuShiHua()
{
if( iGame_INIT == false )
{
for( int i = 0 ; i < MAP_H ; ++i )
{
for( int j = 0 ; j < MAP_W ; ++j )iMap[i][j] = 0 ;
}
iGame_INIT =true;
}
if ( iGame_INIT == true )
{
for( int i = 0 ; i < MAP_H ;++i )
{
for( int j = 0 ; j < MAP_W ; ++j )
{
if( i == 0 || i == MAP_H -1 || j == 0 || j == MAP_W -1 )
{
YANSE( 0xf,3);
cout<<"■";
}
else if ( iMap[i][j] >=1 )
{
YANSE( 3,3);
cout<<"◎";
}
else if (iMap[i][j] == FOOD )
{
YANSE( 4,3);
cout<<"★";
}
else
{
YANSE( 3,3);
cout<<"　";
}
}
cout<<"\n";
}
}
}
//移动蛇。
void Move()
{
if (GetAsyncKeyState('A') && iFangXiang!=FX_RIGHT )
{
iFangXiang = FX_LEFT;
}
if (GetAsyncKeyState('D') && iFangXiang!=FX_LEFT)
{
iFangXiang = FX_RIGHT;
}
else if (GetAsyncKeyState('W') && iFangXiang!=FX_DOWN )
{
iFangXiang = FX_UP;
}
else if (GetAsyncKeyState('S') && iFangXiang!=FX_UP)
{
iFangXiang = FX_DOWN;
}
switch(iFangXiang)
{
case FX_LEFT:iSnakeHeadx--;break;
case FX_RIGHT:iSnakeHeadx++;break;
case FX_UP:iSnakeHeady--;break;
case FX_DOWN:iSnakeHeady++;break;
}
//蛇头走过的地方都是蛇身。 
if( iMap[iSnakeHeady][iSnakeHeadx] == 0 )
{
iMap[iSnakeHeady][iSnakeHeadx] = iSnakeZhi;
BuShanPing( iSnakeHeadx * 2 ,iSnakeHeady );
YANSE( 10 ,3 );
cout<<"*";
iSnakeZhi++;
}
else if(iMap[iSnakeHeady][iSnakeHeadx] == FOOD )
{
iMap[iSnakeHeady][iSnakeHeadx] = iSnakeZhi;
BuShanPing( iSnakeHeadx * 2 ,iSnakeHeady);
YANSE( 10 ,3 );
cout<<"*";
iLength++;
iSnakeZhi++;
bHP = true;
}
//数量达到上限以后，蛇就不在自己变长了。
if(iSnakeSum < iLength )
{
iSnakeSum++;
}
else 
{
//向上移动。
if(iMap[iSnakeWeiBay-1][iSnakeWeiBax] == iMap[iSnakeWeiBay][iSnakeWeiBax] + 1 )
{
iMap[iSnakeWeiBay][iSnakeWeiBax] = 0 ;
BuShanPing( iSnakeWeiBax * 2 ,iSnakeWeiBay );
YANSE( 3,3);
cout<<"　";
iSnakeWeiBay--;
}
//向左移动。 
else if(iMap[iSnakeWeiBay][iSnakeWeiBax-1] == iMap[iSnakeWeiBay][iSnakeWeiBax] + 1 )
{
iMap[iSnakeWeiBay][iSnakeWeiBax] = 0 ;
BuShanPing( iSnakeWeiBax * 2 ,iSnakeWeiBay);
YANSE( 3,3);
cout<<"　";
iSnakeWeiBax--;
}
//向下移动。
else if(iMap[iSnakeWeiBay+1][iSnakeWeiBax] == iMap[iSnakeWeiBay][iSnakeWeiBax] + 1 )
{
iMap[iSnakeWeiBay][iSnakeWeiBax] = 0 ;
BuShanPing( iSnakeWeiBax * 2 ,iSnakeWeiBay );
YANSE( 3,3);
cout<<"　";
iSnakeWeiBay++;
}
//向右移动
else if(iMap[iSnakeWeiBay][iSnakeWeiBax+1] == iMap[iSnakeWeiBay][iSnakeWeiBax] + 1 )
{
iMap[iSnakeWeiBay][iSnakeWeiBax] = 0 ;
BuShanPing( iSnakeWeiBax * 2 ,iSnakeWeiBay );
YANSE( 3,3);
cout<<"　";
iSnakeWeiBax++;
}
}
}
/*1.50.0更新部分*/ 
//判断死亡
void Dead()
{
if(iMap[iSnakeHeady][iSnakeHeadx]!= iSnakeZhi -1 || iSnakeHeadx == 0 || iSnakeHeadx == MAP_W - 1 ||iSnakeHeady == 0 || iSnakeHeady == MAP_H -1 )
{
ibegin = true ;
iCaiDan = false ;
iOver = false ;
for(;;)
{
DaYin:
Sleep(100);
YANSE( 15, 3);//7 15 
system("cls");
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<" game over"<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
if( ibegin == true )
{
cout<<" ------------"<<endl;
cout<<" # restart #"<<endl;
cout<<" ------------"<<endl;
}
else
{
cout<<endl;
cout<<" restart"<<endl;
cout<<endl; 
}
if ( iCaiDan == true )
{
cout<<" ------------"<<endl;
cout<<" # return #"<<endl;
cout<<" ------------"<<endl;
}
else
{
cout<<endl;
cout<<" return"<<endl;
cout<<endl; 
}
if ( iOver == true )
{
cout<<" ------------"<<endl;
cout<<" # exit #"<<endl;
cout<<" ------------"<<endl;
}
else
{
cout<<endl;
cout<<" exit"<<endl;
cout<<endl; 
}
if ( GetAsyncKeyState(' ') && ibegin == true )
{
system("cls");
iGame_INIT =false;
GameShuJu();
GameChuShiHua();
goto begin;
}
else if ( GetAsyncKeyState(' ') && iCaiDan == true )
{
ibegin = true ;
system("cls");
goto begin;
}
else if ( GetAsyncKeyState(' ') && iOver == true )
{
goto begin;
}
else if ( GetAsyncKeyState('S') && ibegin == true )
{
ibegin = false ;
iCaiDan = true ;
goto DaYin;
}
else if( GetAsyncKeyState('S') && iCaiDan == true )
{
iCaiDan = false ;
iOver = true ;
goto DaYin;
}
else if( GetAsyncKeyState('W') && iCaiDan == true )
{
iCaiDan = false ;
ibegin = true ;
goto DaYin;
}
else if( GetAsyncKeyState('W') && iOver == true )
{
iOver = false ;
iCaiDan = true ;
goto DaYin;
}
} 
}
begin:;
}
//判断随机果实。 
void Food()
{
if( bHP == true )
{
do
{
iFoodX = rand()% 18+1;
iFoodY = rand()% 18+1;
}while( iMap[iFoodY][iFoodX]!=0 );
iMap[iFoodY][iFoodX] = FOOD;
BuShanPing( iFoodX * 2 ,iFoodY );
YANSE( 4 ,3 );
cout<<"*";
bHP = false ;
}
}
/*1.40.0更新部分*/ 
void sleeptime()
{
Sleep( 150 - ( nandu * 50 ) );
}
//主函数。 
int main(void)
{
system("color 3f");
CaiDan: 
GameCaiDanDaYin();
GameCaiDan();
GameShuJu();
system("cls");
GameChuShiHua();
while(iGameRun && iOver == false )
{
Food();	
Move();
BuShanPing( 0 ,21 );
Dead();
sleeptime();
if ( iCaiDan == true ) goto CaiDan;
}
}