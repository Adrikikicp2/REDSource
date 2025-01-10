#ifndef C_CASCADE_LIGHT_H
#define C_CASCADE_LIGHT_H

#ifdef _WIN32
#pragma once
#endif

#include "cbase.h"
#include "vector.h"
#include "color.h"
#include "materialsystem/imaterialsystem.h"
#include "utlvector.h"

class CCascadeLight : public C_BaseEntity
{
public:
    DECLARE_CLASS(CCascadeLight, C_BaseEntity);
    DECLARE_CLIENTCLASS();

    CCascadeLight();
    virtual ~CCascadeLight();

    // Overrides
    virtual void Spawn() OVERRIDE;
    virtual void Release() OVERRIDE;
    virtual void OnDataChanged(DataUpdateType_t updateType) OVERRIDE;
    virtual void ClientThink() OVERRIDE;


    inline const Vector& GetShadowDirection() const { return m_shadowDirection; }
    inline const Vector& GetEnvLightShadowDirection() const { return m_envLightShadowDirection; }
    inline bool IsEnabled() const { return m_bEnabled; }
    inline color32 GetColor() const { return m_LightColor; }
    inline int GetColorScale() const { return m_LightColorScale; }
    inline bool UseLightEnvAngles() const { return m_bUseLightEnvAngles; }
    float GetMaxShadowDist() const { return m_flMaxShadowDist; }

private:
 

    Vector m_shadowDirection;
    Vector m_envLightShadowDirection;
    bool m_bEnabled;
    bool m_bUseLightEnvAngles;
    color32	m_LightColor;
    int	m_LightColorScale;
    float m_flMaxShadowDist;
    int m_iCascadeCount;
    CTextureReference m_ShadowMapTextures[4];
};

extern CCascadeLight* m_pCascadeLight;

#endif // C_CASCADE_LIGHT_H
