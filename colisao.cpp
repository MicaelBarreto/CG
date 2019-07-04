#include <stdio.h>
#include <stdlib.h> 
#include <GL/glut.h> 
#include<math.h>

#define janela_altura 800
#define janela_largura 1024

#define PI 3.1416

float xG = -400, yG = 0, hipotenusa;

void display(void);
void tela(GLsizei W, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);
float verifica();

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	// suporte a janelas 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // PADRAO DE CORES 
	glutInitWindowSize(janela_largura, janela_altura); // tamanho da janela 
	glutInitWindowPosition(0, 0); // posicao que surge a janela 
	glutCreateWindow("colisão de circulos"); // cria janela
	//glutFullscreen(); 
	glutKeyboardFunc(&keyboard); // chama teclado 
	glutReshapeFunc(tela); // configura a tela 
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar 
	return(0);
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 'a') {
		xG = xG - 10;
	}
	else if (key == 'd') {
		xG = xG + 10;
	}
	else if (key == 'w') {
		yG = yG + 10;
	}
	else if (key == 's') {
		yG = yG - 10;
	}

	glutPostRedisplay();
}

void desenhar()
{
	GLfloat circ_pnt = 500;
	GLfloat ang, raioX = 100.0f, raioY = 100.0f;

	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
	}
	glEnd();

	glTranslatef(xG, yG, 0);
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
	}
	glEnd();
	glutPostRedisplay();
}
void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	float distancia = verifica();

	if (distancia >= 200) {

		glClearColor(0.2, 0.5, 0.5, 1.0f);
	}
	else {

		glClearColor(1.0f, 0.2f, 0.2f, 1.0f);
	}

	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();
	glFlush();
	// execute o desenho 
}
void tela(GLsizei W, GLsizei h) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}

float verifica() {
	hipotenusa = sqrt((xG * xG) + (yG * yG));
	return  hipotenusa;
}