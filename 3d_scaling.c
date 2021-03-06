#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h>

int cx[]={-100,0,200,200,0,-100,100,100,200},cy[]={-100,0,0,200,200,100,100,-100,200},cz[]={0,100,100,100,100,0,0,0,100};
float tx=0,ty=0,tz=0;
int flag=0;
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
   glOrtho(-780, 780, -420, 420,-400,400); 
}

void drawQuad(int a,int b,int c, int d)
{
	glVertex3i(cx[a],cy[a],cz[a]);
	glVertex3i(cx[b],cy[b],cz[b]);
	glVertex3i(cx[c],cy[c],cz[c]);
	glVertex3i(cx[d],cy[d],cz[d]);
}

void drawTriangle(int a,int b,int c)
{
	glVertex3i(cx[a],cy[a],cz[a]);
	glVertex3i(cx[b],cy[b],cz[b]);
	glVertex3i(cx[c],cy[c],cz[c]);
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

	int i;
	for(i=0;i<9;i++)
	{
		cx[i]-=250;
	}	

   glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
		drawQuad(5,6,7,0);
		glColor3f(0.0f, 1.0f, 1.0f);
		drawQuad(5,4,3,6);
		glColor3f(0.4f, 0.5f, 1.0f);
		drawQuad(6,3,2,7);
		glColor3f(0.2f, 0.5f, 0.1f);
		drawQuad(0,5,4,1);
		glColor3f(0.5f, 0.1f, 0.2f);
		drawQuad(1,4,3,2);
		glColor3f(0.1f, 0.2f, 0.5f);
		drawQuad(1,2,7,0);
	glEnd();
	
	
	for(i=0;i<9;i++)
	{
		cx[i]+=250;
	}	
	

	for(i=0;i<9;i++)
	{
		cx[i]*=tx;
		cy[i]*=ty;
		cz[i]*=tz;
	}	
	
	for(i=0;i<9;i++)
	{
		cx[i]+=250;
	}
	
	   glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
		drawQuad(5,6,7,0);
		glColor3f(0.0f, 1.0f, 1.0f);
		drawQuad(5,4,3,6);
		glColor3f(0.4f, 0.5f, 1.0f);
		drawQuad(6,3,2,7);
		glColor3f(0.4f, 1.0f, 0.3f);
		drawQuad(0,5,4,1);
		glColor3f(1.0f, 0.3f, 0.4f);
		drawQuad(1,4,3,2);
		glColor3f(0.3f, 0.4f, 1.0f);
		drawQuad(1,2,7,0);
	glEnd();
   glutSwapBuffers();  
}

void display11() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
	int i;
	for(i=0;i<9;i++)
	{
		cx[i]-=250;
	}	

	glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 1.0f, 1.0f);
		drawQuad(0,5,6,7);
		glColor3f(0.4f, 0.5f, 1.0f);
		drawTriangle(5,6,8);
		glColor3f(0.2f, 0.5f, 0.1f);
		drawTriangle(6,7,8);
		glColor3f(0.5f, 0.1f, 0.2f);
		drawTriangle(0,7,8);
		glColor3f(0.1f, 0.2f, 0.5f);
		drawTriangle(5,0,8);
	glEnd();
	
	for(i=0;i<9;i++)
	{
		cx[i]+=250;
	}	
	

	for(i=0;i<9;i++)
	{
		cx[i]*=tx;
		cy[i]*=ty;
		cz[i]*=tz;
	}	
	
	for(i=0;i<9;i++)
	{
		cx[i]+=250;
	}
	
	glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 1.0f);
		drawQuad(0,5,6,7);
		glColor3f(0.4f, 0.5f, 1.0f);
		drawTriangle(5,6,8);
		glColor3f(0.4f, 1.0f, 0.3f);
		drawTriangle(6,7,8);
		glColor3f(1.0f, 0.3f, 0.4f);
		drawTriangle(0,7,8);
		glColor3f(0.3f, 0.4f, 1.0f);
		drawTriangle(5,0,8);
	glEnd();
   glutSwapBuffers();  
}

int main(int argc, char** argv) {
	printf("Choose 0: CUBE  1: Pyramid\n");
	scanf("%d",&flag);
	if(flag!=0 && flag!=1)
		flag=0;
	printf("Enter sx,sy,sz\n");
	scanf("%f %f %f",&tx,&ty,&tz);

   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(1366, 768); 
    glutInitWindowPosition(0, 0);  // Position the window's initial top-left corner
   glutCreateWindow("3D Translation");          // Create window with the given title
  
  if(flag==0)
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   else
   glutDisplayFunc(display11);
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
