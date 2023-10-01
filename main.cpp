#include <iostream>
#include <glad/glad.h>    //FUCKING KILL YOURSELF WHY WON'T YOU FUCKING WORK
#include <GLFW/glfw3.h>


//Do I really need to explain this?
int height = 800;
int width = 800;


//All of the sweet, sweet functions.

void setupWindow();
void processInput(GLFWwindow *window);


float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
}; 

int main(int argc, char **argv){

    setupWindow();

    // initialize GLFW
    if (!glfwInit())
    {
        return -1;
    }
    
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    // create a window pointer
    GLFWwindow *window = glfwCreateWindow(width, height, "OpenGL Test", NULL, NULL);
    // error check
    if (window == NULL)
    {
        std::cout << "Error. I could not create a window at all!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    //init GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    //Render/Close loop.
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        //Start of rendering loop

        glClearColor(0.55f, 0.71f, 0.73f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        

        //End of rendering loop

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

//This essentially changes the size of the window. Not exactly the best system around, but it works
void setupWindow(){
    std::cout << "Welcome to the optional window set-up.\nPress 0 to skip\nPlease select the height of the window:\n";    
    std::cin >> height;
    if(height == 0){
        height = 760; 
        return;
    }
    std::cout << "\nNow input the width:\n";
    std::cin >> width;
}


/*
    Just a test to handle user input. The function
    requires the current window as a parameter.
*/
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}