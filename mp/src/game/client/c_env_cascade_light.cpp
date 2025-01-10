#include "cbase.h"
#include "c_env_cascade_light.h"
#include "materialsystem/imaterialsystem.h"
#include "materialsystem/itexture.h" // Add this include to resolve ITexture
#include "iclientshadowmgr.h"

#define SHADOW_MAP_RESOLUTION 1024
#include "tier0/memdbgon.h"


IMPLEMENT_CLIENTCLASS_DT(CCascadeLight, DT_CascadeLight, CCascadeLight)
RecvPropVector(RECVINFO(m_shadowDirection)),
RecvPropVector(RECVINFO(m_envLightShadowDirection)),
RecvPropBool(RECVINFO(m_bEnabled)),
RecvPropBool(RECVINFO(m_bUseLightEnvAngles)),
RecvPropInt(RECVINFO(m_LightColor), 0, RecvProxy_Int32ToColor32),
RecvPropInt(RECVINFO(m_LightColorScale), 0, RecvProxy_Int32ToInt32),
RecvPropFloat(RECVINFO(m_flMaxShadowDist))
END_RECV_TABLE()

CCascadeLight* m_pCascadeLight;

CCascadeLight::CCascadeLight() :
    C_BaseEntity(),
    m_shadowDirection(0, 0, -1),
    m_envLightShadowDirection(0, 0, -1),
    m_bEnabled(false),
    m_bUseLightEnvAngles(true),
    m_flMaxShadowDist(400.0f)
{


    m_LightColor.r = 255;
    m_LightColor.g = 255;
    m_LightColor.b = 255;
    m_LightColor.a = 255;
    m_LightColorScale = 255;

}

CCascadeLight::~CCascadeLight() {

}
void CCascadeLight::Spawn() {
    BaseClass::Spawn();

    SetNextClientThink(CLIENT_THINK_ALWAYS);

    m_pCascadeLight = this;
}
void CCascadeLight::Release() {
    m_pCascadeLight = NULL;

    BaseClass::Release();
}

static Vector g_vCascadeFrustumColors[4 + 1] =
{
    Vector(0, 1, 0),
    Vector(0, 0, 1),
    Vector(0, 1, 1),
    Vector(1, 0, 0),
    Vector(.85f, .85f, .2f)
};
void CCascadeLight::OnDataChanged(DataUpdateType_t updateType){
    BaseClass::OnDataChanged(updateType);

    if (updateType == DATA_UPDATE_CREATED)
    {
        for (int i = 0; i < m_iCascadeCount; ++i)
        {
            if (!m_ShadowMapTextures[i].IsValid())
            {
                m_ShadowMapTextures[i].InitRenderTarget(
                    SHADOW_MAP_RESOLUTION,          // Width
                    SHADOW_MAP_RESOLUTION,          // Height
                    RT_SIZE_OFFSCREEN,              // Render target size mode
                    IMAGE_FORMAT_RGBA8888,          // Image format
                    MATERIAL_RT_DEPTH_ONLY,         // Depth mode
                    true,                          // HDR 
                    "CascadeLight_ShadowMap");     // Optional name
            }
        }
    }
}

void CCascadeLight::ClientThink()
{
    // Update shadow maps or other logic here
    BaseClass::ClientThink();
}
