#include<graphics.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int d = 1, dir =1, x = 200 ,y = 200,speed = 200, fruitX, fruitY, score, gameOver;
int tailX[100], tailY[100];
int nTail;

void Setup(){
        gameOver==false;
        fruitX = (rand() % 43+1)*10;
        fruitY = (rand() % 43+1)*10;
        score=0;
        nTail=1;
        tailX[0]=x;
        tailY[0]=y;

}

void Draw(){

}
void Move(){
    for(int i=nTail;i>0;i--){
        tailX[i]=tailX[i-1];
        tailY[i]=tailY[i-1];
    }
    tailX[0] = x;
    tailY[0] = y;
}

void RelocateFruit(){
        fruitX = (rand() % 43+1)*10;
        fruitY = (rand() % 43+1)*10;
        score+=10;
    }
void Input(){
 if(GetAsyncKeyState(VK_RIGHT)){d=1;}
        else if(GetAsyncKeyState(VK_LEFT)){d=2;}
        else if(GetAsyncKeyState(VK_UP)){d=3;}
        else if(GetAsyncKeyState(VK_DOWN)){d=4;}
        else{d=0;}

        switch(d){

        case 0:
            if(dir==1)
                if(x>430)
                    x=10;
                else
                    x=x+10;
            else if (dir==2)
                if(x<10)
                    x=430;
                else
                    x=x-10;
            else if (dir ==3)
                if(y<10)
                    y=430;
                else
                    y=y-10;
            else if (dir ==4)
                if(y>430)
                    y=10;
                else
                    y=y+10;
            else
                d=0;

        break;
        case 1:
            x=x+10;

            dir=1;
        break;
        case 2:
            x=x-10;
            dir=2;

        break;
        case 3:
            y=y-10;
            dir=3;
        break;
        case 4:
            y=y+10;
            dir=4;
        break;
        }
}

int main(){
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    delay(2000);

    srand(time(NULL));
    setfillstyle(1,2);
    Setup();

    while(gameOver!=true){
        Move();
        Draw();

        setfillstyle(1,0);
        bar(0,0,500,500);
        setfillstyle(1,2);
        bar(0,0,450,10);
        bar(0,0,10,450);
        bar(0,440,450,450);//DOWN
        bar(440,10,450,450);//RIGHT

        char intAsString [10] ;
        itoa (score,intAsString,10);



        outtextxy(450,0, "score:");
        outtextxy(450,20, intAsString);

        Input();

        for(int i =0;i<nTail;i++){
          bar(tailX[i],tailY[i],tailX[i]+10,tailY[i]+10);
        }


        if(fruitX==x && fruitY==y){
            RelocateFruit();
            nTail++;
            speed=speed-5;
        }

        for(int i =1;i<nTail;i++){
            if(x==tailX[i] && y==tailY[i])
                gameOver=true;
        }

        setfillstyle(1,4);
        bar(fruitX,fruitY,fruitX+10,fruitY+10);
        delay(speed);

    }

}

