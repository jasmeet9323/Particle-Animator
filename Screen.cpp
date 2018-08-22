/*
 * Screen.cpp
 *
 *  Created on: Jul 24, 2018
 *      Author: singh
 */
#include <SDL.h>
#include <cstring>
#include "Screen.h"

namespace screen {

Screen::Screen() :
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(
		NULL) {

}

Screen::~Screen() {

}

bool Screen::init() {

	// Start SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	// Create a window
	m_window = SDL_CreateWindow("Particle Fire Explosion",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGB888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_renderer == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	if (m_texture == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		m_buffer1[i] = 0x00000000;
		m_buffer2[i] = 0x00000000;
	}

	return true;
}

void Screen::update() {

	SDL_UpdateTexture(m_texture, NULL, m_buffer1,
			SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Screen::setPixel(int x, int y, Uint32 r, Uint32 g, Uint32 b) {

	if (x < 0 || x >= Screen::SCREEN_WIDTH || y < 0
			|| y >= Screen::SCREEN_HEIGHT)
		return;

	Uint32 color = 0;
	color = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);

	m_buffer1[(SCREEN_WIDTH * y) + x] = color;
}

bool Screen::processEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			return false;
	}
	return true;
}

// This function implements box blur for the particles
void Screen::boxBlur() {

	// Swap buffers, so pixel is in m_buffer2 and we are drawing to m_buffer1.
	Uint32* temp = m_buffer1;
	m_buffer1 = m_buffer2;
	m_buffer2 = temp;

	for (int i = 0; i < SCREEN_WIDTH; i++) {
		for (int j = 0; j < SCREEN_HEIGHT; j++) {

			int redTotal=0;
			int greenTotal=0;
			int blueTotal=0;
			for (int k = -1; k <= 1; k++) {
				for (int l = -1; l <= 1; l++) {
					int currentX = i + k;
					int currentY = j + l;

					if (currentX >= 0 && currentX < SCREEN_WIDTH
							&& currentY >= 0 && currentY < SCREEN_HEIGHT) {

						Uint32 pixel = (m_buffer2[(SCREEN_WIDTH * currentY)
								+ currentX]);

						Uint8 red = ( pixel) >> 16;
						Uint8 green = (pixel  ) >> 8;
						Uint8 blue = (pixel );

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;

					}
				}
			}
			Uint8 red = redTotal / 9;
			Uint8 green = greenTotal / 9;
			Uint8 blue = blueTotal / 9;

			setPixel(i, j, red, green, blue);
		}
	}
}

void Screen::clear() {
	memset(m_buffer1, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
}

void Screen::close() {
	delete[] m_buffer1;
	delete[] m_buffer2;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
}

} /* namespace screen */
