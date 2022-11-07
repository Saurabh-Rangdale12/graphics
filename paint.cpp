#include<graphics.h>
#include<stdlib.h>
#include <math.h>
#include <iostream>
int colr=0;
int radii=2;
void loading();
void drawingpad();
void setup();
void boundaryfill(int x,int y,int fill,int boundary);
// void camera();
void cir();
void eraser();
void clear();
int main()
{
	int gd=DETECT,gm=0;
	initgraph(&gd,&gm,(char*)"");
	initwindow(1000,680,"Saurabh And Vishnu"); //windows coordinate
	setbkcolor(WHITE);
	cleardevice(); 
	//loading();//to show loading bar
	cleardevice();
	drawingpad();//main drawing canvas
	getch();
	closegraph();
}
 	void loading()
 	{
 	readimagefile("./Logowt.jpg",385,250,585,450);//to display image 
 	setcolor(RED);
 	outtextxy(830,630,(char*)"Developed by Saurabh And Vishnu");
 	setcolor(RED);
 	rectangle(350,460,620,480);
	for(int i=0;i<260;i++)//loading bar at begining
	{
		setcolor(12);
		rectangle(355,465,355+i,475);
		delay(1);
	}
	}
	
	void drawingpad()
	{
		POINT cursorpos;
		setup();
		int choice=0;
		while(1)
		{
			setcolor(colr);
			GetCursorPos(&cursorpos);//to get screen co-ordinate
			ScreenToClient(GetForegroundWindow(),&cursorpos);//to convert screen co-ordinate to window co-ordinate
			int x1,y1,x2,y2;
			if(ismouseclick(WM_LBUTTONDOWN))
			{
				x1=cursorpos.x;
				y1=cursorpos.y;
				clearmouseclick(WM_LBUTTONDOWN);
			}
			if(ismouseclick(WM_LBUTTONUP))
			{
				x2=cursorpos.x;
				y2=cursorpos.y;
				clearmouseclick(WM_LBUTTONUP);
				if(choice==1)
				{
					double dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
					int xc=(x1+x2)/2;
					int yc=(y1+y2)/2;
					circle(xc,yc,dis/2);
				}
				else if(choice==2)
				{
					line(x1,y1,x2,y2);
				}
				else if(choice==3)
				{
					rectangle(x1,y1,x2,y2);
				}
			}
			if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0) && cursorpos.x >=80)
			{
				GetCursorPos(&cursorpos);
				switch(choice)
				{
					case 0:
						break;
					case 1:
						// if(cursorpos.x >= 80+radii*10)
						// 	circle(cursorpos.x, cursorpos.y, radii*10);
						break;
					case 2: //managed above (line)
						break;
					case 3: //managed above (rectangle)
						break;
					case 4:
						circle(cursorpos.x,cursorpos.y,radii);	
						boundaryfill(cursorpos.x,cursorpos.y,colr,colr);
						break;
					case 5:
						std::cout<<"case 5 selected\n";
						boundaryfill(cursorpos.x,cursorpos.y,BLACK,BLACK);
						delay(500);
						break;
				}
			}
			// if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>81&&cursorpos.x<994&&cursorpos.y>1&&cursorpos.y<675)//getkeystate detects the mouse left button press
			// {
			// 	choice=0;
			// }
			//first button
			if(((GetAsyncKeyState(VK_LBUTTON)) != 0) && cursorpos.x>=18 && cursorpos.x <=40 && cursorpos.y>=50 && cursorpos.y<=70)
			{
				choice=1; //circle
			}
			else if(((GetAsyncKeyState(VK_LBUTTON)) != 0) && cursorpos.x>=44 && cursorpos.x <=66 && cursorpos.y>=50 && cursorpos.y<=70)
			{
				choice=2; //line
			}
			else if(((GetAsyncKeyState(VK_LBUTTON)) != 0) && cursorpos.x>=18 && cursorpos.x <=40 && cursorpos.y>=74 && cursorpos.y<=94)
			{
				choice=3; //rectangle
			}
			else if(((GetAsyncKeyState(VK_LBUTTON)) != 0) && cursorpos.x>=44 && cursorpos.x <=66 && cursorpos.y>=74 && cursorpos.y<=94)
			{
				choice=4; //rectangle
				outtextxy(13,598,(char*)"Choice:     ");
				outtextxy(13,615,(char*)"4    ");
			}
			
			// else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>18&&cursorpos.x<40&&cursorpos.y>50&&cursorpos.y<70){
			// 	circle(cursorpos.x,cursorpos.y,7);
			// 	outtextxy(13,598,(char*)"Circle     ");
			// 	outtextxy(13,615,(char*)"In Use    ");
			// }

			//Color black
			if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>18&&cursorpos.x<40&&cursorpos.y>180&&cursorpos.y<200)
			{
				colr=13;
				setcolor(8);
				outtextxy(13,598,(char*)"Marker     ");
				outtextxy(13,615,(char*)"In Use    ");
			}
			
			//Color magenta
			else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>44&&cursorpos.x<66&&cursorpos.y>180&&cursorpos.y<200)
			{
				colr=5;
				setcolor(8);
				outtextxy(13,598,(char*)"Marker     ");
				outtextxy(13,615,(char*)"In Use    ");
			}
			
			//Color blue
			else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>18&&cursorpos.x<40&&cursorpos.y>204&&cursorpos.y<224)
			{
				colr=1;
				setcolor(8);
				outtextxy(13,598,(char*)"Marker     ");
				outtextxy(13,615,(char*)"In Use    ");
			}
			
			//Color green
			else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>44&&cursorpos.x<66&&cursorpos.y>204&&cursorpos.y<224)
			{
				colr=2;
				setcolor(8);
				outtextxy(13,598,(char*)"Marker     ");
				outtextxy(13,615,(char*)"In Use    ");
			}
			
			//Color red
			else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>18&&cursorpos.x<40&&cursorpos.y>228&&cursorpos.y<248)
			{
				colr=4;
				setcolor(8);
				outtextxy(13,598,(char*)"Marker     ");
				outtextxy(13,615,(char*)"In Use    ");
			}
			
			//Color yellow
			else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>44&&cursorpos.x<66&&cursorpos.y>228&&cursorpos.y<248)
			{
				colr=14;
				setcolor(8);
				outtextxy(13,598,(char*)"Marker     ");
				outtextxy(13,615,(char*)"In Use    ");
			}
			
			//Color cyan
			else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>18&&cursorpos.x<40&&cursorpos.y>252&&cursorpos.y<272)
			{
				colr=3;
				setcolor(8);
				outtextxy(13,598,(char*)"Marker     ");
				outtextxy(13,615,(char*)"In Use    ");
			}
			
			//Color Brown
			else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>44&&cursorpos.x<66&&cursorpos.y>252&&cursorpos.y<272)
			{
				colr=6;
				setcolor(8);
				outtextxy(13,598,(char*)"Marker     ");
				outtextxy(13,615,(char*)"In Use    ");
			}
			
			//Color light red
			else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>18&&cursorpos.x<40&&cursorpos.y>276&&cursorpos.y<296)
			{
				colr=12;
				setcolor(8);
				outtextxy(13,598,(char*)"Marker     ");
				outtextxy(13,615,(char*)"In Use    ");
			}
			
			//Color light red
			else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>44&&cursorpos.x<66&&cursorpos.y>276&&cursorpos.y<296)
			{
				colr=9;
				setcolor(8);
				outtextxy(13,598,(char*)"Marker     ");
				outtextxy(13,615,(char*)"In Use    ");
			}
			
				//Eraser
			else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>18&&cursorpos.x<66&&cursorpos.y>300&&cursorpos.y<350)
			{
				colr=15;
				setcolor(8);
				outtextxy(13,598,(char*)"Eraser      ");
				outtextxy(13,615,(char*)"In Use    ");
			}
			//snapshot
			// else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>18&&cursorpos.x<66&&cursorpos.y>354&&cursorpos.y<404)
			// {
 				
			// 	writeimagefile("snapshot.jpg",82,2,993,674);
			// 	setcolor(8);
			// 	outtextxy(13,598,(char*)"Snapshot");
			// 	outtextxy(13,615,(char*)"Taken ");
				
			// }
			//Clear all
			else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>18&&cursorpos.x<66&&cursorpos.y>408&&cursorpos.y<458)
			{
				cleardevice();
				setup();
				setcolor(8);
				outtextxy(13,598,(char*)"Cleared    ");
				outtextxy(13,615,(char*)"All      ");
			}

			else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>18&&cursorpos.x<66&&cursorpos.y>354&&cursorpos.y<404)
			{
				// setup();
				// setcolor(8);
				choice=5;
				outtextxy(13,598,(char*)"Flood    ");
				outtextxy(13,615,(char*)"Fill      ");
			}
			//Brushsize
			else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>18&&cursorpos.x<40&&cursorpos.y>484&&cursorpos.y<508)
			{
				radii=2;
				setcolor(8);
				outtextxy(13,598,(char*)"Brush      ");
				outtextxy(13,615,(char*)"2px      ");
			}
			else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>44&&cursorpos.x<66&&cursorpos.y>484&&cursorpos.y<508)
			{
				radii=6;
				setcolor(8);
				outtextxy(13,598,(char*)"Brush     ");
				outtextxy(13,615,(char*)"6px      ");
			}
			
			else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>18&&cursorpos.x<40&&cursorpos.y>512&&cursorpos.y<536)
			{
				radii=10;
				setcolor(8);
				outtextxy(13,598,(char*)"Brush      ");
				outtextxy(13,615,(char*)"10px      ");
			}
			
			else if(((GetKeyState(VK_LBUTTON) & 0x8000) != 0)&&cursorpos.x>44&&cursorpos.x<66&&cursorpos.y>512&&cursorpos.y<536)
			{
				radii=14;
				setcolor(8); 
				outtextxy(13,598,(char*)"Brush      ");
				outtextxy(13,615,(char*)"14px      ");
			}
		}
		
		
	}
	void setup()
	{
		readimagefile("Logos.jpg",6,50,76,120);
		setcolor(1);
		//status:
		outtextxy(13,580,(char*)"Status: ");
		setcolor(8);
		//canvas vv
		rectangle(80,0,995,676);
		rectangle(81,1,994,675);
		
		//tool box vv
		rectangle(10,40,74,468);
		rectangle(11,41,73,467);
		
		//size outline
		rectangle(10,474,74,560);
		rectangle(11,475,73,559);
		outtextxy(28,540,(char*)"SIZE");
		outtextxy(26,489,(char*)"1");
		outtextxy(52,489,(char*)"2");
		outtextxy(26,516,(char*)"3");
		outtextxy(52,516,(char*)"4");
		
		
		//brush size vv
		rectangle(18,484,40,508);
		rectangle(44,484,66,508);
		
		rectangle(18,512,40,536);
		rectangle(44,512,66,536);
		
		//top buttons
		rectangle(18,50,40,70); circle(29,60,7);
		rectangle(44,50,66,70); line(49,55,61,65);

		rectangle(18,74,40,94); rectangle(22,80,36,88);
		rectangle(44,74,66,94);
		//colors vv
		rectangle(18,180,40,200);
		rectangle(44,180,66,200);
		
		rectangle(18,204,40,224);
		rectangle(44,204,66,224);
		
		rectangle(18,228,40,248);
		rectangle(44,228,66,248);
		
		rectangle(18,252,40,272);
		rectangle(44,252,66,272);
		
		rectangle(18,276,40,296);
		rectangle(44,276,66,296);
		
		//eraser vv
		eraser();
		rectangle(18,300,66,350);
		
		//Screenshot vv
		// camera();
		// rectangle(18,354,66,404);
		
		// clear vv
		clear();
		rectangle(18,408,66,458);

		clear();
		rectangle(18,354,66,404);
		
		/*-----------------------*/
		
		boundaryfill(12,174,7,8);
		
		boundaryfill(12,476,7,8);
		
		boundaryfill(19,181,0,8);
		boundaryfill(45,181,5,8);
			
		boundaryfill(19,205,1,8);
		boundaryfill(45,205,2,8);
		
		boundaryfill(19,229,4,8);
		boundaryfill(45,229,14,8);
		
		boundaryfill(19,253,3,8);
		boundaryfill(45,253,6,8);
		
		boundaryfill(19,277,12,8);
		boundaryfill(45,277,9,8);
		
		/*-----------------------*/
		
		
		
		
		
	
	}
	void boundaryfill(int x,int y, int fill, int boundary)
	{
		int current=getpixel(x,y);
		if((current!=boundary)&&(current!=fill))
		{
			// setcolor(fill);
			putpixel(x,y,fill);
			boundaryfill(x+1,y,fill,boundary);
			boundaryfill(x,y-1,fill,boundary);
			boundaryfill(x-1,y,fill,boundary);
			boundaryfill(x,y+1,fill,boundary);
		}
	}
	
	// void camera()
	// {
	// 	outtextxy(28,387,(char*)"snap");
	// 	rectangle(26,367,60,387);
	// 	rectangle(27,368,59,386);
		
	// 	rectangle(50,363,58,367);
	// 	rectangle(51,364,57,366);
		
	// 	circle(44,378,6);
	// 	circle(44,378,7);
	// 	circle(44,378,3);
	// }

	void cir(){
		circle(30,60,7);
	}
	
	void clear()
	{
		outtextxy(26,440,(char*)"clear");
	
		circle(42,428,10);
		circle(42,428,9);
		outtextxy(39,411,(char*)"<");
	}
	
	void eraser()
	{
		outtextxy(25,332,(char*)"erase");
		line(26,330,58,330);
		rectangle(35,306,50,330);
		rectangle(36,307,49,329);
		line(35,318,50,318);
		boundaryfill(37,317,8,8);
		
	}

 
