#include "cbase.h"


// PURPOSE: Serve as main header file for cascade shadows (CLIENT DLL)

class C_CascadeLight : public C_BaseEntity {
public:
	DECLARE_CLASS(C_CascadeLight,C_BaseEntity)
	DECLARE_CLIENTCLASS();

	C_CascadeLight();

	virtual ~C_CascadeLight();

	static C_CascadeLight* Get() { return m_pCascadeLight; }

	virtual void Spawn();
	virtual void Release();
	virtual bool ShouldDraw();
	virtual void ClientThink();

protected:
	static C_CascadeLight* m_pCascadeLight;

};