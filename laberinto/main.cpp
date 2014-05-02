#include <curses.h>
#include <iostream>
#include <stdlib.h>

int x=8, y=22;
int xq =30, yq=15;
int punto=0;
int tecla;
int segundos=0, minutos=0;

void laberinto(){
    for(int i=7; i<47;i++){
        move(2,i); printw("%c",205);
        move(23,i); printw("%c",205);
    }
    for(int i=3; i<23;i++){
        move(i,6); printw("%c",186);
        move(i,47); printw("%c",186);
    }

        for(int i=6; i<23;i++){
        move(i,11); printw("%c",186); //1
    }
        for(int i=6; i<21;i++){
        move(i,15); printw("%c",186); //2
    }
        for(int i=9; i<21;i++){
        move(i,19); printw("%c",186); //3
    }
        for(int i=2; i<7;i++){
        move(i,23); printw("%c",186); //4
    }
        for(int i=9; i<23;i++){
        move(i,23); printw("%c",186);//4
    }
        for(int i=12; i<18;i++){
        move(i,27); printw("%c",186);//5
    }
        for(int i=20; i<23;i++){
        move(i,27); printw("%c",186);//5
    }
        for(int i=9; i<18;i++){
        move(i,31); printw("%c",186);//6
    }
        for(int i=3; i<18;i++){
        move(i,35); printw("%c",186);//7
    }
        for(int i=7; i<18;i++){
        move(i,39); printw("%c",186);//8
    }
        for(int i=10; i<20;i++){
        move(i,43); printw("%c",186);//9
    }
        for(int i=15; i<32;i++){
        move(6,i); printw("%c",205);//1
    }
        for(int i=39; i<43;i++){
        move(6,i); printw("%c",205);//1
    }
        for(int i=19; i<32;i++){
        move(9,i); printw("%c",205);//2
    }
        for(int i=28; i<32;i++){
        move(17,i); printw("%c",205);//3
    }
        for(int i=36; i<40;i++){
        move(17,i); printw("%c",205);//3
    }
        for(int i=27; i<44;i++){
        move(20,i); printw("%c",205);//4
    }
    move(2,6); printw("%c",201);
    move(23,6); printw("%c",200);
    move(2,47); printw("%c",187);
    move(23,47); printw("%c",188);
    move(6,23); printw("%c",202);
    move(2,23); printw("%c",203);
    move(2,35); printw("%c",203);
    move(6,39); printw("%c",201);
    move(23,11); printw("%c",202);
    move(6,15); printw("%c",201);
    move(9,19); printw("%c",201);
    move(9,23); printw("%c",203);
    move(9,31); printw("%c",187);
    move(17,27); printw("%c",200);
    move(17,31); printw("%c",188);
    move(17,35); printw("%c",200);
    move(17,39); printw("%c",188);
    move(20,27); printw("%c",201);
    move(20,43); printw("%c",188);
    move(23,27); printw("%c",202);
    move(23,23); printw("%c",202);
}
void queso(){
    if(x==xq && y==yq){
        punto++;
        xq =(rand()%35)+8;
        yq =(rand()%20)+3;
        move(yq,xq); printw("%c",178);
    }
}
void puntos(){
    move(10,60); printw("Puntos: %d",punto);
}
void tiempo(){

  if(segundos>=60){
    segundos=0;
    minutos++;
   }
    move(11,60); printw("Tiempo: %d:%d", minutos,segundos);
//    timeout(1000);
  //  segundos++;

}
bool fin_juego(){
 if(minutos==1 && segundos==30) {
    return false;
 }
 else if (punto==15)
    return false;
 else{
 return true;
 }
}

int main(){
    initscr();
    curs_set(0);
    keypad(stdscr, 1);
    noecho();

    while (fin_juego()){
    laberinto();
    move(5,58); printw("   Encuentra");
    move(6,58); printw("    los 15");
    move(7,58); printw("quesos en 1:30.");
    move(yq,xq); printw("%c",178);
    move(11,60); printw("Tiempo: %d:%d", minutos,segundos);
    tiempo();
    queso();
    puntos();
    mvprintw(y, x, "&");
    tecla = getch();
        if (tecla == KEY_DOWN) { y++; clear(); }
        if (tecla == KEY_UP)   { y--; clear(); }
        if (tecla == KEY_LEFT) { x--; clear(); }
        if (tecla == KEY_RIGHT){ x++; clear(); }
     /*   if (y==2)  y++; clear();
        if (y==23) y--; clear();
        if (x==6)  x++; clear();
        if (x==47) x--; clear();
        if (y>5 && y<23 && x==11)  x--; clear();
        if (y>11 && y<18 && x==27)  x--; clear();
        if (y>5 && y<21 && x==15)  x--; clear();
        if (y>8 && y<21 && x==19)  x--; clear();
        if (y>1 && y<7 && x==23)  x--; clear();
        if (y>11 && y<18 && x==13)  x--; clear();
        if (y>9 && y<23 && x==23)  x--; clear();
        if (y>11 && y<18 && x==27)  x--; clear();
        if (y>19 && y<23 && x==27)  x--; clear();
        if (y>8 && y<18 && x==31)  x--; clear();
        if (y>2 && y<18 && x==35)  x--; clear();
        if (y>6 && y<18 && x==39)  x--; clear();
        if (y>9 && y<20 && x==43)  x--; clear();//
        if (x>14 && x<32 && y==6)  y--; clear();
        if (x>38 && x<43 && y==6)  y--; clear();
        if (x>18 && x<32 && y==9)  y--; clear();
        if (x>27 && x<32 && y==17)  y--; clear();
        if (x>35 && x<40 && y==17)  y--; clear();
        if (x>26 && x<44 && y==20)  y--; clear();*/
    }
    endwin();
}
