#include <stdio.h>
#include <stdlib.h> 
#include <GL/glut.h> 
#include<math.h>
#define janela_altura 600 
#define janela_largura 800 
#define PI 3.1416
#define VK_W 0x57
#define VK_S 0x53

//Funções
void keyboard();
void update(int val);
void anima(int val);
void display(void);
void tela(GLsizei W, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);
bool esquerda(float aX, float aY, float bX, float bY, float bAlt, float bComp);
bool direita(float aX, float aY, float bX, float bY, float bAlt, float bComp);
bool cima(float aY, float bY, float bAlt);
bool baixo(float aY, float bY, float bAlt);


int intervalo = 1000 / 60;

//Movimento da bola
float tx, ty = 0.0;
float xTep = 4;
float yTep = 1;

//Informações iniciais do player 1
float x1 = -380;
float yp1 = 50;
float largura1 = 20;
float altura1 = -100;
int score1 = 0;

//Informações iniciais do player 2
float x2 = 380;
float y2 = 50;
float largura2 = -20;
float altura2 = -100;
int score2 = 0;

//Paredes
float Tx = -400;
float Ty = 280;
float Tcomp = 800;
float Talt = -20;
float Cx = -400;
float Cy = -280;
float Ccomp = 800;
float Calt = 20;


int main(int argc, char** argv) {

	glutInit(&argc, argv);
	// suporte a janelas 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // PADRAO DE CORES 
	glutInitWindowSize(janela_largura, janela_altura); // tamanho da janela 
	glutInitWindowPosition(0, 0); // posicao que surge a janela 
	glutCreateWindow("Pong"); // cria janela 
	glutTimerFunc(150, anima, 1);
	glutTimerFunc(250, update, 1);
	//glutKeyboardFunc(&keyboard); // chama teclado 
	glutReshapeFunc(tela); // configura a tela 
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar 
	return(0);
}

void update(int value) {

	keyboard();
	glutTimerFunc(intervalo, update, 0);
	glutPostRedisplay();
}

void anima(int valor) {
	float a = tx;
	float b = ty;
	bool e = esquerda(a, b, x1, yp1, largura1, altura1);
	bool d = direita(a, b, x2, y2, largura2, altura2);
	bool c = cima(b, Ty, Tcomp);
	bool ba = baixo(b, Cy, Ccomp);

	if (e == true) {
		xTep = -xTep;
		yTep = yTep;
	}

	if (d == true) {
		xTep = -xTep;
		yTep = yTep;
	}

	if (c == true) {
		xTep = xTep;
		yTep = -yTep;
	}

	if (ba == true) {
		xTep = xTep;
		yTep = -yTep;
	}

	if (a > 390) {
		tx = 0;
		ty = 0;
		score2++;
	}
	else if (a < -390) {
		tx = 0;
		ty = 0;
		score1++;
	}

	if (score1 == 3 || score2 == 3) {
		Sleep(1000);
		exit(0);
	}

	ty += yTep;
	tx += xTep;
	glutPostRedisplay();
	glutTimerFunc(15, anima, 2);

}

void keyboard() {
	if (GetAsyncKeyState(VK_W)) {
		if (yp1 < 260) {
			yp1 += 5;
		}
	}
	if (GetAsyncKeyState(VK_S)) {
		if (yp1 > -160) {
			yp1 -= 5;
		}
	}

	if (GetAsyncKeyState(VK_UP)) {
		if (y2 < 260) {
			y2 += 5;
		}
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		if (y2 > -160) {
			y2 -= 5;
		}
	}
}

void cenario() {
	glBegin(GL_QUADS);
	glColor3f(0.2, 0.5, 0.5);
	glVertex2f(Tx, Ty + 100);
	glVertex2f(Tx + Tcomp, Ty + 100);
	glVertex2f(Tx + Tcomp, Ty + Talt);
	glVertex2f(Tx, Ty + Talt);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.2, 0.5, 0.5);
	glVertex2f(Cx, Cy + 100);
	glVertex2f(Cx + Ccomp, Cy + 100);
	glVertex2f(Cx + Ccomp, Cy + Calt);
	glVertex2f(Cx, Cy + Calt);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.2, 0.5, 0.5);
	glVertex2f(-5, 280);
	glVertex2f(5, 280);
	glVertex2f(5, -260);
	glVertex2f(-5, -260);
	glEnd();

	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(0.2, 0.5, 0.5);
	glVertex2f(x1, yp1);
	glVertex2f(x1 + largura1, yp1);
	glVertex2f(x1 + largura1, yp1 + altura1);
	glVertex2f(x1, yp1 + altura1);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(0.2, 0.5, 0.5);
	glVertex2f(x2, y2);
	glVertex2f(x2 + largura2, y2);
	glVertex2f(x2 + largura2, y2 + altura2);
	glVertex2f(x2, y2 + altura2);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	GLfloat circ_pnt = 500;
	GLfloat ang, raioX = 10.0f, raioY = 10.0f;

	glTranslatef(tx, ty, 0);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang)*raioX, sin(ang)*raioY);
	}
	glEnd();

	glPopMatrix();
}

void placar1() {

	if (score1 == 0)
	{
		glBegin(GL_LINE_LOOP);
		glLineWidth(50);
		glColor3f(0.2, 0.5, 0.5);
		glVertex2f(50, 230);
		glVertex2f(80, 230);
		glVertex2f(80, 170);
		glVertex2f(50, 170);
		glEnd();
	}
	else if (score1 == 1)
	{
		glBegin(GL_LINE_STRIP);
		glLineWidth(50);
		glColor3f(0.2, 0.5, 0.5);
		glVertex2f(60, 200);
		glVertex2f(80, 230);
		glVertex2f(80, 170);
		glEnd();
	}
	else if (score1 == 2)
	{
		glBegin(GL_LINE_STRIP);
		glLineWidth(50);
		glColor3f(0.2, 0.5, 0.5);
		glVertex2f(50, 230);
		glVertex2f(80, 230);
		glVertex2f(80, 200);
		glVertex2f(50, 200);
		glVertex2f(50, 170);
		glVertex2f(80, 170);
		glEnd();
	}
	else if (score1 == 3)
	{
		glBegin(GL_LINE_STRIP);
		glLineWidth(50);
		glColor3f(0.2, 0.5, 0.5);
		glVertex2f(50, 230);
		glVertex2f(80, 230);
		glVertex2f(80, 200);
		glVertex2f(50, 200);
		glVertex2f(80, 200);
		glVertex2f(80, 170);
		glVertex2f(50, 170);
		glEnd();
	}
}
void placar2() {

	if (score2 == 0)
	{
		glBegin(GL_LINE_LOOP);
		glLineWidth(50);
		glColor3f(0.2, 0.5, 0.5);
		glVertex2f(-80, 230);
		glVertex2f(-50, 230);
		glVertex2f(-50, 170);
		glVertex2f(-80, 170);
		glEnd();
	}
	else if (score2 == 1)
	{
		glBegin(GL_LINE_STRIP);
		glLineWidth(50);
		glColor3f(0.2, 0.5, 0.5);
		glVertex2f(-80, 200);
		glVertex2f(-60, 230);
		glVertex2f(-60, 170);
		glEnd();
	}
	else if (score2 == 2)
	{
		glBegin(GL_LINE_STRIP);
		glLineWidth(50);
		glColor3f(0.2, 0.5, 0.5);
		glVertex2f(-80, 230);
		glVertex2f(-50, 230);
		glVertex2f(-50, 200);
		glVertex2f(-80, 200);
		glVertex2f(-80, 170);
		glVertex2f(-50, 170);
		glEnd();
	}
	else if (score2 == 3)
	{
		glBegin(GL_LINE_STRIP);
		glLineWidth(50);
		glColor3f(0.2, 0.5, 0.5);
		glVertex2f(-80, 230);
		glVertex2f(-50, 230);
		glVertex2f(-50, 200);
		glVertex2f(-80, 200);
		glVertex2f(-50, 200);
		glVertex2f(-50, 170);
		glVertex2f(-80, 170);
		glEnd();
	}
}
void desenhar()
{
	cenario();
	placar1();
	placar2();

}
void display()
{

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0, 0, 0, 1);

	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();
	glFlush();
}
void tela(GLsizei W, GLsizei h) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}

bool esquerda(float aX, float aY, float bX, float bY, float bComp, float bAlt) {

	if (aX > bY) {
		return false;
	}
	else if (aY < bY + bAlt) {
		return false;
	}
	else if (aX > bX + bComp) {
		return false;
	}

	return true;
}

bool direita(float aX, float aY, float bX, float bY, float bComp, float bAlt) {

	if (aY > bY) {
		return false;
	}
	else if (aY < (bY + bAlt)) {
		return false;
	}
	else if (aX < (bX + bComp)) {
		return false;
	}

	return true;
}

bool cima(float aY, float bY, float bAlt) {

	if (aY < (bY + bAlt)) {
		return false;
	}

	return true;
}

bool baixo(float aY, float bY, float bAlt) {

	if (aY >(bY + bAlt)) {
		return false;
	}

	return true;
}