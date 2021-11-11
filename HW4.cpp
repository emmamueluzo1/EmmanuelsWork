// Emmanuel Uzochukwu
// 2/1/2020
// CSCI 4550
// HW2

#include<iostream>
#include<cstdlib>
#include<cmath>
#include <ctime>
#include<GL/freeglut.h>
#include<string>
#include<cstring>
#define MSEC_PER_FRAME 10
#define PI 3.14159265

using namespace std;

int location = 0;
int carLoc = -4;
int eyex = 0;
int eyey = 4;
int eyez = 0;
int arr[20];
void storage();
void creatObstacles();
bool collision = false;
int score = 0;
bool gainPoint = false;
string message;
bool pauseGame = false;
int in_x = 0;
int in_y = 0;

void writeBitmapString(void *font, char *string){
	for (char* c = string; *c != '\0'; c++)
		glutBitmapCharacter(font, *c);
}
void Draw_Road()
{
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex3f(-50.0, 0.0, 0.0);
		glVertex3f(-50.0, 0.0, 1000);//we moved to the left n/6 and down n/2
		glVertex3f(50.0, 0.0, 1000);//we moved to the right n/6 and down n/2
		glVertex3f(50.0, 0.0, 0.0);//we moved to the right n/6 and up n/2
		glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8, 0.8, 0.8);
	//glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0,0,500);	//scaled 500 to move it 500 forward in the z. Previously it already had 500 behind me. That is what we move
	//forward by 500 there for having a 1000 in fornt of our camera
	glScalef(16,0.1,1000);

	glutSolidCube(1);
	glPopMatrix();

	glColor3f(1.0,1.0,1.0);

	for(int i = 0; i<50; i++)
	{
		//if(i%5 == 0)
		//{
		glPushMatrix();
			//
			glTranslatef(0, 0, 20*i);
			glScalef(1, 1, 5);
			glutSolidCube(1);
			//glVertex3f(0.0, 0.10005, i);
		//}
		glPopMatrix();
	}


}

void objectCollison()
{
	for(int i=0; i<20; i++)
	{
		if((location == (arr[i]* 40)) && (-4.0+(8*(arr[i]%2)) == carLoc))
		{
			pauseGame = true;
			collision = true;
			break;
		}
	}
}



//will help us determind a range within which the arrow will spin but not more than that
void timerFunc(int value)
{
	for(int i=0;i<20;i++)
		cout << carLoc << " " << -4.0+(8*(arr[i]%2)) << " " << location << " " << arr[i]* 40 << endl;

	if(pauseGame == false)
	{
		objectCollison();
		
		if(location < 985)
		{
			location++;
			//below if will be used to increment point system for player
			/*
			if(location > arr[i]*40)
 		  {	
 				score++;
 				gainPoint = true;
 		  }
			//cout << location << endl;*/
		}

	}

   glutPostRedisplay();// will create a updated screen of our window every 33.33 ms. This is how our print to the window does not
   										//overlap
   glutTimerFunc(MSEC_PER_FRAME, timerFunc, value);
}

//Keyboard input processing routine.
void keyInput(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		if(carLoc!=4)
		{
			carLoc = 4;
		}
		break;
	case GLUT_KEY_RIGHT:
		if(carLoc!=-4)
		{
		carLoc = -4;
		}
		break;

	}
	glutPostRedisplay();
}

void keyInput_2(unsigned char key, int x, int y)
{
//cout << key << endl << endl;
switch (key)
	{
		case ' ':
			 pauseGame = !pauseGame;
		break;
		case 'o':
			 pauseGame = !pauseGame;
			 collision = !collision;
		break;
	}
	glutPostRedisplay();
}

void storage()
{
	for(int i=0; i<20; i++)
	{
		//20 because we want 20 obsticles
		arr[i]= rand()%25 +1;
		//we mod so that our random numbers will range from 1-38 (dividing the road into 38 slots not points)
		//where we will add obsticles using a separte function.
	}
	//for(int j = 0; j<20; j++)//for debuggind purposes
		//cout << arr[j] << endl;
}

void createObstacle()
{

	for(int i =0; i<20; i++)
	{
		glPushMatrix();
		float color = (rand()%100)/100.0;//this will just give us variety with the color of our obstacles
		float color1 = (rand()%100)/100.0;
		float color2 = (rand()%100)/100.0;
				glColor3f(color, color1, color2);
				//if arr[i] is odd then mod 2 will have a remainder of 1, if even a remainder of 0.
				//8*1 will equal 8 plus -4 will be the left side of my road. 8*0 +(-4) will be the right side
				//of our road. NOTE: the middle of our road on right side is -4 and 4 on left
				//because our road is going in the positive z not negative. <--------------all this was for x coordinate.
				glTranslatef(-4.0+(8*(arr[i]%2)), 0.5, (arr[i]*40));


				//multiplied by 25 to span the objects to the proper length of the road
				// chose 25 becasue 1000/40 = 25 and our random array has partitioned the road
				//into 25 partitions because we have 20 obstacles with about 40 length of space in between
				glutSolidCube(2);
				//cout << arr[i] << endl;
			glPopMatrix();
	}
}


//This was my attempt at printint out my score. Sadly it did not work
/*
void writeStrokeString(void *font, const char *string)
{
	int i = 0;
	while(string[i] != '\0')
	{
		glutStrokeCharacter (font, string[i]);
		i++;
	}
}
*/

// Initialization routine.
void setup(void)
{
	glClearColor(0.0, 1.0, 0.95, 0.0);
}


void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.5, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


// this function holds and calls each of the above shape functions
void drawScene(void)
{
	glViewport(0, 0, 500, 500);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();


	//gluLookAt(0.0,15.0,0.0,0.0,0.0,5.0,eyex,eyey,eyez);

	gluLookAt(0.0,15.0,location-15,0.0,0,location+35.0,0.0,0.0,1.0);
	glPushMatrix();
		Draw_Road();
		glColor3f(1,0,0);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(carLoc,3,location);
		glutSolidCube(4);
		glPopMatrix();
		//cout << location << endl;
	glPopMatrix();

	createObstacle();
	
	//necessary to print score to screen but did not have time to finish
	//std::string s = std::to_string (score);
	//char const *displayScore = s.c_str();
	
	 
	//viewport for the collision
	if(collision == true )
	{
		
		glViewport(150, 200, 200, 100);
		glScissor(150,200,200,100);
		glEnable(GL_SCISSOR_TEST);
		glClearColor(1.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glDisable(GL_SCISSOR_TEST);

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glOrtho(-20,20,-10,10,-1,5);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glColor3f(1,1,1);glRasterPos3f(-15, 0, 0);
		writeBitmapString(GLUT_BITMAP_HELVETICA_18, "YOU CRASHED!");
		glRasterPos3f(-15, -5, 0);
		writeBitmapString(GLUT_BITMAP_HELVETICA_18, "Try again! Press 'O'");

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);

		glClearColor(0.0, 1.0, 0.95, 0.0);
	}

	//viewport for score but sadly i could not figue it out in time
	/*
	if(collision == true || collision == false)
	{
		if(pauseGame == true || pauseGame == false)
		{
			glViewport(350, 200, 200, 100);
			glScissor(350,200,200,100);
			glEnable(GL_SCISSOR_TEST);
			glClearColor(1.0, 1.0, 0.0, 0.0);
			glClear(GL_COLOR_BUFFER_BIT);
			glDisable(GL_SCISSOR_TEST);

			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			glLoadIdentity();
			glOrtho(-20,20,-10,10,-1,5);

			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			glColor3f(0,0,1);
			glRasterPos3f(-15, 0, 0);
			glLineWidth(1);
			glPointSize(1);	
			writeStrokeString(GLUT_STROKE_ROMAN, *str);
	
			glMatrixMode(GL_PROJECTION);
			glPopMatrix();
			glMatrixMode(GL_MODELVIEW);

			glClearColor(0.0, 1.0, 0.95, 0.0);
		}
		
	}
	*/
	
	
	


	glDisable(GL_DEPTH_TEST);
	glFlush();
}



// Main routine.
int main(int argc, char **argv)
{
	srand(time(0));
	storage();

	glutInit(&argc, argv);

	glutInitContextVersion(3, 0);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Emmanuels_Window.cpp");
	srand( time(NULL));
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput_2);
	//glutMouseFunc(mouseControl);
	glutSpecialFunc(keyInput);
	glutTimerFunc(MSEC_PER_FRAME, timerFunc, 1);


	setup();

	glutMainLoop();
}
