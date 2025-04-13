#include <stdio.h>
#include <stdbool.h>
#include <SDL3/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;
bool is_running = false;

bool initialize_window(void)
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow(NULL, 1280, 720, SDL_WINDOW_OPENGL);

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

void setup(void)
{
    // TODO
}

void process_events(void)
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_EVENT_QUIT:
        is_running = false;
        break;

    case SDL_EVENT_KEY_DOWN:
        if (event.key.key == SDLK_ESCAPE)
            is_running = false;
        break;
    }
}

void update(void)
{
    // TODO
}

void render(void)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

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