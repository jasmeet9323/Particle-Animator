/*
 * Screen.h
 *
 *  Created on: Jul 24, 2018
 *      Author: singh
 */
#include <SDL.h>

#ifndef SCREEN_H_
#define SCREEN_H_

namespace screen {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;

public:
	Screen();
	bool init();
	bool processEvents();
	void update();
	void setPixel(int , int , Uint32 , Uint32 , Uint32 );
	void boxBlur();
	void close();
	void clear();
	virtual ~Screen();
};

} /* namespace screen */

#endif /* SCREEN_H_ */
