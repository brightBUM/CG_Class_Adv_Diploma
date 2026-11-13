#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include<string>
#include<vector>
#include<glm/glm.hpp>
using namespace std;
using namespace glm;

#pragma region Global Variables

//global variables
const int WIDTH = 800;
const int HEIGHT = 800;
float worldX;
float worldY;

#pragma endregion

#pragma region FwdDeclarations
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{

}
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    worldX = 2.0f * (xpos / WIDTH) - 1.0f;
    worldY = 1.0f - 2.0f * (ypos / HEIGHT);

    /* cout << "xPos : "<< worldX << endl;
     cout << "yPos : " << worldY <<"\n" << endl;*/

}
#pragma endregion


int main(void)  
{

#pragma region WindowCreation

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WIDTH, HEIGHT, "CG_class", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSwapInterval(0);

    //glad loader
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
#pragma endregion

    float vertices[] = {
    -0.5f, -0.5f, 0.0f,//1
     0.5f, -0.5f, 0.0f,//2
     0.0f,  0.5f, 0.0f //3
    };

    //VBO - vertex buffer object
    //VAO - vertex attribute object
    unsigned int VBO,VAO;
    glGenBuffers(1, &VBO);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    //binding = selecting
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


   
#pragma region RenderLoop

    std::cout << "starting game loop shader project" << std::endl;
    //glPolygonMode(GL_FRONT, GL_LINE);
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.282, 0.22, 0.369, 0.0f);


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
#pragma endregion

}
