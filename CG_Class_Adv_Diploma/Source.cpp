#include <GLFW/glfw3.h>
#include<glad/glad.h>
#include<iostream>


int main(void)
{
#pragma region WindowCreation

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "CG_class", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    //glad loader
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
#pragma endregion

    std::cout << "starting game loop" << std::endl;

#pragma region RenderLoop
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.529, 0.592, 0.922, 0.0f);

        std::cout << "inside the game loop" << std::endl;



        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
#pragma endregion

}
