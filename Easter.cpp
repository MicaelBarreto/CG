#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define janela_largura 1200
#define janela_altura 900
#define PI 3.1415926535898

void tela(GLsizei w, GLsizei h);
void display(void);


int main(int argc, char** argv)
{
	glutInit(&argc, argv);  // controla se o sistema operacional tem suporte a janelas.

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // quantidade de buffer de cores e que o padrao de cores é RGB ou RGBA

	glutInitWindowSize(janela_largura, janela_altura);  // tamanho da janela

								   //glutFullScreen();  // full screen

	glutInitWindowPosition(200, 100); // posicao inicial da janela

	glutCreateWindow("Ovo");   /// cria a janela

	glutReshapeFunc(tela); // 

	glutDisplayFunc(display);
	glutMainLoop();

	return (0);
}

void desenhar() {
	GLfloat circ_pnt = 600;
	GLfloat ang, raioX = 40.0f, raioY = 80.0f;
	glPushMatrix();

	//Ovo de Pascoa 1
	glTranslatef(200, (-100), 0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI*i) / circ_pnt;
		glVertex2f(-(cos(ang)*(raioX+10)), -(sin(ang)*(raioY+10)));
	}
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 85);
	glVertex2f((-70), 180);
	glVertex2f(70, 180);
	glEnd();

	//Ovo de Pascoa 2
	glTranslatef(200, 0, 0);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 85);
	glVertex2f((-70), 180);
	glVertex2f(70, 180);
	glEnd();

	//Laços
	glTranslatef(0, 85, 0);
	raioX = 0.2f, raioY = 0.2f;
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(40, 40);
	glVertex2f(40, (-40));
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f((-40), 40);
	glVertex2f((-40), (-40));
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();

	glTranslatef((-200), 0, 0);
	raioX = 0.2f, raioY = 0.2f;
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(40, 40);
	glVertex2f(40, (-40));
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f((-40), 40);
	glVertex2f((-40), (-40));
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(0, 0);
	glVertex2f(5, 10);
	glVertex2f(3, 8);
	glVertex2f(6, 9);
	glVertex2f(0, 0);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();


	//Corpo Coelho
	glPopMatrix();
	glTranslatef((-150), (-100), 0);
	raioX = 100.0f, raioY = 160.0f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	raioX = 80.0f, raioY = 120.0f;
	glColor3f(1.0, 0.75, 0.79);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	
	//Cabeça Coelho
	glTranslatef(0, 250, 0);
	raioX = 80.0f, raioY = 80.0f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	glTranslatef(0, (-20), 0);
	raioX = 100.0f, raioY = 60.0f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	//Nariz/Focinho
	raioX = 15.0f, raioY = 15.0f;
	glColor3f(1.0, 0.1, 0.1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < ((circ_pnt / 2) + 1); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	glTranslatef(20, (-25), 0);
	raioX = 10.0f, raioY = 5.0f;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < ((circ_pnt/2)+1); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	glTranslatef((-40), 0, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < ((circ_pnt / 2) + 1); i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	//Olhos
	glTranslatef((-10),65, 0);
	raioX = 2.0f, raioY = 6.0f;
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	glTranslatef(60, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	//Orelhas
	glTranslatef(20, 100, 0);
	raioX = 15.0f, raioY = 80.0f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	glColor3f(1.0, 0.75, 0.79);
	raioX = 5.0f, raioY = 40.0f;
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	glTranslatef((-100),0 , 0);
	raioX = 15.0f, raioY = 80.0f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	glColor3f(1.0, 0.75, 0.79);
	raioX = 5.0f, raioY = 40.0f;
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	//Patas
	glTranslatef((-20), (-490), 0);
	raioX = 30.0f, raioY = 60.0f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	glPushMatrix();

	glTranslatef(0, (-10), 0);
	glColor3f(1.0, 0.75, 0.79);
	raioX = 15.0f, raioY = 25.0f;
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();

	glPopMatrix();
	glTranslatef(130, 0, 0);
	raioX = 30.0f, raioY = 60.0f;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();
	glPushMatrix();

	glTranslatef(0, (-10), 0);
	glColor3f(1.0, 0.75, 0.79);
	raioX = 15.0f, raioY = 25.0f;
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * PI * i) / circ_pnt;
		glVertex2f(-(cos(ang) * (raioX + 10)), -(sin(ang) * (raioY + 10)));
	}
	glEnd();

}

void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.3f, 0.3f, 1.0f, 0.5f);  // cor do fundo

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