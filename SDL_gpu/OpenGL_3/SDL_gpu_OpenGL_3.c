#include "SDL_gpu_OpenGL_3.h"


#if defined(SDL_GPU_DISABLE_OPENGL) || defined(SDL_GPU_DISABLE_OPENGL_3)

// Dummy implementations
GPU_Renderer* GPU_CreateRenderer_OpenGL_3(GPU_RendererID request) {return NULL;}
void GPU_FreeRenderer_OpenGL_3(GPU_Renderer* renderer) {}

#else


// Most of the code pulled in from here...
#define SDL_GPU_USE_OPENGL
#define SDL_GPU_USE_GL_TIER3
#define SDL_GPU_GL_TIER 3
#define SDL_GPU_GL_MAJOR_VERSION 3
#define CONTEXT_DATA ContextData_OpenGL_3
#define RENDERER_DATA RendererData_OpenGL_3
#define IMAGE_DATA ImageData_OpenGL_3
#define TARGET_DATA TargetData_OpenGL_3
#include "../GL_common/SDL_gpu_GL_common.inl"
#include "../GL_common/SDL_gpuShapes_GL_common.inl"


GPU_Renderer* GPU_CreateRenderer_OpenGL_3(GPU_RendererID request)
{
    GPU_Renderer* renderer = (GPU_Renderer*)malloc(sizeof(GPU_Renderer));
    if(renderer == NULL)
        return NULL;

    memset(renderer, 0, sizeof(GPU_Renderer));

    renderer->id = request;
	renderer->id.id = GPU_RENDERER_OPENGL_3;
	renderer->tier = SDL_GPU_GL_TIER;
    
    renderer->current_context_target = NULL;

    SET_COMMON_FUNCTIONS(renderer);

    return renderer;
}

void GPU_FreeRenderer_OpenGL_3(GPU_Renderer* renderer)
{
    if(renderer == NULL)
        return;

    free(renderer);
}


#endif
