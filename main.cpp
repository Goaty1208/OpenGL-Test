#include <iostream>
#include <glad/glad.h>    //FUCKING KILL YOURSELF WHY WON'T YOU FUCKING WORK
#include <GLFW/glfw3.h>   //Fixed the above

//Do I really need to explain this?
int height = 800;
int width = 800;

//Uhhhh
//Yeah it does shit I guess
//I hope
static unsigned int CompileShader(unsigned int type, const std::string& source) {
    
    unsigned int id = glCreateShader(GL_VERTEX_SHADER);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    
    //my sanity might be dwindling
    //I might do error handling later
    //bool aboveStatement = false;

    return id;
}


//Function to create shaders. What the fuck was it supposed to be if not, I don't know, this?
static int CreateShader(const std::string& vertexShader, const std::string& fragmentShader){
    unsigned int program = glCreateProgram();   
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);  
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);
}


//All of the sweet, sweet functions.
    
void setupWindow();
void processInput(GLFWwindow *window);

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

    float vertices[9] = {
        -0.5f, -0.5f, 0.0f, 
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    }; 

    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(vertices), vertices, GL_STATIC_DRAW);


    //Render/Close loop.
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        //Start of rendering loop

        glClearColor(0.55f, 0.71f, 0.73f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);

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