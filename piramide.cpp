#include<GL/glew.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

#define janela_altura 800
#define janela_largura 1024

double rotacao_x = 0;
double rotacao_y = 0;

void reshape(GLsizei w, GLsizei h);
void display();

void keyboard(unsigned char key, int a, int b) {
	if (key == 'w') {
		rotacao_x += 10;
	}
	else if (key == 's') {
		rotacao_x -= 10;
	}
	else if (key == 'd') {
		rotacao_y += 10;
	}
	else if (key == 'a') {
		rotacao_y -= 10;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(janela_largura, janela_altura);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("piramide e cubo 3D");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

void reshape(GLsizei w, GLsizei h) {
	if (h == 0) h = 1;
	GLfloat aspect = (GLfloat)w / (GLfloat)h;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(30.0f, aspect, 0.1f, 100.0f);

	glClearColor(0.2, 0.5, 0.5, 1);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);


	glLoadIdentity();
	glTranslatef(-1.0f, 0.0f, -6.0f);

	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0.6, 0);
	glVertex3f(-0.6, -0.6, 0.6);
	glVertex3f(0.6, -0.6, 0.6);
	glColor3f(0, 1, 0);
	glVertex3f(0, 0.6, 0);
	glVertex3f(0.6, -0.6, 0.6);
	glVertex3f(0.6, -0.6, -0.6);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0.6, 0);
	glVertex3f(0.6, -0.6, -0.6);
	glVertex3f(-0.6, -0.6, -0.6);
	glColor3f(1, 1, 1);
	glVertex3f(0, 0.6, 0);
	glVertex3f(-0.6, -0.6, -0.6);
	glVertex3f(-0.6, -0.6, 0.6);
	glEnd();

	glTranslatef(4, 0, -6);
	glRotatef(rotacao_x, 1.0, 0.0, 0.0);
	glRotatef(rotacao_y, 0.0, 1.0, 0.0);

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex3f(0.6, -0.6, -0.6);
	glVertex3f(0.6, 0.6, -0.6);
	glVertex3f(-0.6, 0.6, -0.6);
	glVertex3f(-0.6, -0.6, -0.6);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(-0.6, -0.6, 0.6);
	glVertex3f(-0.6, 0.6, 0.6);
	glVertex3f(-0.6, 0.6, -0.6);
	glVertex3f(-0.6, -0.6, -0.6);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex3f(0.6, -0.6, 0.6);
	glVertex3f(0.6, 0.6, 0.6);
	glVertex3f(-0.6, 0.6, 0.6);
	glVertex3f(-0.6, -0.6, 0.6);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex3f(0.6, -0.6, -0.6);
	glVertex3f(0.6, 0.6, -0.6);
	glVertex3f(0.6, 0.6, 0.6);
	glVertex3f(0.6, -0.6, 0.6);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex3f(0.6, -0.6, -0.6);
	glVertex3f(0.6, -0.6, 0.6);
	glVertex3f(-0.6, -0.6, 0.6);
	glVertex3f(-0.6, -0.6, -0.6);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex3f(0.6, 0.6, 0.6);
	glVertex3f(0.6, 0.6, -0.6);
	glVertex3f(-0.6, 0.6, -0.6);
	glVertex3f(-0.6, 0.6, 0.6);
	glEnd();
	glFlush();
	glutSwapBuffers();
}