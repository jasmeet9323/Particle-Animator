/*
 * Particle.cpp
 *
 *  Created on: Jul 24, 2018
 *      Author: singh
 */

#include "Particle.h"
#include <cstdlib>
#include <time.h>
#include <math.h>

#define dist(a, b) pow(a*a + b*b, 0.5);

namespace screen {

Particle::Particle() :
		m_x(0), m_y(0) {

	init();
	/*m_x = ((2.0 * rand()) / RAND_MAX) - 1;
	 m_y = ((2.0 * rand()) / RAND_MAX) - 1;
	 m_xspeed = 0.002 * ((2.0 * rand()) / RAND_MAX - 1.);
	 m_yspeed = 0.002 * ((2.0 * rand()) / RAND_MAX - 1.);*/

}

void Particle::init() {
	m_x = 0;
	m_y = 0;
	m_direction = (2.0 * M_PI * rand()) / RAND_MAX;
	m_speed = (0.001 * rand()) / RAND_MAX;
	m_speed *= m_speed;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}
void Particle::update(int interval) {

	/*m_x += m_xspeed;
	 m_y += m_yspeed;

	 if (m_x <= -1 || m_x >= 1) {
	 m_xspeed = -m_xspeed;
	 }

	 if (m_y <= -1 || m_y >= 1) {
	 m_yspeed = -m_yspeed;
	 }
	 */
	// interval = 1;
	m_direction += interval * 0.000001;

	m_x += interval * (m_speed * cos(m_direction));
	m_y += interval * (m_speed * sin(m_direction));

	if (m_x < -1 || m_x > 1 || m_y > 1 || m_y < -1) {
		init();
	}
	if( rand() < RAND_MAX/100 ){
		init();
	}
}
} /* namespace screen */
