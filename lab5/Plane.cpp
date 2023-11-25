#include "plane.h"
#include <iostream>

Plane::Plane(int nCode, int nFuel) : m_nCode(nCode), m_nFuel(nFuel), m_bInAir(true), m_nTimeToFinish(-1) {}

Plane::~Plane() {
	// Деструктор
}

void Plane::ProcessTick() {
	if (m_bInAir) {
		m_nFuel -= 1;
	}
	if (m_nTimeToFinish > 0) {
		m_nTimeToFinish -= 1;
	}
}

void Plane::SetTimeToFinish(int time) {
	m_nTimeToFinish = time;
}


void Plane::Print() {
	std::cout << "#" << m_nCode << " (" << m_nFuel << ") " << (m_bInAir ? "In air" : "On ground");
	if (m_nTimeToFinish >= 0) {
		std::cout << " Processing: " << m_nTimeToFinish << "m left";
	}
	std::cout << std::endl;
}


bool Plane::IsCrashed() {
	return m_bInAir && (m_nFuel <= 0);
}

bool Plane::IsFinished() {
	return m_nTimeToFinish <= 0;
}
