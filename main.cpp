// #include <windows.h>  // for MS Windows
// #include <GL/freeglut.h>  // GLUT, include glu.h and gl.h
#include "main.h"
// #include <GL/glx.h> /* this includes the necessary X headers /

/* Global variables */
char title[] = "OpenGL-PUC PR";
GLfloat nRange = 200;

/* Initialize OpenGL Graphics */
void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_FLAT);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

/* Handler for window-repaint event. Called back when the window first appears and
whenever the window needs to be re-painted. */
void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
	glLoadIdentity();                  // Reset the model-view matrix

	glRotatef(45.0f, 1,1,1);
	cubo(100);

	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

/* Handler for window re-size event. Called back when the window first appears and
whenever the window is re-sized with its new width and height */
void reshape(GLsizei w, GLsizei h) {
	if (h == 0) h = 1;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
		glOrtho(-nRange, nRange, -nRange * h / w, nRange*h / w, -nRange, nRange);
	else
		glOrtho(-nRange * w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(640, 480);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow(title);          // Create window with the given title
	glutDisplayFunc(render);          // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);         // Register callback handler for window re-size event
	initGL();                         // Our own OpenGL initialization
	glutMainLoop();                    // Enter the infinite event-processing loop
	return 0;
}

void cubo(float a) {
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.0, 0.1, 0.5);
    glVertex3f(-a / 2, a / 2, a / 2);
    glVertex3f(-a / 2, -a / 2, a / 2);
    glVertex3f(a / 2, a / 2, a / 2);
    glVertex3f(a / 2, -a / 2, a / 2);
    glVertex3f(a / 2, a / 2, -a / 2);
    glColor3f(0.5, 0.1, 0.5);
    glVertex3f(a / 2, -a / 2, -a / 2);
    glVertex3f(-a / 2, a / 2, -a / 2);
    glVertex3f(-a / 2, -a / 2, -a / 2);
    glVertex3f(-a / 2, a / 2, a / 2);
    glVertex3f(-a / 2, -a / 2, a / 2);
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(-a / 2, a / 2, -a / 2);
    glVertex3f(-a / 2, a / 2, a / 2);
    glVertex3f(a / 2, a / 2, -a / 2);
    glVertex3f(a / 2, a / 2, a / 2);
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(a / 2, -a / 2, -a / 2);
    glVertex3f(a / 2, -a / 2, a / 2);
    glVertex3f(-a / 2, -a / 2, -a / 2);
    glVertex3f(-a / 2, -a / 2, a / 2);
    glEnd();
}
