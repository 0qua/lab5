#ifndef PLANESCONTROL_H
#define PLANESCONTROL_H

#include "plane.h"
#include <list>

class PlanesControl {
	int m_nTimeForProcessing;
	std::list<Plane*> m_Planes;
	Plane* m_pProcessingPlane;

public:
	PlanesControl(int nTimeForProcessing = 10);
	virtual ~PlanesControl();
	virtual void Add(Plane* p);
	virtual int ProcessTick();
	virtual void Print();
};

#endif