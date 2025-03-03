#include <iostream>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>`
#include<dos.h>
#include<time.h>
#include<windows.h>
void enemycar(int x,int y,int color) 
{
	setcolor(color);
		line(x,y,x+24,y);
		line(x,y,x,y+37);
		line(x+24,y,x+24,y+37);
		line(x,y+37,x+11,y+60);
		line(x+24,y+37,x+13,y+60);
		line(x+11,y+60,x+13,y+60);
		//clor for body of car
		setfillstyle(SOLID_FILL,color);
		floodfill(x+20,y+32,color);
		//car wheels
		setcolor(BLACK);
		rectangle(x,y,x-9,y+10);
		rectangle(x+24,y,x+33,y+10);
		rectangle(x,y+34,x-9,y+24);
		rectangle(x+24,y+34,x+33,y+24);
		//color for wheels
		setfillstyle(SOLID_FILL,BLACK);
		floodfill(x-6,y+5,BLACK);
		floodfill(x-6,y+30,BLACK);
		floodfill(x+29,y+5,BLACK);
		floodfill(x+29,y+30,BLACK);
}
class cargame
{
		int page=0,t_y=-300,x=250,y=600,m=0,x1=250,x2=340,x3=430,x4=520,y1=-100,y2=-280,y3=-460,y4=-640,n=0,level=0,a=0,score=0;
		const char*sco="score=";
		const char*lev="level=";
		char mylevel[20];
		char myscore[20];
		public:
		void mycar();
		int game();
};
void cargame::mycar()
{
	setcolor(RED);
	line(x,y,x+24,y);
	line(x,y,x,y-37);
	line(x+24,y,x+24,y-37);
	line(x,y-37,x+11,y-60);
	line(x+24,y-37,x+13,y-60);
	line(x+11,y-60,x+13,y-60);
	//clor for body of car
	setfillstyle(SOLID_FILL,RED);
	floodfill(x+20,y-32,RED);
	//car wheels
	setcolor(BLACK);
	rectangle(x,y,x-9,y-10);
	rectangle(x+24,y,x+33,y-10);
	rectangle(x,y-34,x-9,y-24);
	rectangle(x+24,y-34,x+33,y-24);
	//color for wheels
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(x-6,y-5,BLACK);
	floodfill(x-6,y-30,BLACK);
	floodfill(x+29,y-5,BLACK);
	floodfill(x+29,y-30,BLACK);	
}
int cargame::game()
{
	while(1)
	{
		setactivepage(page);
		setvisualpage(1-page);
		cleardevice();
		setcolor(CYAN);
		rectangle(0,0,1600,1000);
		setfillstyle(1,CYAN);
		floodfill(1,1,CYAN);
		setcolor(WHITE);
		rectangle(240,-1,554,710);
		rectangle(225,-1,240,710);
		rectangle(554,-1,569,710);
		setfillstyle(1,8);
		floodfill(241,0,WHITE);
		setfillstyle(1,WHITE);
		floodfill(230,0,WHITE);
		floodfill(566,0,WHITE);
		setcolor(YELLOW);
		sprintf(myscore,"%s%d",sco,score);
		sprintf(mylevel,"%s%d",lev,level);
		settextstyle(8,0,2);
		outtextxy(50,100,myscore);
		outtextxy(600,160,mylevel);
		for(int i=0;i<450;i+=105)
		{
			rectangle(390,10+i+t_y,410,70+i+t_y);
			setfillstyle(1,YELLOW);
			floodfill(391,11+i+t_y,YELLOW);
		}
		t_y+=15;
		if(t_y>650)
			t_y=-300;
		mycar();
		if(level<5&&a==0)
		{
			enemycar(x1,y1,MAGENTA);
			enemycar(x2,y2,GREEN);
			enemycar(x3,y3,BLUE);
			enemycar(x4,y4,BROWN);
			y1+=18;
			y2+=18;
			y3+=18;
			y4+=18;
			if(y1>710)
			{
					x1=250+(rand()%14)*20;
					y1=y4-180;
					score++;
			}		
			if(y2>710)
			{
				x2=250+(rand()%14)*20;
				y2=y1-180;
				score++;
			}
			if(y3>710)
			{
				x3=250+(rand()%14)*20;
				y3=y2-180;
				score++;
			}
			if(y4>710)
			{
				x4=250+(rand()%14)*20;
		    	n++;
				y4=y3-180;
				score++;
			}
		}
		if(n==7)
			level=1;
		if(n==14)
			level=2;
		if(n==21)
			level=3;
		if(n==28)
			level=4;
		if(n>=35)
			level=5;
		if(level<5&&a==0)		
		{
			if(kbhit())
			{
				char ch=getch();
				if(ch==75&&x>250)
					x=x-30;
				else if(ch==77&&x<520)
					x=x+30;
				else if(ch==120)
					return(0);		
			}
		}
		if(level==5)
		{
			setcolor(RED);
			settextstyle(8,0,5);
			outtextxy(300,200,"you won");
			settextstyle(8,0,3);
			setcolor(GREEN);
			outtextxy(40,300,"press y to continue");
			outtextxy(40,350,"press x to exit");		
			delay(20);
			if(kbhit())
			{
				char ch=getch();
				if(ch==121)
					return 1;				
				if(ch==120)
					return 0;
			}
		}
		if((a==1)||(((y-y1>0&&y-y1<66)&&((x-x1<42&&x>=x1)||(x1-x<42&&x1>=x)))||(((x-x2<42&&x>=x2)||(x2-x<42&&x2>=x))&&(y-y2>0&&y-y2<66))||(((x-x3<42&&x>=x3)||(x3-x<42&&x3>=x))&&(y-y3>0&&y-y3<66))||(((x-x4<42&&x>=x4)||(x4-x<42&&x4>=x))&&(y-y4>0&&y-y4<66))))
		{
			setcolor(RED);
			settextstyle(8,0,5);
			outtextxy(300,200,"you lose");
			setcolor(GREEN);
			settextstyle(8,0,3);
			outtextxy(40,300,"press y to continue");
			outtextxy(40,350,"press x to exit");	
			level=1;
			a=1;
			delay(60);
			if(kbhit())
			{
				char ch=getch();
				if(ch==121)
					return 1;				
				if(ch==120)
					return 0;
			}
		}
		page=1-page;
		delay(18-level);
	
	}
	getch();
}
int main()
{
	initwindow(1600,710);
	srand(time(NULL));
	
	int score=0;
	int i=0;
	char name[20];
	char ch;
	const char*sco="score=";
	rectangle(100,70,1300,680);
	setcolor(WHITE);
	rectangle(380,280,1140,400);
	setcolor(YELLOW);
	settextstyle(6,0,8);
	outtextxy(400,300,"PROJECT -X- ");
	getch();
	cleardevice();
	setcolor(WHITE);
	rectangle(100,280,650,680);
	rectangle(680,280,1250,680);
	settextstyle(6,0,7);
	setcolor(YELLOW);
	outtextxy(400,150,"select the game");
	setcolor(RED);
	settextstyle(6,0,5);
	outtextxy(150,450,"1.RACING CAR");
	outtextxy(730,450,"2.BRAIN MASTER");
	
	ch=getch();
	cleardevice();
	switch(ch)
	{
		case 50:
		{
			setbkcolor(BLACK);
			setcolor(BLACK);
			settextstyle(3,0,7);
			rectangle(100,100,1300,650);
			rectangle(430,280,930,390);
			setcolor(WHITE);
			outtextxy(450,300,"BRA!N MASTER");
			setcolor(LIGHTGREEN);
			settextstyle(3,0,1);
	    	outtextxy(570,480,"Starting BrainMaster P.C....");
			for(int k=0;k<200;k++)
			{	setcolor(WHITE);
				rectangle(570,510,770,530);
				setcolor(YELLOW);
				line(570+k,510,570+k,530);
				delay(40);
			}	
			setcolor(YELLOW);
			settextstyle(3,0,3);
			outtextxy(700,600,"press any key to continue...");
			getch();
			cleardevice();
			setcolor(WHITE);
			setcolor(CYAN);
			settextstyle(3,0,6);
			outtextxy(500,300,"Quiz Starts Now...");
			getch();
			cleardevice();
		 	settextstyle(8,0,2);
		 	setcolor(YELLOW);
			char myscore[30];
		 	sprintf(myscore,"%s%d",sco,score);
		 	outtextxy(50,100,myscore);
		 	settextstyle(8,0,5);
		 	outtextxy(200,200,"Q1:C.E.O of Microsoft ?");
		 	settextstyle(1,0,2);
		 	setcolor(WHITE);
		 	outtextxy(300,400,"a.steven job");
		 	outtextxy(670,400,"b.nadenla sunder");
		 	outtextxy(300,500,"c.satya nadenla" );
		 	outtextxy(670,500,"d.sunder pichai");
		 	settextstyle(1,0,3);
		 	setcolor(CYAN);
		 	outtextxy(200,600,"Enter your choice:");
	       ch=getch();
		   setcolor(WHITE);
			if(ch=='c')
			{
				cleardevice();
				settextstyle(6,0,5);
				outtextxy(220,200,"Right Answer..!");
				score=score+10;
		 	}
			else
			{
				cleardevice();
				settextstyle(3,0,5);
				outtextxy(470,300,"WRONG");
				getch();
				cleardevice();
				sprintf(myscore,"TOTAL SCORE:%d",score);
				outtextxy(200,200,myscore);
				getch();
				cleardevice();
				outtextxy(500,300,"GAME OVER");
				delay(1000);
				exit(0);
			}
			getch();
			//second questions
		 	cleardevice();
		 	settextstyle(8,0,2);
		 	sprintf(myscore,"%s%d",sco,score);
		 	outtextxy(50,100,myscore);
		 	setcolor(CYAN);
			settextstyle(8,0,5);
	    	outtextxy(200,200,"Q2:Odd one out.");
			settextstyle(1,0,2);
		 	setcolor(WHITE);
		 	outtextxy(300,400,"a.Sleep");
		 	outtextxy(670,400,"b.Debug");
		 	outtextxy(300,500,"c.Build" );
		 	outtextxy(670,500,"d.Run");
		 	settextstyle(1,0,3);
		 	setcolor(CYAN);
		 	outtextxy(200,600,"Enter your choice:");
			 setcolor(YELLOW);
			ch=getch();
			if(ch=='a')
			{
				cleardevice();
				settextstyle(3,0,7);
				outtextxy(230,200,"Right Answer...!");
				score=score+20;
				getch();
			}
			else
			{
				cleardevice();	
				settextstyle(3,0,5);
				outtextxy(470,300,"WRONG");
				getch();
				cleardevice();
				sprintf(myscore,"TOTAL SCORE:%d",score);
				outtextxy(200,200,myscore);
				getch();
				cleardevice();
				outtextxy(500,300,"GAME OVER");
				delay(1000);
				exit(0);
			}
			cleardevice();
			//third question
			settextstyle(8,0,2);
		 	sprintf(myscore,"%s%d",sco,score);
		 	outtextxy(50,100,myscore);
		 	settextstyle(8,0,5);
		 	setcolor(YELLOW);
		 	outtextxy(200,200,"Q3:Who is the founder of Wipro ?");
		 	settextstyle(1,0,2);
		 	setcolor(WHITE);
		 	outtextxy(300,400,"a.Azim premji.");
		 	outtextxy(670,400,"b.satya nadenla.");
			outtextxy(300,500,"c.Narayana murthi" );
		 	outtextxy(670,500,"d.Kahlil geebran.");
		 	settextstyle(1,0,3);
		 	setcolor(YELLOW);
		 	outtextxy(200,600,"Enter your choice:");
		 	setcolor(WHITE);
			ch=getch();
			if(ch=='a')
			{
				cleardevice();
				settextstyle(3,0,7);
				outtextxy(220,200,"Right Answer..!");
				score=score+30;
		    	getch();
			}
			else
			{
				cleardevice();
				settextstyle(3,0,5);
				outtextxy(470,300,"WRONG");
				getch();
				cleardevice();
				sprintf(myscore,"TOTAL SCORE:%d",score);
				outtextxy(200,200,myscore);
				getch();
				cleardevice();
				outtextxy(500,300,"GAME OVER");
				delay(1000);
				exit(0);
			}
			cleardevice();
		 	settextstyle(8,0,2);
		 	setcolor(LIGHTGREEN);
	       	sprintf(myscore,"%s%d",sco,score);
		 	outtextxy(50,100,myscore);
		 	settextstyle(8,0,5);
		 	outtextxy(200,200,"Q4:Which of this is not a Armstrong number?");
			settextstyle(1,0,2);
		 	setcolor(YELLOW);
		 	outtextxy(300,400,"a.370");
		 	outtextxy(670,400,"b.153");
		 	outtextxy(300,500,"c.371" );
		 	outtextxy(670,500,"d.157");
			settextstyle(1,0,3);
		 	setcolor(CYAN);
			outtextxy(200,600,"Enter your choice:");
		 	setcolor(WHITE);
			ch=getch();
			if(ch=='d')
			{
				cleardevice();
				settextstyle(6,0,5);
				outtextxy(220,200,"Right Answer..!");
				score=score+40;
				getch();
		 	}
			else
			{
				cleardevice();
				settextstyle(3,0,5);
				outtextxy(470,300,"WRONG");
				getch();
				cleardevice();
				sprintf(myscore,"TOTAL SCORE:%d",score);
				outtextxy(200,200,myscore);
		      	//	gotoxy(63,15);
		       	//	cout<<score;
				getch();
				cleardevice();
				outtextxy(500,300,"GAME OVER");
				delay(1000);
				exit(0);
			}
		    cleardevice();
		    //	gotoxy(2,4);
	      	//	cout<<"SCORE:"<<score;
		 	settextstyle(8,0,2);
		 	setcolor(CYAN);
	       	//	 gotoxy(40,4);
	       	//	 cout<<"User Name: "<<name;
	       	sprintf(myscore,"%s%d",sco,score);
		 	outtextxy(30,100,myscore);
		 	settextstyle(8,0,5);
		 	outtextxy(200,200,"Q5:Options that you have given upto now?");
		 	settextstyle(1,0,2);
		 	setcolor(MAGENTA);
		 	outtextxy(300,400,"a.cadc");
		 	outtextxy(470,400,"b.caad");
		 	outtextxy(300,500,"c.acad" );
		 	outtextxy(470,500,"d.dcad");
		 	settextstyle(1,0,3);
		 	setcolor(CYAN);
		 	outtextxy(200,600,"Enter your choice:");
			//line(230,400,280,400);
	       	//	 gotoxy(32,25);
	       	//	 cin>>ch;
		 	setcolor(WHITE);
			ch=getch();
			if(ch=='b')
			{
				cleardevice();
				settextstyle(6,0,5);
				outtextxy(220,200,"Right Answer..!");
				score=score+50;
				cleardevice();
				sprintf(myscore,"TOTAL SCORE:%d",score);
				outtextxy(200,200,myscore);
		      	//	gotoxy(63,15);
		      	//	cout<<score;
				getch();
			}
			else
			{	
				cleardevice();
				settextstyle(3,0,5);
				outtextxy(470,300,"WRONG");
				getch();
				cleardevice();
				sprintf(myscore,"TOTAL SCORE:%d",score);
				outtextxy(200,200,myscore);
		       	//	gotoxy(63,15);
		      	//	cout<<score;
				getch();
				cleardevice();
				outtextxy(500,300,"GAME OVER");
				delay(1000);
				exit(0);
			}
	 }break;
	case 49:
	{
		cleardevice();
		setbkcolor(BLACK);
		setcolor(YELLOW);
		settextstyle(8,0,10);
		outtextxy(300,320,"RACING CARS");
		getch();
		cleardevice();
		int x=1;
		while(x==1)
		{
		cargame CAR;
		x=CAR.game();
		}
		return 0;
	}
}
}	
