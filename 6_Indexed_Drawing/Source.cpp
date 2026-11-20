#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include<string>
#include<vector>
#include<glm/glm.hpp>
#include"Shader.h"
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

int SquareArea(int s); //forward declartiom

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

#pragma region Vertex Data

    float vertices[] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f,   // top left 
     0.0f,  0.8f, 0.0f,
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3,    // second triangle
        0 ,3, 4     //3rd triangle
    };

#pragma endregion

#pragma region Buffers_Attributes
    //VBO - vertex buffer object
    //VAO - vertex attribute object
    //EBO - element buffer object
    unsigned int VBO, VAO, EBO;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    //binding = selecting
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    //attributes
    // 1st param - layout location
    // 2nd param - size of component
    // 5th param - total size of vertex
    // 6th param - offset within the vertex
    //pos attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //col attribute
    /*glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);*/
#pragma endregion

    Shader defaultShader("Resources/Shaders/default.vert",
        "Resources/Shaders/default.frag");

#pragma region RenderLoop

    std::cout << "starting game loop indexed project" << std::endl;
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    std::cout << SquareArea(5);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.282, 0.22, 0.369, 0.0f);

        //std::cout << glfwGetTime() << std::endl;

        defaultShader.use();

        defaultShader.SetVec3("objectColor", glm::vec3(1.0f, 1.0f, 0.0f));
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        defaultShader.SetVec3("objectColor", glm::vec3(1.0f, 0.0f, 0.0f));
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (void*)(6 * sizeof(float)));

        glPointSize(5.0f);
        defaultShader.SetVec3("objectColor", glm::vec3(1.0f, 1.0f, 1.0f));
        glDrawArrays(GL_POINTS, 0, 5);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
#pragma endregion

}

int SquareArea(int s)
{
    return s * s;
}
