#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_gpu.h>

static SDL_Window* s_window;
static SDL_GPUDevice* s_gpu;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
    s_window = SDL_CreateWindow("DemoApp", 1280, 720, SDL_WINDOW_RESIZABLE);
    s_gpu = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV, false, nullptr);

    if (!s_window || !s_gpu) {
        SDL_DestroyWindow(s_window);
        SDL_DestroyGPUDevice(s_gpu);
        return SDL_APP_FAILURE;
    }

    SDL_ClaimWindowForGPUDevice(s_gpu, s_window);

    /**
     * initialise everything else here 
     */

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
 
    /**
     * app logic here 
     */   

     return SDL_APP_CONTINUE;   
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    switch(event->type) {
        case SDL_EVENT_WINDOW_CLOSE_REQUESTED:  return SDL_APP_SUCCESS;

        /**
         * event handling here
         */

        default:                                return SDL_APP_CONTINUE;
    }
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    SDL_DestroyWindow(s_window);
    SDL_DestroyGPUDevice(s_gpu);

    /**
     * dealocate memory here
     */
}
