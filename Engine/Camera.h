#pragma once
#include "Component.h"

namespace McCol
{
    class Transform;

    class Camera final : public McCol::Component
    {
    public:
        Camera(GameObject* owner);
        ~Camera() override = default;

    private:
        GameObject* m_TargetObject;                     // ī�޶� ������Ʈ�� ���� Ÿ�� ������Ʈ
        Transform* m_Transform;                         // Ÿ�� ������Ʈ�� Ʈ������

    public:
        void Initialize() override;

        D2D1_MATRIX_3X2_F GetWorldMatrix() const;       // ī�޶� ������Ʈ�� ���� Ÿ�� ������Ʈ�� WorldMatrix ��ȯ
        void SetTargetObject(GameObject* targetObject); // Ÿ�� ������Ʈ ����
    };
}
