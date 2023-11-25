#ifndef PLANE_H
#define PLANE_H

class Plane {
	int m_nCode;
	int m_nFuel;
	bool m_bInAir;
	int m_nTimeToFinish;

public:
	Plane(int nCode, int nFuel = 50);
	~Plane();
	void ProcessTick();
	void Print();
	bool IsCrashed();
	bool IsFinished();
	void SetTimeToFinish(int time);
};

#endif // PLANE_H
