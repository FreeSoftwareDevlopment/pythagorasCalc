int windowBuilder(bool* windowclosed, bool* doexit) {
	GLFWwindow* window;
	if (!glfwInit()) {
		std::cerr << "Error in OPENGL Init" << std::endl;
		*windowclosed = true;
		return -1;
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Pythagoras Calc Visualisation", NULL, NULL);
	if (!window)
	{
		std::cerr << "Teminate" << std::endl;
		glfwTerminate();
		*windowclosed = true;
		return -1;
	}
	glfwMakeContextCurrent(window);
	integertrans currentrender;
	currentrender.content = false;
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		/* Render here */
		if (trasfer.ids > currentrender.ids && trasfer.content) {
			currentrender.ids = trasfer.ids;
			currentrender.a = trasfer.a;
			currentrender.b = trasfer.b;
			currentrender.content = true;
		}
		if (currentrender.content) {
			glColor3f(0.0f, 1.0f, 0.5f);
			glBegin(GL_TRIANGLES);
			glVertex2f(currentrender.a.x, currentrender.a.y);
			glVertex2f(currentrender.b.x, currentrender.b.y);
			glVertex2f(currentrender.a.x, currentrender.b.y);
			glEnd();
		}
		else {
			glColor3f(1.0f, 0.0f, 0.0f);
			glBegin(GL_TRIANGLES);
			glVertex2f(0.0f, 0.0f);
			glVertex2f(4.0f, 4.0f);
			glVertex2f(4.0f, 0.0f);
			glVertex2f(0.0f, 4.0f);
			glEnd();
		}
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
		if (*doexit) { break; }
	}
	std::cout << "Teminate" << std::endl;
	*windowclosed = true;
	glfwTerminate();
	return 0;
}