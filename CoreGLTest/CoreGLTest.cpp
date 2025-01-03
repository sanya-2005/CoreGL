#include "Window.h"
#include "glContext.h"
#include "OpenGL.h"
#include <iostream>

void Resize(int width, int height)
{
    if (width == 0 || height == 0)
    {
        return;
    }

    glViewport(0, 0, width, height);
}

int main()
{
    InitRuntime();

    Window* window = CreateNativeWindow("Lol - русский текст", 600, 800);

    ShowNativeWindow(window);

    if (!LoadGLContext())
    {
        std::cout << "Error load gl context" << std::endl;
        return -1;
    }
    
    PixelFormatInfo info;

    info.colorBits = 32;
    info.depthBits = 24;
    info.stencilBits = 8;
    info.pixelType = PixelType::RgbaFormat;

    GLContextCreateInfo contextInfo{};

    contextInfo.major = 4;
    contextInfo.minor = 5;
    contextInfo.profile = GLProfile::CoreProfile;
    contextInfo.flags |= GLContextFlags::DebugFlag;

    if (!CreateGLContext(window, &info, &contextInfo))
    {
        std::cout << "error create context" << std::endl;
        return -1;
    }

    SetCurrentContext(window);

    if (!LoadCoreGL())
    {
        std::cout << "error load core gl" << std::endl;
        return -1;
    }

    Size size = GetWindowSize(window);

    glViewport(0, 0, size.width, size.height);

    SetResizeCallback(window, &Resize);

    while (!IsWindowShouldClosed(window))
    {
        PollEvents(window);

        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        SwapWindowBuffers(window);
    }

    ResetContext();
    DeleteGLContext(window);
    DisposeRuntime();

    return 0;
}
