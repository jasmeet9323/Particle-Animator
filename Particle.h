/*
 * Particle.h
 *
 *  Created on: Jul 24, 2018
 *      Author: singh
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace screen {

class Particle {
public:
	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;

private:
	void init();

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

} /* namespace screen */

#endif /* PARTICLE_H_ */
