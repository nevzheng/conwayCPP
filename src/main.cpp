#include <SDL2/SDL.h>
#include <iostream>
#include <string>

#include "GameOfLife.hpp"
#include "cleanup.hpp"
#include "res_path.hpp"

int main(int, char **) {
  bool quit = false;
  SDL_Event event;

  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window =
      SDL_CreateWindow("SDL2 Pixel Drawing", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                                           SDL_TEXTUREACCESS_STATIC, 640, 480);
  Uint32 *pixels = new Uint32[640 * 480];
  memset(pixels, 0, 640 * 480 * sizeof(Uint32));

  while (!quit) {
    SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));

    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
    }
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyWindow(window);
  delete[] pixels;
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);

  SDL_Quit();

  return 0;
}
// int main(int, char **) {
//   // int width, height = 10;
//   // bool leftMouseButtonDown = false;
//
//   bool quit = false;
//
//   SDL_Event event;
//
//   GameOfLife gm1(640, 480);
//   gm1.randomInit();
//
//   // std::cout << "ENTER WIDTH,HEIGHT \n DEFAULT RANDOM CONFIG" << '\n';
//
//   // std::cin >> width;
//   // std::cin >> height;
//
//   SDL_Init(SDL_INIT_VIDEO);
//
//   SDL_Window *window =
//       SDL_CreateWindow("SDL2 Pixel Drawing", SDL_WINDOWPOS_UNDEFINED,
//                        SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
//
//   SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
//   SDL_Texture *texture = SDL_CreateTexture(renderer,
//   SDL_PIXELFORMAT_ARGB8888,
//                                            SDL_TEXTUREACCESS_STATIC, 640,
//                                            480);
//   Uint32 *pixels = new Uint32[640 * 480];
//   memset(pixels, 0, 640 * 480 * sizeof(Uint32));
//   // auto gd = gm1.get_conwayGrid();
//
//   while (!quit) {
//     // SDL_WaitEvent(&event);
//     SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));
//
//     switch (event.type) {
//     case SDL_QUIT:
//       quit = true;
//       break;
//     }
//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, texture, NULL, NULL);
//     SDL_RenderPresent(renderer);
//   }
//
//   // while (!quit) {
//   //
//   //   SDL_WaitEvent(&event);
//   //   SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));
//   //   SDL_RenderClear(renderer);
//   //   SDL_RenderCopy(renderer, texture, NULL, NULL);
//   //   SDL_RenderPresent(renderer);
//   //   /////// draw grid
//   //   // conwayGrid gd = gm1.get_conwayGrid();
//   //
//   //   // for (int i = 0; i < 640; ++i) {
//   //   //   for (int j = 0; j < 480; ++j) {
//   //   //     auto tmp = GameOfLife::getState(gd->at(i).at(j));
//   //   //     if (tmp) {
//   //   //       pixels[j * 640 + i] = 255;
//   //   //     } else {
//   //   //       pixels[j * 640 + i] = 0;
//   //   //     }
//   //   //   }
//   //   // }
//   //   ///////
//   //
//   //   switch (event.type) {
//   //
//   //   case SDL_QUIT:
//   //     quit = true;
//   //     break;
//   //     // case SDL_MOUSEBUTTONUP:
//   //     //   if (event.button.button == SDL_BUTTON_LEFT)
//   //     //     leftMouseButtonDown = false;
//   //     //   break;
//   //     // case SDL_MOUSEBUTTONDOWN:
//   //     //   if (event.button.button == SDL_BUTTON_LEFT)
//   //     //     leftMouseButtonDown = true;
//   //     // case SDL_MOUSEMOTION:
//   //     //   if (leftMouseButtonDown) {
//   //     //     int mouseX = event.motion.x;
//   //     //     int mouseY = event.motion.y;
//   //     //     pixels[mouseY * 640 + mouseX] = 0;
//   //   }
//   //   break;
//   // }
//
//   delete[] pixels;
//   SDL_DestroyTexture(texture);
//   SDL_DestroyRenderer(renderer);
//   SDL_DestroyWindow(window);
//   SDL_Quit();
//   return 0;
// }
