#include <stdio.h>
#include <SDL3/SDL.h>

int main(void)
{
    printf("Hello World");
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Hello World");
    return 0;
}