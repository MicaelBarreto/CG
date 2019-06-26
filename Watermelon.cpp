#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define janela_largura 600
#define janela_altura 400
#define PI 3.1415926535898
float rotacao = 1;
float zoom = 1;
float trans = 1;

void tela(GLsizei w, GLsizei h);
void display(void);
void keyboard(unsigned char tecla, int x, int y);


int main(int argc, char** argv)
{
	glutInit(&argc, argv);  // controla se o sistema operacional tem suporte a janelas.

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // quantidade de buffer de cores e que o padrao de cores é RGB ou RGBA

	glutInitWindowSize(janela_largura, janela_altura);  // tamanho da janela

								   //glutFullScreen();  // full screen

	glutInitWindowPosition(100, 100); // posicao inicial da janela

	glutCreateWindow("Ovo");   /// cria a janela

	glutReshapeFunc(tela); // 

	glutDisplayFunc(display);
	glutKeyboardFunc(&keyboard);
	glutMainLoop();

	return (0);
}

void keyboard(unsigned char tecla, int x, int y) {
	if (tecla == 'q') {
		rotacao = rotacao + 1;
	}

	if (tecla == 'e') {
		rotacao = rotacao - 1;
	}

	if (tecla == 'w') {
		zoom = zoom + 0.5;
	}

	if (tecla == 's') {
		zoom = zoom - 0.5;
	}

	if (tecla == 'd') {
		trans = trans + 1;
	}

	if (tecla == 'a') {
		trans = trans - 1;
	}

	glutPostRedisplay();
}

void desenhar() {
	GLfloat circ_pnt = 600;
	GLfloat ang, raioX = 80.0f, raioY = 80.0f;

	glRotated(-rotacao, 0, 0, 1);
	glScalef(zoom, zoom, 0);
	glTranslatef(trans, trans, 0);

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < ((circ_pnt / 2)+1); i++) {
		ang = (2 * PI*i) / circ_pnt;
		glVertex2f(-(cos(ang)*(raioX+10)), -(sin(ang)*(raioY+10)));
		printf("%f\n  %f\n\n", cos(ang)*raioX, sin(ang)*raioY);
	}
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < ((circ_pnt / 2) + 1); i++) {
		ang = (2 * PI*i) / circ_pnt;
		glVertex2f(-(cos(ang)*raioX), -(sin(ang)*raioY));
		printf("%f\n  %f\n\n", cos(ang)*raioX, sin(ang)*raioY);
	}
	glEnd();
}

void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);  // cor do fundo

	glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo

	glTranslatef(janela_largura/2, janela_altura/2, 0.0f);

	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();
	glFlush(); // executa o desenho
}

void tela(GLsizei w, GLsizei h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	gluOrtho2D(0,janela_largura, 0, janela_altura);

	glMatrixMode(GL_MODELVIEW);

}