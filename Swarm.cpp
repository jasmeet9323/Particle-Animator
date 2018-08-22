/*
 * Swarm.cpp
 *
 *  Created on: Jul 24, 2018
 *      Author: singh
 */

#include "Swarm.h"
#include "Particle.h"

namespace screen {

Swarm::Swarm(): m_lastTime(0) {
	m_particles = new Particle [Number_Of_Particles];
}

Swarm::~Swarm() {
	delete [] m_particles;
}

void Swarm::update(int elapsed){

	int interval = elapsed - m_lastTime;

	for(int i = 0 ; i < Number_Of_Particles; i ++){
		m_particles[i].update(interval);
	}
}

} /* namespace screen */
