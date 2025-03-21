/*
	Cute Framework
	Copyright (C) 2024 Randy Gaul https://randygaul.github.io/

	This software is dual-licensed with zlib or Unlicense, check LICENSE.txt for more info
*/

#ifndef CF_IMGUI_INTERNAL_H
#define CF_IMGUI_INTERNAL_H

#include <SDL3/SDL.h>

void cf_imgui_init();
void cf_imgui_shutdown();
void cf_imgui_draw(SDL_GPUTexture* swapchain_texture);

#endif // CF_IMGUI_INTERNAL_H
