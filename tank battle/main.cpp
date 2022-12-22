//#include <stdlib.h>
//#include <fstream>
#include <iostream>  
#include <GL/glut.h> //import opengl library  
#include <math.h>  
using namespace std;  

 
int result1=100; 
int result2=100; 
 
int health1=5; 
int health2=5; 

int tank1Bulletsx=500,tank1Bulletsy=500,tank2Bulletsx=500,tank2Bulletsy=500; 
string dir1="up",dir2="up"; 
bool gun1=false,gun2=false; 
//tank quad variables  
int xx1=0,yy1=0,xx2=30,yy2=30;
//enemy tanks quad varables
int xq1=230,yq1=-170,xq2=260,yq2=-140; 
/////////////// r o t a t i o n -------- v a r i a b l e s  ///////////////////  
float rx1=13.5,ry1=20,rx2=16.5,ry2=37.5,rxx1=13.5,ryy1=20,rxx2=16.5,ryy2=37.5;
int nx1,nx2,ny1,ny2;   
int nxx1,nxx2,nyy1,nyy2;  
///// --------- ///////////  
void keyboard(unsigned char key,int ,int); //return aschi code of the input  
void keyboard2(  int,int ,int);
void draw_breaks();  
void draw_enemy_tank1(int xx1,int yy1,int xx2,int yy2); 
void draw_tank(int xx1,int yy1,int xx2,int yy2); 
void gunshot(); 
void timer(int); 
void death(); 
void text();
void drawText(int ,int ,string,int);
 
  
 void draw(){  
  glClear(GL_COLOR_BUFFER_BIT); // clear old draw  
  draw_tank(xx1,yy1,xx2,yy2);  
  draw_enemy_tank1(xq1,yq1,xq2,yq2);  
  draw_breaks();  
  gunshot(); 
  text();
  glutSwapBuffers(); // make the process faster  
}  
 
 
int main(int argc, char** argv){   
  glutInit(&argc,argv); //define opengl library  
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  
  glutInitWindowSize(1000,600);  
  glutInitWindowPosition(100,50);  
    
  glutCreateWindow("tank battles");  
    
  glClearColor(0.0,0.0,0.0,1.0);// set background color  
  glMatrixMode(GL_PROJECTION); // 2D MODE  
    
  gluOrtho2D(-300.0,400.0,-200.0,200.0);  
    
  glutKeyboardFunc(keyboard);  
  glutSpecialFunc(keyboard2); 
  glutDisplayFunc(draw);  
  glutTimerFunc(0,timer,0); 
  glutMainLoop(); // hold the window to still opened  
    
}  
 
 
void draw_enemy_tank1(int xx1,int yy1,int xx2,int yy2){  
    
  glColor3f(0.635,0.839,0.976);  //set elemetn color  
  //body  
  glBegin(GL_QUADS);  
      glVertex2i(xx1,yy1);  
    glVertex2i(xx1,yy2);  
    glVertex2i(xx2,yy2);  
    glVertex2i(xx2,yy1);  
  glEnd();  
   glColor3f(0.078,0.129,0.239);   //set elemetn color  
  //top body  
  glBegin(GL_POLYGON);  
    glVertex2i(xx1+7.5,yy1+12.5);  
    glVertex2i(xx1+7.5,yy1+17.5);  
    glVertex2i(xx1+15,yy1+22.5);  
    glVertex2i(xx1+22.5,yy1+17.5);  
    glVertex2i(xx1+22.5,yy1+12.5);  
    glVertex2i(xx1+15,yy1+7.5);  
  glEnd();  
  nxx1=xx1+rxx1;  
  nxx2=xx1+rxx2;  
  nyy1=yy1+ryy1;  
  nyy2=yy1+ryy2;  
  // front gun  
  glBegin(GL_QUADS);  
    glVertex2i(nxx1,nyy1);  
    glVertex2i(nxx2,nyy1);  
    glVertex2i(nxx2,nyy2);  
    glVertex2i(nxx1,nyy2);  
  glEnd();  
  
}  
  
  
void draw_tank(int xx1,int yy1,int xx2,int yy2){  
  
  glColor3f(0.635,0.839,0.976); //set elemetn color  
  //body  
  glBegin(GL_QUADS);  
    glVertex2i(xx1,yy1);  
    glVertex2i(xx1,yy2);  
    glVertex2i(xx2,yy2);  
    glVertex2i(xx2,yy1);  
  glEnd();  
   glColor3f(0.988,0.639,0.0666);  //set elemetn color  
  //top body  
  glBegin(GL_POLYGON);  
    glVertex2i(xx1+7.5,yy1+12.5);  
    glVertex2i(xx1+7.5,yy1+17.5);  
    glVertex2i(xx1+15,yy1+22.5);  
    glVertex2i(xx1+22.5,yy1+17.5);  
    glVertex2i(xx1+22.5,yy1+12.5);  
    glVertex2i(xx1+15,yy1+7.5);  
  glEnd();  
  nx1=xx1+rx1;  
  nx2=xx1+rx2;  
  ny1=yy1+ry1;  
  ny2=yy1+ry2;  
  // front gun  
  glBegin(GL_QUADS);  
    glVertex2i(nx1,ny1);  
    glVertex2i(nx2,ny1);  
    glVertex2i(nx2,ny2);  
    glVertex2i(nx1,ny2);  
  glEnd();  
} 
  
 
 
void draw_breaks(){  
//breaks 
     glBegin(GL_POLYGON);  
 glColor3f(0.898,0.898,0.898);  
 glVertex2i(-210,155);  
 glVertex2i(-175,155);  
 glVertex2i(-175,-135);  
 glVertex2i(-210,-135);  
 glEnd();   
  
glBegin(GL_POLYGON);   
 glVertex2i(-140,-35);  
 glVertex2i(-140,-70);  
 glVertex2i(0,-70);  
 glVertex2i(0,-35);  
 glEnd();  
  
  glBegin(GL_POLYGON);  
 glVertex2i(-70,-175);  
 glVertex2i(-70,-140);  
 glVertex2i(60,-140);  
 glVertex2i(60,-175);  
 glEnd();  
  
  glBegin(GL_POLYGON);  
 glVertex2i(105,0);  
 glVertex2i(140,0);  
 glVertex2i(140,-175);  
 glVertex2i(105,-175);  
 glEnd();  
   
  glBegin(GL_POLYGON);  
 glVertex2i(175,-135);  
 glVertex2i(210,-135);  
 glVertex2i(210,155);  
 glVertex2i(175,155);  
 glEnd();  
  
  glBegin(GL_POLYGON);  
 glVertex2i(70,70);  
 glVertex2i(70,105);  
 glVertex2i(-70,105);  
 glVertex2i(-70,70);  
 glEnd();  
 
//result 
  glPointSize(result1); 
  
  glColor3f(0.988,0.639,0.0666); 
    glBegin(GL_POINTS); 
    glVertex2i(400,150); 
    glEnd(); 
     glColor3f(0.078,0.129,0.239);  
    glPointSize(result2); 
    glBegin(GL_POINTS); 
    glVertex2i(400,-150); 
    glEnd(); 
  
//small breaks 
     glBegin(GL_POLYGON);  
      glColor3f(1.0,1.0,1.0);  
 glVertex2i(-210,155);  
 glVertex2i(-175,130);  
 glVertex2i(-175,155);  
 glVertex2i(-210,130);  
 glEnd(); 
      glBegin(GL_POLYGON);  
 glVertex2i(-210,-135);  
 glVertex2i(-175,-105);  
 glVertex2i(-175,-135);  
 glVertex2i(-210,-105);  
 glEnd(); 
  
   glBegin(GL_POLYGON);   
 glVertex2i(-140,-35);  
 glVertex2i(-120,-70);  
 glVertex2i(-140,-70);  
 glVertex2i(-120,-35);  
 glEnd();  
    glBegin(GL_POLYGON);   
 glVertex2i(0,-35);  
 glVertex2i(-20,-70);  
 glVertex2i(0,-70);  
 glVertex2i(-20,-35);  
 glEnd();    
  
   glBegin(GL_POLYGON);  
 glVertex2i(-70,-175);  
 glVertex2i(-50,-140);  
 glVertex2i(-70,-140);  
 glVertex2i(-50,-175);  
 glEnd();  
   glBegin(GL_POLYGON);  
 glVertex2i(60,-175);  
 glVertex2i(40,-140);  
 glVertex2i(60,-140);  
 glVertex2i(40,-175);  
 glEnd(); 
  
   glBegin(GL_POLYGON);  
 glVertex2i(105,0);  
 glVertex2i(140,-20);  
 glVertex2i(140,0);  
 glVertex2i(105,-20);  
 glEnd();    
 glBegin(GL_POLYGON);  
 glVertex2i(105,-175);  
 glVertex2i(140,-155);  
 glVertex2i(140,-175);  
 glVertex2i(105,-155);  
 glEnd();  
  
    glBegin(GL_POLYGON);  
 glVertex2i(175,-135);  
 glVertex2i(210,-115);  
 glVertex2i(210,-135);  
 glVertex2i(175,-115);  
 glEnd();  
   glBegin(GL_POLYGON);   
 glVertex2i(175,155);  
 glVertex2i(210,135);  
 glVertex2i(210,155);  
 glVertex2i(175,135);  
 glEnd();  
  
   glBegin(GL_POLYGON);   
 glVertex2i(70,70);  
 glVertex2i(50,105);  
 glVertex2i(70,105);  
 glVertex2i(50,70);  
 glEnd(); 
   glBegin(GL_POLYGON);  
 glVertex2i(-70,70);  
 glVertex2i(-50,105);  
 glVertex2i(-70,105);  
 glVertex2i(-50,70);  
 glEnd(); 
 glFlush();  
}
 
 
void keyboard(unsigned char key,int,int){  
  if(key==32){ 
    gun1=true; 
    if (  rx1==13.5&&ry1==20){
    	dir1="up";
	}
	else if( ry1==13.5&&rx1==20){
		dir1="right";
	}
	else if(    rx1==13.5&&ry1==10){
		dir1="down";
	}
	else if(    ry1==13.5&&rx1==10){
		dir1="left";
	}
    tank1Bulletsx=nx2; 
    tank1Bulletsy=ny2;
  } 
   	 if(key==48){ 
    gun2=true; 
       if (  rxx1==13.5&&ryy1==20){
    	dir2="up";
	}
	else if( ryy1==13.5&&rxx1==20){
		dir2="right";
	}
	else if(    rxx1==13.5&&ryy1==10){
		dir2="down";
	}
	else if(    ryy1==13.5&&rxx1==10){
		dir2="left";
	}
    tank2Bulletsx=nxx2; 
    tank2Bulletsy=nyy2; 
  } 
 
    if(key=='w'&& yy2<190){  
    if((xx1<-235|xx1>-175|xx2>0|yy1>-135)&&(xx1<-165|xx2>25|yy1<-100|yy1>-35|yy2>0)&&(xx1<0|xx2<175|xx2>235|yy1>-155)&&(xx1<-95|xx2>95|yy1<0|yy2<70|yy2>105)){  
    yy1+=10;  
    yy2+=10;  
    rx1=13.5;  
    ry1=20;  
    rx2=16.5;  
    ry2=37.5;  
}  
 }  
  else if(key=='d'&&xx2<260)  
  {  
   if((xx1<-240|xx1>-200|yy1<-160|yy2>180)&&(xx1<-170|xx2>25|yy1<-95|yy1>-35|yy2>0)&&(xx1<-105|xx2>85|yy1>-140|yy2>0)&&(xx1<0|xx2<105|xx2>140|yy2>25)&&  
   (xx1<0|xx2<175|xx2>210|yy1<-160|yy2>180)&&(xx1<-100|xx2>70|yy1<0|yy2<70|yy2>130)){  
    xx1+=5;  
    xx2+=5;  
    ry1=13.5;  
    rx1=20;  
    ry2=16.5;  
    rx2=37.5; 
}  
  }  
  else if(key=='s'&&yy1>-170){  
    if((xx1<-235|xx1>-175|yy2<185)&&(xx1<-165|xx2>25|yy1>-30|yy1<-70)&&(xx1<-95|xx2>85|yy1>-140)&&(xx1<0|xx2<105|xx2>165|yy2>30)&&  
 (xx1<0|xx2<180|xx2>235|yy2>185)&&(xx1<-95|xx2>95|yy2>135|yy2<105|yy1<0)){  
 yy1-=5;  
    yy2-=5;  
    rx1=13.5;  
    ry1=10;  
    rx2=16.5;  
    ry2=-7.5;  
}  
  }  
  else if(key=='a'&&xx1>-260)  
  {  
   if((xx1<-210|xx1>-175|yy1<-160|yy2>180)&&(xx1<-140|xx2>30|yy1<-95|yy1>-35|yy2>0)&&(xx1<-70|xx2>90|yy1>-140)&&  
   (xx1<0|xx2<105|xx2>170|yy2>25)&&(xx1<0|xx2<175|xx2>240|yy2>185|yy1<-160)&&(xx1<-70|xx2>105|yy1<0|yy2<70|yy2>130)){  
    xx1-=5;  
    xx2-=5;  
    ry1=13.5;  
    rx1=10;  
    ry2=16.5;  
    rx2=-7.5;  
}  
  // conditions   
  }  
    
  draw();  
} 
 

void keyboard2(int key,int,int){

 	   if( key==GLUT_KEY_UP&&yq2<190){  
    if((xq1<-235|xq1>-175|xq2>0|yq1>-135)&&(xq1<-165|xq2>25|yq1<-100|yq1>-35|yq2>0)&&(xq1<0|xq2<175|xq2>235|yq1>-155)&&(xq1<-95|xq2>95|yq1<0|yq2<70|yq2>105)){  
    yq1+=5;  
    yq2+=5;  
    rxx1=13.5;  
    ryy1=20;  
    rxx2=16.5;  
    ryy2=37.5;  
}  
 }  
  else if(key==GLUT_KEY_RIGHT&&xq2<260)  
  {  
   if((xq1<-240|xq1>-200|yq1<-160|yq2>180)&&(xq1<-170|xq2>25|yq1<-95|yq1>-35|yq2>0)&&(xq1<-105|xq2>85|yq1>-140|yq2>0)&&(xq1<0|xq2<105|xq2>140|yq2>25)&&  
   (xq1<0|xq2<175|xq2>210|yq1<-160|yq2>180)&&(xq1<-100|xq2>70|yq1<0|yq2<70|yq2>130)){  
    xq1+=5;  
    xq2+=5;  
    ryy1=13.5;  
    rxx1=20;  
    ryy2=16.5;  
    rxx2=37.5;  
}  
  }  
  else if(key==GLUT_KEY_DOWN&&yq1>-170){  
    if((xq1<-235|xq1>-175|yq2<185)&&(xq1<-165|xq2>25|yq1>-30|yq1<-70)&&(xq1<-95|xq2>85|yq1>-140)&&(xq1<0|xq2<105|xq2>165|yq2>30)&&  
 (xq1<0|xq2<180|xq2>235|yq2>185)&&(xq1<-95|xq2>95|yq2>135|yq2<105|yq1<0)){  
 yq1-=5;  
    yq2-=5;  
    rxx1=13.5;  
    ryy1=10;  
    rxx2=16.5;  
    ryy2=-7.5;  
}  
  }  
  else if(key==GLUT_KEY_LEFT&&xq1>-260)  
  {  
   if((xq1<-210|xq1>-175|yq1<-160|yq2>180)&&(xq1<-140|xq2>30|yq1<-95|yq1>-35|yq2>0)&&(xq1<-70|xq2>90|yq1>-140)&& 
(xq1<0|xq2<105|xq2>170|yq2>25)&&(xq1<0|xq2<175|xq2>240|yq2>185|yq1<-160)&&(xq1<-70|xq2>105|yq1<0|yq2<70|yq2>130)){  
    xq1-=5;  
    xq2-=5;  
    ryy1=13.5;  
    rxx1=10;  
    ryy2=16.5;  
    rxx2=-7.5;  
}  
    
} 
 	  draw();  
 }


void gunshot(){ 
  	glPointSize(5); 
  	glColor3f(0.5,0.0,0.2); 
    glBegin(GL_POINTS); 
    glVertex2i(tank1Bulletsx,tank1Bulletsy); 
    glEnd(); 
    glColor3f(0.1,0.1,0.4);  
    glBegin(GL_POINTS); 
    glVertex2i(tank2Bulletsx,tank2Bulletsy); 
    glEnd(); 
} 
 
 
void timer(int ){ 
  glutPostRedisplay(); 
  glutTimerFunc(1000/30,timer,0); 
  death(); 
  if (gun1){ 
    if(dir1=="up") 
    {
      tank1Bulletsy+=30;
      if((tank1Bulletsx>-140&&tank1Bulletsx<0&&tank1Bulletsy>-65&&tank1Bulletsy<-35)||
      (tank1Bulletsx>-70&&tank1Bulletsx<70&&tank1Bulletsy>70&&tank1Bulletsy<105)){
      	tank1Bulletsy=500;
	  }
      if(tank1Bulletsy>200){ 
       gun1=false; 
   		}
    } 
    else if(dir1=="right") 
    { 
      tank1Bulletsx+=30; 
      if((tank1Bulletsx>-210&&tank1Bulletsx<-175&&tank1Bulletsy>-135&&tank1Bulletsy<155)||(tank1Bulletsx>-140&&tank1Bulletsx<0&&tank1Bulletsy>-70&&tank1Bulletsy<-35)||
	  (tank1Bulletsx>-70&&tank1Bulletsx<60&&tank1Bulletsy>-175&&tank1Bulletsy<-140)||(tank1Bulletsx>105&&tank1Bulletsx<140&&tank1Bulletsy>-175&&tank1Bulletsy<0)||
	  (tank1Bulletsx>175&&tank1Bulletsx<210&&tank1Bulletsy>-135&&tank1Bulletsy<155)||(tank1Bulletsx>-70&&tank1Bulletsx<70&&tank1Bulletsy>70&&tank1Bulletsy<105)){
	  	tank1Bulletsx=500;
	  }
       if(tank1Bulletsx>400){ 
       gun1=false; 
   } 
    } 
    else if(dir1=="down") 
    { 
      tank1Bulletsy-=30; 
    if((tank1Bulletsx>-210&&tank1Bulletsx<-175&&tank1Bulletsy>-135&&tank1Bulletsy<155)||(tank1Bulletsx>-140&&tank1Bulletsx<0&&tank1Bulletsy>-70&&tank1Bulletsy<-35)||
	  (tank1Bulletsx>-70&&tank1Bulletsx<60&&tank1Bulletsy>-175&&tank1Bulletsy<-140)||(tank1Bulletsx>105&&tank1Bulletsx<140&&tank1Bulletsy>-175&&tank1Bulletsy<0)||
	  (tank1Bulletsx>175&&tank1Bulletsx<210&&tank1Bulletsy>-135&&tank1Bulletsy<155)||(tank1Bulletsx>-70&&tank1Bulletsx<70&&tank1Bulletsy>70&&tank1Bulletsy<105)){
	  	tank1Bulletsy=-500;
	  }
       if(tank1Bulletsy<-200){ 
       gun1=false; 
   } 
    } 
    else if(dir1=="left") 
    { 
      tank1Bulletsx-=30; 
          if((tank1Bulletsx>-210&&tank1Bulletsx<-175&&tank1Bulletsy>-135&&tank1Bulletsy<155)||(tank1Bulletsx>-140&&tank1Bulletsx<0&&tank1Bulletsy>-70&&tank1Bulletsy<-35)||
	  (tank1Bulletsx>-70&&tank1Bulletsx<60&&tank1Bulletsy>-175&&tank1Bulletsy<-140)||(tank1Bulletsx>105&&tank1Bulletsx<140&&tank1Bulletsy>-175&&tank1Bulletsy<0)||
	  (tank1Bulletsx>175&&tank1Bulletsx<210&&tank1Bulletsy>-135&&tank1Bulletsy<155)||(tank1Bulletsx>-70&&tank1Bulletsx<70&&tank1Bulletsy>70&&tank1Bulletsy<105)){
	  	tank1Bulletsx=-500;
	  }
       if(tank1Bulletsx<-300){ 
       gun1=false; 
   } 
    } 
  } 
   if (gun2){ 
    if(dir2=="up") 
    { 
      tank2Bulletsy+=30; 
        if((tank2Bulletsx>-140&&tank2Bulletsx<0&&tank2Bulletsy>-65&&tank2Bulletsy<-35)||
      (tank2Bulletsx>-70&&tank2Bulletsx<70&&tank2Bulletsy>70&&tank2Bulletsy<105)){
      	tank2Bulletsy=500;
	  }
      if(tank2Bulletsy>200){ 
       gun2=false; 
   } 
    } 
    else if(dir2=="right") 
    { 
      tank2Bulletsx+=30; 
      if((tank2Bulletsx>-210&&tank2Bulletsx<-175&&tank2Bulletsy>-135&&tank2Bulletsy<155)||(tank2Bulletsx>-140&&tank2Bulletsx<0&&tank2Bulletsy>-70&&tank2Bulletsy<-35)||
	  (tank2Bulletsx>-70&&tank2Bulletsx<60&&tank2Bulletsy>-175&&tank2Bulletsy<-140)||(tank2Bulletsx>105&&tank2Bulletsx<140&&tank2Bulletsy>-175&&tank2Bulletsy<0)||
	  (tank2Bulletsx>175&&tank2Bulletsx<210&&tank2Bulletsy>-135&&tank2Bulletsy<155)||(tank2Bulletsx>-70&&tank2Bulletsx<70&&tank2Bulletsy>70&&tank2Bulletsy<105)){
	  	tank2Bulletsx=500;
	  }
       if(tank2Bulletsx>400){ 
       gun2=false; 
   } 
    } 
    else if(dir2=="down") 
    { 
      tank2Bulletsy-=30; 
      if((tank2Bulletsx>-210&&tank2Bulletsx<-175&&tank2Bulletsy>-135&&tank2Bulletsy<155)||(tank2Bulletsx>-140&&tank2Bulletsx<0&&tank2Bulletsy>-70&&tank2Bulletsy<-35)||
	  (tank2Bulletsx>-70&&tank2Bulletsx<60&&tank2Bulletsy>-175&&tank2Bulletsy<-140)||(tank2Bulletsx>105&&tank2Bulletsx<140&&tank2Bulletsy>-175&&tank2Bulletsy<0)||
	  (tank2Bulletsx>175&&tank2Bulletsx<210&&tank2Bulletsy>-135&&tank2Bulletsy<155)||(tank2Bulletsx>-70&&tank2Bulletsx<70&&tank2Bulletsy>70&&tank2Bulletsy<105)){
	    tank2Bulletsy=-500;
	  }
       if(tank2Bulletsy<-200){ 
       gun2=false; 
   } 
    } 
    else if(dir2=="left") 
    { 
      tank2Bulletsx-=30;
	  if((tank2Bulletsx>-210&&tank2Bulletsx<-175&&tank2Bulletsy>-135&&tank2Bulletsy<155)||(tank2Bulletsx>-140&&tank2Bulletsx<0&&tank2Bulletsy>-70&&tank2Bulletsy<-35)||
	  (tank2Bulletsx>-70&&tank2Bulletsx<60&&tank2Bulletsy>-175&&tank2Bulletsy<-140)||(tank2Bulletsx>105&&tank2Bulletsx<140&&tank2Bulletsy>-175&&tank2Bulletsy<0)||
	  (tank2Bulletsx>175&&tank2Bulletsx<210&&tank2Bulletsy>-135&&tank2Bulletsy<155)||(tank2Bulletsx>-70&&tank2Bulletsx<70&&tank2Bulletsy>70&&tank2Bulletsy<105)){
	  	tank2Bulletsx=-500;
	  } 
       if(tank2Bulletsx<-300){ 
       gun2=false; 
   } 
    } 
  } 
} 
 
 
void death(){ 
  if(tank1Bulletsx>xq1&&tank1Bulletsx<xq2&&tank1Bulletsy>yq1&&tank1Bulletsy<yq2){ 
    health2--; 
    result2 -=20; 
  } 
  if(health2==0){ 
    exit(0); 
  } 
  if(tank2Bulletsx>xx1&&tank2Bulletsx<xx2&&tank2Bulletsy>yy1&&tank2Bulletsy<yy2){ 
    health1--; 
    result1 -=20; 
  } 
  if(health1==0){ 
    exit(0); 
  } 
}


void text(){
	 glColor3f(0.078,0.129,0.239);  
	drawText(300,80,"player1",0);
	drawText(300,-80,"player2",0);
	drawText(-60,83,"S A M E H",0);
	drawText(-135,-55,"O S T O R A",0);
	drawText(-50,-160,"A Y A",0);
	drawText(188,110,"F A R I D",1);
	drawText(-198,110,"A H M E D",1);
	drawText(117,-30,"TEAM1",1);
}



void drawText(int x,int y,string text,int direction){
	for (int i=0; i<text.length();i++){
		if(direction==0){
			x+=10;
		}
		else{
			y-=20;
		}
		glRasterPos2i(x,y);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
	}
}




