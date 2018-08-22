/*
 * SDLTest.cpp
 *
 *  Created on: Jul 21, 2018
 *      Author: singh
 */

#include <iostream>
#include <math.h>
#include <SDL.h>
#include <cstring>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace screen;

int main() {

	srand(time(NULL));

	// Declare the screen
	Screen screen;

	// Initialize the screen
	if (!screen.init()) {
		cout << "Error Initializing Screen." << endl;
		return 1;
	}

	// Declare swarm of particles
	Swarm swarm;

	// Run the game loop
	while (true) {

		// Change the color of the particles using elapsed time
		int elapsed = SDL_GetTicks();

		swarm.update(elapsed);

		unsigned char red = 128 * (1 + sin(elapsed * 0.0001));
		unsigned char green = 128 * (1 + sin(elapsed * 0.0002));
		unsigned char blue = 128 * (1 + sin(elapsed * 0.0003));

		const Particle * const pParticles = swarm.getParticles();

		// Set pixel values where the particles are located on the screen
		for (int i = 0; i < Swarm::Number_Of_Particles; i++) {
			Particle particle = pParticles[i];
			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = (particle.m_y + 1) * Screen::SCREEN_WIDTH / 2 - (Screen::SCREEN_WIDTH-Screen::SCREEN_HEIGHT)/2;

			screen.setPixel(x, y, red, green, blue);
		}

		// Blur the particles
		screen.boxBlur();

		// Update the screen
		screen.update();

		//screen.clear();

		// Check for screen events, such as close window. Break loop if event occurs
		if (!screen.processEvents())
			break;
	}

	// Close the screen, delete the SDL variables here
	screen.close();

	//
	SDL_Quit();

	return 0;
}
