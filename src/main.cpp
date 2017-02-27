#include <SDL2/SDL.h>
#include <iostream>

#include "GameOfLife.hpp"

int posX = 100;
int posY = 100;
int sizeX = 1000;
int sizeY = 1000;

SDL_Window *window;
SDL_Renderer *renderer;

bool InitEverything();
bool InitSDL();
bool CreateWindow();
bool CreateRenderer();
void SetupRenderer();
void Cleanup();

void Render(conwayGrid &gd);

void RunGame();

SDL_Rect playerPos;

int main(int, char **) {
  if (!InitEverything())
    return -1;

  // Initlaize our playe
  playerPos.x = 20;
  playerPos.y = 20;
  playerPos.w = 99;
  playerPos.h = 99;

  RunGame();
}

void Cleanup() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
}
void Render(conwayGrid &gd) {
  // iterate though the ten subblocks
  // Clear the window and make it all green
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      auto tmp = gd.at(i).at(j);
      if (tmp) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      } else {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
      }
      SDL_RenderFillRect(renderer, &playerPos);

      playerPos.y = (playerPos.y + 100) % 1000;
    }
    playerPos.x = (playerPos.x + 100) % 1000;
  }

  // SDL_RenderPresent(renderer);
  SDL_Delay(500);
  SDL_RenderPresent(renderer);
}
bool InitEverything() {
  if (!InitSDL())
    return false;

  if (!CreateWindow())
    return false;

  if (!CreateRenderer())
    return false;

  SetupRenderer();

  return true;
}
bool InitSDL() {
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
    std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
    return false;
  }

  return true;
}
bool CreateWindow() {
  window = SDL_CreateWindow("Server", posX, posY, sizeX, sizeY, 0);

  if (window == nullptr) {
    std::cout << "Failed to create window : " << SDL_GetError();
    return false;
  }

  return true;
}
bool CreateRenderer() {
  renderer = SDL_CreateRenderer(window, -1, 0);

  if (renderer == nullptr) {
    std::cout << "Failed to create renderer : " << SDL_GetError();
    return false;
  }

  return true;
}
void SetupRenderer() {
  // Set size of renderer to the same as window
  SDL_RenderSetLogicalSize(renderer, sizeX, sizeY);

  // Set color of renderer to green
  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
}
void RunGame() {
  bool loop = true;
  std::srand(std::time(NULL));
  GameOfLife gm(10, 10);
  gm.randomInit();
  auto gd = gm.get_conwayGrid();

  while (loop) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        loop = false;
    }
    Render(*gd);
    gm.iterateGrid();
  }
  // Render(*gd);

  // Add a 16msec delay to make our game run at ~60 fps
  SDL_Delay(16);
  Cleanup();
  SDL_Quit();
}
