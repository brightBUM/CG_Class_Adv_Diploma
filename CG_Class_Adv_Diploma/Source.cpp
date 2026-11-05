#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include<string>

int main(void)
{
#pragma region WindowCreation

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1920, 1080, "CG_class", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);

    //glad loader
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
#pragma endregion

    std::cout << "starting game loop" << std::endl;

#pragma region RenderLoop
    int frameCounter = 0;
    double currentTime = 0.0f;
    double prevTime = 0.0f;
    float timer = 0.0f;
    int Fps = 0;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.282, 0.22, 0.369, 0.0f);

        //drawing code
       
        glPointSize(10.0f);

        

        glLineWidth(3.0f);
        glColor3f(1.0f, 0.5f, 0.0f); // 0 to 1
        

        glColor3f(1.0f, 1.0f, 1.0f); // 0 to 1
        glBegin(GL_TRIANGLE_FAN);

        glVertex3f(0.0f, 0.0f, 0.0f); //-1 to 1
        glVertex3f(0.5f, 0.0f, 0.0f);
        glVertex3f(0.5f, 0.5f, 0.0f);

        glColor3f(1.0f, 0.5f, 0.0f); // 0 to 1

        glVertex3f(0.0f, 0.75f, 0.0f);

        glColor3f(0, 1, 0.2); // 0 to 1
        glVertex3f(0.5f, 0.75f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.0f);

        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
#pragma endregion

}
