#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44
#define PI 3.1415926535898
#define janela_altura 800
#define janela_largura 1200

float tx1 = -140.0;
float tx2 = -140.0;
float tx3 = -140.0;
float tx4 = -140.0;
float xt = 0;
float yt = 0;
float vel1 = 2;
float vel2 = -1;
float vel3 = 1.5;
float vel4 = -1.5;
float c1f, c1b;
float c2f, c2b;
float c3f, c3b;
float c4f, c4b;

void anima(int valor);
void update(int valor); int interval = 1000 / 60;
void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard();

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitWindowSize(janela_largura, janela_altura);
	glutCreateWindow("Freeway");
	glutInitWindowPosition(0, 0);
	glutReshapeFunc(tela);
	glutTimerFunc(150, anima, 10);
	glutTimerFunc(50, update, 1);
	glutDisplayFunc(display);
	glutMainLoop();
	return(0);
}

void update(int valor) {
	keyboard();
	glutTimerFunc(interval, update, 0);
	glutPostRedisplay;
}


void anima(int valor) {

	tx1 += vel1;
	tx2 += vel2;
	tx3 += vel3;
	tx4 += vel4;

	if (tx1 >= 1600) {
		tx1 = -140;
	}

	if (tx2 <= -140) {
		tx2 = 1600;
	}

	if (tx3 >= 1600) {
		tx3 = -140;
	}

	if (tx4 <= -140) {
		tx4 = 1600;
	}

	if (yt >= 845) {
		yt = 0;
		xt = 0;
	}

	glutPostRedisplay();
	glutTimerFunc(1, anima, 1);

}

void verifica() {

	if (yt >= 84 && yt <= 202) {
		if (xt <= c1f && xt >= c1b + 20) {
			xt = 0;
			yt = 0;
		}
	}
	else if (yt >= 264 && yt <= 380) {
		if (xt <= c2f && xt >= c2b + 20) {
			xt = 0;
			yt = 0;
		}
	}
	else if (yt >= 448 && yt <= 570) {
		if (xt <= c3f + 80 && xt >= c3b) {
			xt = 0;
			yt = 0;
		}
	}
	else if (yt >= 636 && yt <= 756) {
		if (xt <= c4f + 80 && xt >= c4b) {
			xt = 0;
			yt = 0;
		}
	}
}

void carros() {

	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.1, 0.0);
	glVertex2f(-925 + tx1, 244);
	glVertex2f(-825 + tx1, 244);
	glVertex2f(-825 + tx1, 305);
	glVertex2f(-925 + tx1, 305);
	glEnd();

	c4f = (-825 + tx1);
	c4b = (-925 + tx1);

	glPopMatrix();

	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(-925 + tx3, 57);
	glVertex2f(-825 + tx3, 57);
	glVertex2f(-825 + tx3, 123);
	glVertex2f(-925 + tx3, 123);
	glEnd();

	c3f = (-825 + tx3);
	c3b = (-925 + tx3);

	glPopMatrix();

	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(-925 + tx4, -67);
	glVertex2f(-825 + tx4, -67);
	glVertex2f(-825 + tx4, -128);
	glVertex2f(-925 + tx4, -128);
	glEnd();

	c2f = (-825 + tx4);
	c2b = (-925 + tx4);

	glPopMatrix();

	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(-925 + tx2, -249);
	glVertex2f(-825 + tx2, -249);
	glVertex2f(-825 + tx2, -310);
	glVertex2f(-925 + tx2, -310);
	glEnd();

	c1f = (-825 + tx2);
	c1b = (-925 + tx2);

	glPopMatrix();
}

void cenario() {

	int x = 0;

	for (int i = 0; i <= 19; i++) {
		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(-925 + x, 5);
		glVertex2f(-1000 + x, 5);
		glVertex2f(-1000 + x, -10);
		glVertex2f(-925 + x, -10);
		glEnd();

		x += 100;
	}

	x = 0;

	for (int i = 0; i <= 19; i++) {
		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(-925 + x, 180);
		glVertex2f(-1000 + x, 180);
		glVertex2f(-1000 + x, 187);
		glVertex2f(-925 + x, 187);
		glEnd();

		x += 100;
	}

	x = 0;

	for (int i = 0; i <= 19; i++) {
		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(-925 + x, -185);
		glVertex2f(-1000 + x, -185);
		glVertex2f(-1000 + x, -192);
		glVertex2f(-925 + x, -192);
		glEnd();

		x += 100;
	}

	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex2f(1000, 362);
	glVertex2f(1000, 450);
	glVertex2f(-1000, 450);
	glVertex2f(-1000, 362);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex2f(1000, -500);
	glVertex2f(1000, -367);
	glVertex2f(-1000, -367);
	glVertex2f(-1000, -500);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(-20 + xt, -445 + yt);
	glVertex2f(-20 + xt, -385 + yt);
	glVertex2f(-80 + xt, -385 + yt);
	glVertex2f(-80 + xt, -445 + yt);
	glEnd();

}

void keyboard() {

	if (GetAsyncKeyState(VK_W)) {
		yt += 4;
	}

	if (GetAsyncKeyState(VK_A)) {
		if (xt >= -910) {
			xt -= 4;
		}

	}

	if (GetAsyncKeyState(VK_S)) {
		if (yt >= -20) {
			yt -= 4;
		}

	}

	if (GetAsyncKeyState(VK_D)) {
		if (xt <= 610) {
			xt += 4;
		}

	}

}

void display() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);

	verifica();
	cenario();
	carros();

	glFlush();
}

void tela(GLsizei w, GLsizei h) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}