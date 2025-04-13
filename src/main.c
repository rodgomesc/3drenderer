#include <stdio.h>
#include <stdbool.h>
#include <SDL3/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;
bool is_running = false;

bool initialize_window(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOW_BORDERLESS);

    if (window == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, NULL);

    if (renderer == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void setup(void) {}

void process_events(void)
{
}

void update(void) {}

void render(void) {}

int main(void)
{
    is_running = initialize_window();

    while (is_running)
    {
        process_events();
        update();
        render();
    }

    return 0;
}