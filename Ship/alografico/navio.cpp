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

	glutCreateWindow("Pier");   /// cria a janela

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
	glClearColor(0.35f, 0.35f, 1.0f, 1.0f);  // cor do fundo

	glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo

	glBegin(GL_QUADS);
	glColor3f(0.2f, 0.2f, 1.0f);
	glVertex2f(0, 0);
	glVertex2f(0, 100);
	glVertex2f(175, 100);
	glVertex2f(175, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.54f, 0.27f, 0.07f);
	glVertex2f(175, 100);
	glVertex2f(220, 130);
	glVertex2f(220, 0);
	glVertex2f(175, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.54f, 0.27f, 0.07f);
	glVertex2f(220, 130);
	glVertex2f(250, 130);
	glVertex2f(250, 0);
	glVertex2f(220, 0);
	glEnd();

	glLineWidth(800.0f);
	glBegin(GL_LINES);
	glColor3f(0.87f, 0.72f, 0.52f);
	glVertex2f(220, 130);
	glVertex2f(130, 130);
	glEnd();

	glLineWidth(800.0f);
	glBegin(GL_LINES);
	glColor3f(0.87f, 0.72f, 0.52f);
	glVertex2f(132, 130);
	glVertex2f(132, 100);
	glEnd();

	glLineWidth(200.0f);
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(175, 100);
	glVertex2f(220, 130);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(220, 130);
	glVertex2f(250, 130);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.54f, 0.27f, 0.07f);
	glVertex2f(230, 133);
	glVertex2f(240, 133);
	glVertex2f(240, 180);
	glVertex2f(230, 180);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.00f);
	glVertex2f(220, 180);
	glVertex2f(250, 180);
	glVertex2f(235, 230);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.15f, 0.15f);
	glVertex2f(125, 130);
	glVertex2f(5, 130);
	glVertex2f(25, 100);
	glVertex2f(105, 100);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.75f, 0.75f, 0.75f);
	glVertex2f(15, 130);
	glVertex2f(15, 150);
	glVertex2f(85, 150);
	glVertex2f(85, 130);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.41f, 0.41f, 0.41f);
	glVertex2f(55, 150);
	glVertex2f(55, 180);
	glVertex2f(70, 180);
	glVertex2f(70, 150);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.54f, 0.27f, 0.07f);
	glVertex2f(84, 150);
	glVertex2f(84, 175);
	glVertex2f(85, 175);
	glVertex2f(85, 150);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.8f);
	glVertex2f(85, 175);
	glVertex2f(100, 175);
	glVertex2f(100, 165);
	glVertex2f(85, 165);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(85, 169.5f);
	glVertex2f(100, 169.5f);
	glVertex2f(100, 170.5f);
	glVertex2f(85, 170.5f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(92, 175);
	glVertex2f(93, 175);
	glVertex2f(93, 165);
	glVertex2f(92, 165);
	glEnd();


	/*glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100, 125);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(100, 165);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(140, 165);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(140, 125);
	glEnd();*/

	glFlush(); // executa o desenho
}