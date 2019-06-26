#include<GL/glew.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#define windowH 400
#define windowW 600
#define PI 3.1415926535898

//translation variables
float tx = 0.0;
float ty = 0.0;

//variables incrementation
float xStep = 8;
float yStep = 4;

void display(void);
void screen(GLsizei w, GLsizei h);
void keyboard(unsigned char key, int x, int y);
void anim(int value);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(windowW, windowH);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Animation Test");

	glutReshapeFunc(screen);
	glutDisplayFunc(display);
	glutKeyboardFunc(&keyboard);
	glutTimerFunc(1500, anim, 1);
	glutMainLoop();

	return(0);
}

void anim(int value) {
	int aleatorio = rand() % 179;
	glRotated(-aleatorio, 0, 0, 1);

	/*if (aleatorio) {

	}else if () {

	}else if () {

	}else if() {

	}*/

	if ((tx)>(300) || (tx) < (-300)) {
		xStep = -xStep;
	}
	if ((ty)>(150) || (ty) < (-150)) {
		yStep = -yStep;
	}
	tx += xStep;
	ty += yStep;

	printf("\n Top %.2f \t Bottom %.2f \t Right %.2f \t Left %.2f", ((windowH) / 2), (((windowH) / 2) - 1), ((windowW) / 2), (((windowW) / 2) - 1));
	printf("\n Step X %.2f Step Y %.2f", xStep, yStep);
	printf("\n TX %.2f TY %.2f", tx, ty);

	glutPostRedisplay();
	glutTimerFunc(150, anim, 1);
}

void keyboard(unsigned char key, int x, int y) {
	printf("\n Key %c", key);
	printf("\n1-Translate X\n2-Translate Y\nEnter: ");
	printf("\nKey %c", key);
	printf("\n Mouse position: %d x %d", x, y);
}

void draw() {
	GLfloat circ_pnt = 600;
    GLfloat ang, raioX = 25.0f, raioY = 5.0f;

	glLoadIdentity();
	glTranslatef((windowW) / 2, (windowH) / 2, 0);
	glTranslatef(tx, ty, 0);


	glColor3f(255, 215, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();


	glBegin(GL_TRIANGLES);
	glVertex2f(-25, 0);
	glVertex2f(-60, 25);
	glVertex2f(-60, -25);
	glEnd();
}

void display() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0, 0, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0, 0, windowW, windowH);
	draw();

	glFlush();
}

void screen(GLsizei w, GLsizei h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, windowW, 0, windowH);
	glMatrixMode(GL_MODELVIEW);
}