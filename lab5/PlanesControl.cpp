#include "PlanesControl.h"
#include <iostream>

PlanesControl::PlanesControl(int nTimeForProcessing) : m_nTimeForProcessing(nTimeForProcessing), m_pProcessingPlane(nullptr) {}

PlanesControl::~PlanesControl() {
	if (m_pProcessingPlane)
		delete m_pProcessingPlane;
	while (!m_Planes.empty()) {
		Plane* p = m_Planes.front();
		m_Planes.pop_front();
		delete p;
	}
}

void PlanesControl::Add(Plane* p) {
	m_Planes.push_back(p);
}

int PlanesControl::ProcessTick() {
	if (!m_pProcessingPlane && !m_Planes.empty()) {
		m_pProcessingPlane = m_Planes.front();
		m_Planes.pop_front();
		m_pProcessingPlane->SetTimeToFinish(m_nTimeForProcessing);
	}
	if (m_pProcessingPlane) {
		m_pProcessingPlane->ProcessTick();
		if (m_pProcessingPlane->IsFinished()) {
			delete m_pProcessingPlane;
			m_pProcessingPlane = nullptr;
		}
	}
	for (auto& plane : m_Planes) {
		plane->ProcessTick();
	}
	return 0; // Можна повернути статус, наприклад, кількість оброблених літаків
}

void PlanesControl::Print() {
	if (m_pProcessingPlane) {
		m_pProcessingPlane->Print();
	}
	for (auto& plane : m_Planes) {
		plane->Print();
	}
}
