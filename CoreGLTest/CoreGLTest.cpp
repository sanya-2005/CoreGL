#include "CoreGL\Window.h"
#include "CoreGL\glContext.h"
#include "CoreGL\OpenGL.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>

Window* window;

using uint = unsigned int;

uint VAO;
uint program;

bool switchColor = true;
bool ctrlAPressed = false;
  
void Resize(int width, int height)
{
    if (width == 0 || height == 0)
    {
        return;
    }

    glViewport(0, 0, width, height);
}

void Draw()
{
    if (switchColor)
    {
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    }
    else
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(program);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    SwapWindowBuffers(window);
}

void Input(Keys key, ModiferKeys modifer, KeyActions action)
{
    if (action == KeyActions::KeyDown)
    {
        if (key == Keys::Esc)
        {
            CloseNativeWindow(window);
        }

        if (key == Keys::A && modifer == ModiferKeys::Ctrl)
        {
            ctrlAPressed = !ctrlAPressed;
        }
        else if (key == Keys::A)
        {
            switchColor = false;
        }
    }

    if (action == KeyActions::KeyUp)
    {
        if (key == Keys::A)
        {
            switchColor = true;
        }
    }
}

void LoadData()
{
    float vertices[] =
    {
         0.5f,  0.5f, 0.0f, 
         0.5f, -0.5f, 0.0f,  
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f 
    };

    uint indices[] =
    {
        0, 1, 3,
        1, 2, 3
    };

    uint VBO;
    glGenBuffers(1, &VBO);


    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    uint IBO;
    glGenBuffers(1, &IBO);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    int success;
    char infoLog[512];

    uint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    std::ifstream vertexShaderFile;

    vertexShaderFile.open("vert.spv", std::ios::out | std::ios::binary);

    uint vsSize = std::filesystem::file_size("vert.spv");

    std::vector<char> vsBytes(vsSize);

    for (int i = 0; i < vsSize; i++)
    {
        vertexShaderFile.read(&vsBytes[i], 1);
    }

    vertexShaderFile.close();

    glShaderBinary(1, &vertexShader, GL_SHADER_BINARY_FORMAT_SPIR_V_ARB, &vsBytes[0], vsBytes.size());
    glSpecializeShader(vertexShader, "main", 0, 0, 0);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        
        std::cout << "Error compiling vertex shader\nLog\n" << infoLog << std::endl;
    }

  /*  std::string vsCode;
    std::ifstream vertexShaderFile;

    vertexShaderFile.open("vert.glsl");
    
    std::stringstream temp;

    temp << vertexShaderFile.rdbuf();

    vertexShaderFile.close();

    vsCode = temp.str();

    const char* vstemp = vsCode.c_str();

    glShaderSource(vertexShader, 1, &vstemp, nullptr);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cout << "Error compiling vertex shader\nLog\n" << infoLog << std::endl;
    }*/

    uint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

    std::ifstream fragShaderFile;

    fragShaderFile.open("frag.spv", std::ios::out | std::ios::binary);

    uint fsSize = std::filesystem::file_size("frag.spv");

    std::vector<char> fsBytes(fsSize);

    for (int i = 0; i < fsSize; i++)
    {
        fragShaderFile.read(&fsBytes[i], 1);
    }

    fragShaderFile.close();

    glShaderBinary(1, &fragShader, GL_SHADER_BINARY_FORMAT_SPIR_V_ARB, &fsBytes[0], fsBytes.size());
    glSpecializeShader(fragShader, "main", 0, 0, 0);

    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragShader, 512, nullptr, infoLog);
        std::cout << "Error compiling fragment shader\nLog\n" << infoLog << std::endl;
    }


 /*   std::string fsCode;
    std::ifstream fsFile;
    std::stringstream temp1;

    fsFile.open("frag.glsl");

    temp1 << fsFile.rdbuf();

    fsFile.close();

    fsCode = temp1.str();

    const char* fstemp = fsCode.c_str();

    glShaderSource(fragShader, 1, &fstemp, nullptr);
    glCompileShader(fragShader);

    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragShader, 512, nullptr, infoLog);
        std::cout << "Error compiling fragment shader\nLog\n" << infoLog << std::endl;
    }*/

    program = glCreateProgram();

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragShader);

    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cout << "Error linking program\nLog\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);
}

int main()
{
    if (!InitRuntime())
    {
        std::cout << "Error init runtime" << std::endl;
        return -1;
    }

    GLCoreVersion version = GetGLCoreVersion();

    std::cout << "GLCore version: " + std::to_string(version.major) + "." + std::to_string(version.minor) << std::endl;

    window = CreateNativeWindow("Lol - русский текст", 600, 800);

    ShowNativeWindow(window);

    SetNativeWindowTitle(window, "Ага ага");

    if (!LoadGLContext())
    {
        std::cout << "Error load gl context" << std::endl;
        DisposeRuntime();
        return -1;
    }
    
    PixelFormatInfo pixelInfo{};

    pixelInfo.colorBits = 32;
    pixelInfo.depthBits = 24;
    pixelInfo.pixelType = PixelType::RgbaFormat;
    
    GLContextInfo contextInfo{};

    contextInfo.major = 4;
    contextInfo.minor = 6;
    contextInfo.profile = GLProfile::CoreProfile;
    contextInfo.flags |= GLContextFlags::DebugFlag;

    if (!CreateGLContext(window, &pixelInfo, &contextInfo))
    {
        std::cout << "error create context" << std::endl;
        DisposeRuntime();
        return -1;
    }

    SetCurrentContext(window);

    if (!LoadCoreGL())
    {
        std::cout << "error load core gl" << std::endl;
        DisposeRuntime();
        return -1;
    }

    Size size = GetWindowSize(window);

    glViewport(0, 0, size.width, size.height);

    SetResizeCallback(window, &Resize);
    SetKeyInputCallback(window, &Input);

    LoadData();

    while (!IsWindowShouldClosed(window))
    {
        PollEvents(window);

        if (ctrlAPressed)
        {
            SetNativeWindowTitle(window, "A + ctrl is pressed");
        }
        else
        {
            SetNativeWindowTitle(window, "Ага ага");
        }

        Draw();
    }

    ResetContext();
    DeleteGLContext(window);
    DisposeRuntime();

    return 0;
}
