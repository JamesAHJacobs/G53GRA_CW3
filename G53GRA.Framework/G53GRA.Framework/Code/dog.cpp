#include "Dog.h"



Dog::Dog() : xrot(0.0f), yrot(0.0f), zrot(0.0f), scale(0.5f){}


void Dog::Display()
{
	glClearColor(1.f, 1.f, 1.f, 1.f);

	glPushMatrix();

	glTranslatef(0.0f, 0.0f, 0.0f);

	//glRotatef(zrot, 0.0f, 0.0f, 1.0f);
	//glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	//glRotatef(xrot, 1.0f, 0.0f, 0.0f);

	//glScalef(0.5f, scale, 0.5f);

	glDisable(GL_CULL_FACE);

	//glBegin(GL_TRIANGLES);

	//glColor3ub(255, 0, 0); 
	//glVertex3d(static_cast<float>(-Scene::GetWindowWidth()) / 3.0f, -Scene::GetWindowHeight() / 4.0f, -2.0);

	//glColor3f(0.0f, 1.0f, 0.0f);
	//glVertex3d(static_cast<float>(Scene::GetWindowWidth()) / 3.0f, -Scene::GetWindowHeight() / 4.0f, -2.0f);

	//glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	//glVertex3d(0.0, Scene::GetWindowHeight() / 3.0f, -2.0f);

	//glEnd();

	Body();

	glEnable(GL_CULL_FACE);

	glPopMatrix();
}

void Dog::Body()
{
	//glClearColor(1.f, 1.f, 1.f, 1.f);                   // set background colour
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear buffers
	glMatrixMode(GL_MODELVIEW);                         // set for model and viewing operations
	glLoadIdentity();                                   // reset drawing

	glTranslatef(0.f, 0.f, -100.f);                     // move drawing further back in the scene
	glColor3f(0.f, 0.f, 0.f);                           // set draw colour to black
	glutWireCube(10.f);                                 // draw outlined cube

	//checkGLError();
	glutSwapBuffers();                                  // execute all commands, swap buffers
}

/*void Dog::Legs()
{

}

void Dog::SubLegs()
{

}

void Dog::Head()
{

}

void Dog::Tail()
{

}*/

void Dog::Update(const double& deltaTime)
{
	zrot += 10.0f * static_cast<float>(deltaTime);
}

void Dog::HandleKey(unsigned char key, int state, int x, int y)
{
	switch (key)
	{
	case 'i':
		scale += 0.1f;
		break;
	case 'k':
		scale -= 0.1f;
		break;
	default:
		break;
	}
}

