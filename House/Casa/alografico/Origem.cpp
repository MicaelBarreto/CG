#include <stdlib.h>
#include <GL/glut.h>


void keyboard(unsigned char key, int x, int y);
void resize(GLsizei w, GLsizei h);
void display(void);


int main(int argc, char** argv)
{
	glutInit(&argc, argv);  // controla se o sistema operacional tem suporte a janelas.

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // quantidade de buffer de cores e que o padrao de cores é RGB ou RGBA

	glutInitWindowSize(400, 400);  // tamanho da janela

								   //glutFullScreen();  // full screen

	glutInitWindowPosition(10, 300); // posicao inicial da janela

	glutCreateWindow("Casa");   /// cria a janela

	glutKeyboardFunc(&keyboard);

	glutReshapeFunc(&resize); // 

	glutDisplayFunc(display);

	glutMainLoop();

	return EXIT_SUCCESS;
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '\x1B':
		exit(EXIT_SUCCESS);
		break;
	}
}

void resize(GLsizei w, GLsizei h)
{

	if (h == 0) h = 1;  // Evita a divisao por zero

	glViewport(0, 0, w, h);  // Especifica as dimensões da Viewport

							 // Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (left, right, bottom, top)
	if (w <= h)
	{
		gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f*h / w);
	}
	else
	{
		gluOrtho2D(0.0f, 250.0f*w / h, 0.0f, 250.0f);
	}
	glMatrixMode(GL_MODELVIEW);


}

void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.30f, 0.30f, 1.0f, 1.0f);  // cor do fundo

	glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(125, 250);
	glVertex2f(50, 200);
	glVertex2f(200, 200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(50, 200);
	glVertex2f(200, 200);
	glVertex2f(200, 50);
	glVertex2f(50, 50);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.647f, 0.502f, 0.392f);
	glVertex2f(50, 100);
	glVertex2f(85, 100);
	glVertex2f(85, 50);
	glVertex2f(50, 50);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0, 0);
	glVertex2f(0, 50);
	glVertex2f(250, 50);
	glVertex2f(250, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.545f, 0.270f, 0.075f);
	glVertex2f(78, 70);
	glVertex2f(82, 70);
	glVertex2f(82, 74);
	glVertex2f(78, 74);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100, 125);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100, 165);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(140, 165);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(140, 125);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(105, 130);
	glVertex2f(105, 160);
	glVertex2f(135, 160);
	glVertex2f(135, 130);
	glEnd();

	//Trocar os quadrados da janela por gl_line_loop

	glFlush(); // executa o desenho
}