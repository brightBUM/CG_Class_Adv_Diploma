#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include<string>
#include<vector>
#include<glm/glm.hpp>
using namespace std;
using namespace glm;
//global variables
const int WIDTH = 800;
const int HEIGHT = 600;
float worldX;
float worldY;

glm::vec3 pointA(0.5f, 0.5f, 0.5f);

vector<int> a;
vector<vec3> points;

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
    {
        //cout << "right mouse pressed" << endl;
        points.push_back(glm::vec3(worldX,worldY,0.0f)); //x 
    }
}
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    worldX = 2.0f*(xpos / WIDTH) - 1.0f;
    worldY = 1.0f - 2.0f*(ypos / HEIGHT) ;

   /* cout << "xPos : "<< worldX << endl;
    cout << "yPos : " << worldY <<"\n" << endl;*/

}
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

    std::cout << "starting game loop project 2" << std::endl;

#pragma region RenderLoop
    
    //1
    points.push_back(vec3(0.0f,0.0f,0.0f)); //x 
    points.push_back(vec3(0.5f,0.0f,0.0f)); //x 
    points.push_back(vec3(0.5f,0.5f,0.0f)); //x 
    points.push_back(vec3(0.0f,0.5f,0.0f)); //x 

    

    for (int i = 0;i < a.size();i++)
    {
        cout << a[i] << endl;
    }


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

        glBegin(GL_LINE_STRIP);

        for (int i = 0;i < points.size();i ++)
        {
            glVertex3f(points[i].x, points[i].y, 0.0f);

        }

        glEnd();

        glColor3f(1.0f, 1.0f, 1.0f); // 0 to 1

        glBegin(GL_POINTS);

        for (int i = 0;i < points.size();i++)
        {
            glVertex3f(points[i].x, points[i].y, 0.0f);

        }

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
