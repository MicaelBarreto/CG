#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define janela_altura 480
#define janela_largura 640
int on = 1;
float x = 0.0, y = 0.0, z = 0.0;
void reshape(GLsizei largura, GLsizei altura);
void display();
void keyboard(unsigned char key, int a, int b);
void luz_esfera();
void luz_cubo();

float i = 30.0;

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // Ligar GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Display com Duplo Buffer
	glutInitWindowSize(janela_largura, janela_altura); // tamanho da janela
	glutInitWindowPosition(50, 50); // Pos. onde surge a janela
	glutCreateWindow("ilum"); // Criar Janela
	luz_esfera();
	luz_cubo();
	glutDisplayFunc(display); // imagem
	glutReshapeFunc(reshape); // config telas
	glutKeyboardFunc(keyboard); // funcoes de teclado
	glutMainLoop(); // loop
	return 0;
}
void luz_esfera(void)
{
	float ambiente[] = { 0.0, 0.0, 0.0, 1.0 };
	float diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	float position[] = { 0.0 + sin(x * 2 * 3.14 / 360), 3.0, 2.0 + sin(x * 2 * 3.14 / 360), 0.0 };
	float lmodel_ambiente[] = { 0.4, 0.4, 0.4, 1.0 };
	float local_view[] = { 0.0 };
	glClearColor(0.1, 0.5, 0.5, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambiente);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void luz_cubo(void)
{
	float ambiente[] = { 0.0, 0.0, 0.0, 1.0 };
	float diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	float position[] = { 5.0 + sin(x * 2 * 3.14 / 360), 3.0, 2.0 + sin(x * 2 * 3.14 / 360), 0.0 };
	float lmodel_ambiente[] = { 0.4, 0.4, 0.4, 1.0 };
	float local_view[] = { 0.0 };
	glClearColor(0.1, 0.5, 0.5, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambiente);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}



void reshape(GLsizei largura, GLsizei altura)
{
	if (altura == 0) altura = 1; // previne a divis�o por zero
	GLfloat aspecto = (GLfloat)largura / (GLfloat)altura;
	glViewport(0, 0, largura, altura);
	glMatrixMode(GL_PROJECTION); // manipulando matriz de proje��o
	glLoadIdentity(); // zerando a matriz
	gluPerspective(45.0f, aspecto, 0.1f, 100.0f);
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // configura fundo sem transparencia
	glEnable(GL_DEPTH_TEST); // alunos devem testar
	glShadeModel(GL_SMOOTH); // acabamento com suaviza��o
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // correcao de perspectiva
}

void display()
{
	float inicial[] = { 0.0, 0.0, 0.0, 1.0 };
	float ambiente[] = { 1.7, 0.7, 0.7, 1.0 };
	float diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
	float spec[] = { 1.0, 1.0, 1.0, 1.0 };
	float brilho[] = { i };
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // executa a limpeza
	glMatrixMode(GL_MODELVIEW); // operando com a camera de modelos

	glLoadIdentity();
	glTranslatef(-1.5f, 0.0f, -6.0f); // posiciona a piramide
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambiente);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
	glMaterialfv(GL_FRONT, GL_SHININESS, brilho);
	glMaterialfv(GL_FRONT, GL_EMISSION, inicial);


	glColor3d(1.0, 0.5, 1.0);
	glutSolidCube(1.5);

	glPushMatrix();
	glTranslated(3, 0, 0);
	glutSolidSphere(1, 55, 55);

	glutSwapBuffers();
}
void keyboard(unsigned char key, int a, int b)
{
	switch (key)
	{
	case 'e':
	{
		x += 10.0;
		luz_esfera();

		glutPostRedisplay();
	} break;
	case '3':
	{
		if (on)
		{

			glDisable(GL_LIGHT0);
			on = 0;
		}
		else
		{

			glEnable(GL_LIGHT0);
			on = 1;
		}
		glutPostRedisplay();
	} break;
	case 'w':
	{
		if (i != 0) {
			i -= 2.0;
		}
		glutPostRedisplay();
	} break;
	case 's':
	{
		if (i != 26.0) {
			i += 2.0;
		}
		glutPostRedisplay();
	} break;
	}
}