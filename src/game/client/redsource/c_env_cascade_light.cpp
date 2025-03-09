#include "cbase.h"
#include "c_env_cascade_light.h"

IMPLEMENT_CLIENTCLASS_DT(C_CascadeLight, DT_CascadeLight, CCascadeLight)
END_RECV_TABLE()

C_CascadeLight::C_CascadeLight() {

}

C_CascadeLight::~C_CascadeLight() {

}

void C_CascadeLight::Spawn() {

}

void C_CascadeLight::Release() {

}

bool C_CascadeLight::ShouldDraw() {

	return true;
}

void C_CascadeLight::ClientThink() {

}