#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898
#define janela_altura 500
#define janela_largura 800
GLfloat  circ_pnt = 500;
GLfloat  ang, raioX = 200.0f, raioY = 200.0f;

float tx = 0.0;
float ty = 0.0;
float xStep = 4;
float yStep = 4;
float x = 0;
float r = 1;
float g = 0.9;
float b = 0;

void anima(int valor);
void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(janela_largura, janela_altura);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Aquário");
	glutReshapeFunc(tela);
	glutKeyboardFunc(&keyboard);
	glutTimerFunc(150, anima, 10);
	glutDisplayFunc(display);
	glutMainLoop();
	return(0);
}


void anima(int valor) {

	if ((tx) > (120)) {
		xStep = -xStep;
		x = 1;
	}

	if ((tx) < (-120)) {
		xStep = -xStep;
		x = 0;
	}

	if ((ty) > (10) || (ty) < (-30)) {
		yStep = -yStep;
	}

	ty += yStep;
	tx += xStep;

	glutPostRedisplay();
	glutTimerFunc(95, anima, 1);
}

void aquario() {
	glTranslatef(0, 60, 0);
	glRotatef(180, 0, 0, 0);
	glRotatef(0, 0, 0, 0);
	glColor3f(0.2, 0.2, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < (circ_pnt / 2); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
	}
	glEnd();

	glTranslated(tx, (ty + 60), 0);
	glRotatef(180.0, 0.0, 0.0, 1.0);

	if (x == 1) {
		glRotatef(180.0, 0.0, 1.0, 0.0);
	}
	GLfloat circ_pnt = 600;
	GLfloat ang, raioX = 25.0f, raioY = 5.0f;
	glRotatef(0, 0, 0, 0);
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();


	glBegin(GL_TRIANGLES);
	glVertex2f(25, 0);
	glVertex2f(60, -25);
	glVertex2f(60, 25);
	glEnd();


}

void keyboard(unsigned char key, int x, int y) {
	if (key == 'a') {
		r = 1;
		g = 0;
		b = 1;
	}
	else if (key == 'd') {
		r = 1;
		g = 1;
		b = 0;
	}
	else if (key == 'w') {
		r = 0;
		g = 1;
		b = 1;
	}
	else if (key == 's') {
		r = 1;
		g = 1;
		b = 1;
	}

	glutPostRedisplay();
}

void display() {

	glMatrixMode(GL_MODELVIEW); //coordenadas
	glLoadIdentity();

	glClearColor(0.2, 0.5, 0.5, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//colocar o desenho no meio da janela:
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);

	aquario();

	glFlush();
}

void tela(GLsizei w, GLsizei h) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}