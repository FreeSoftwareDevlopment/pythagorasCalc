#pragma once
#ifndef GL_QUADS
#include <GLFW/glfw3.h>
#endif
#ifndef multi
#define multi 0.01f
#endif

void makequadxx(const float);

void makebackground() {
	glColor3f(0.0f, 1.0f, 1.0f);
	makequadxx(100.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	makequadxx(40.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	makequadxx(30.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	makequadxx(20.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	makequadxx(10.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	makequadxx(5.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	makequadxx(2.5f);
}

void makequadxx(const float size) {
	glBegin(GL_QUADS);
	glVertex2f(-1.0f * size * multi, -1.0f * size * multi);
	glVertex2f(1.0f * size * multi, -1.0f * size * multi);
	glVertex2f(1.0f * size * multi, 1.0f * size * multi);
	glVertex2f(-1.0f * size * multi, 1.0f * size * multi);
	glEnd();
}
