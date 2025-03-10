#pragma once
#include "Component.h"
#include "GameObject.h"
#include "IRenderable.h"

#include "Vector2.h"
/*----------------------------------------------------------------------------------------------------------------------------------
Collider
AABB, OBB �� �̸� Ŭ������ ���ӿ�����Ʈ�� ������Ʈ�� �߰���Ű�� ��.
�⺻������ �ݶ��̴� ������� ��ġ�� ������Ʈ�� ����ϰ� �ִ� ������ ������Ʈ�� ���� �״�� ������.
void SetColliPosOffset(const Vector2& ColliOffset);
void SetColliScaleOffset(const Vector2& ColliScale);
�Լ��� offset�� ������ �� �ִ�.
(������ ������ ������Ʈ�� ȸ���Ҷ� posoffset ������ �� ��ġ���� �ݶ��̴��� ȸ���ϴµ�
������Ʈ ȸ���� ��ġ ���� �ݶ��̴��� ���� �����Ϸ��� ���� �ؾߵ�.)
�׸��� void AddCollider(Collider* collider)��
CollisionSystem ���� �ȿ� �ݶ��̴� �־��ְ�
(�� �κ� �ϴ� �̷��� ��������� �س��µ� ���� �ݶ��̴� ���� �� �ڵ����� ���Եǰ� �����Ҽ���? )
������Ʈ���� CollisionSystem ������Ʈ ȣ���ϸ� ���ư��鼭
�浹 �� ICollidable�� ��ӹ��� ���� ������Ʈ �Ļ�Ŭ������ �����ص� ���� �����Լ�
virtual void HandleCollision(Collider* mine, Collider* other); �� ȣ�� ��.
�� ��ɿ� ���� �� ���ӿ�����Ʈ �Ļ�Ŭ������ HandleCollision() ���� ���ָ� ��.
���� AABB, OBB ���� �ݶ��̴������� �浹 üũ ����.

TODO : ���� �����ӿ� �浹 �ƴ��� üũ�ϴ� ��� �����ϳ� ���� Enter(), Exit(), OnCollision() �浹 ���� ����ȭ �ϱ�
----------------------------------------------------------------------------------------------------------------------------------*/
namespace McCol
{
	class Transform;
	class BaseRenderer;

	class Collider : public Component, public IFixedUpdatable, public IRenderable
	{
	public:
		enum class CollisionState
		{
			None,
			Enter,
			Stay,
			Exit
		};
	public:
		/*temp*/
		//�ӽ� �浹 Ȯ�ο� ��
		//D2D1_COLOR_F m_color;

	protected:
		bool m_IsColliding;
		CollisionState m_CollisionState;

		Transform* m_OwnerTransform;
		BaseRenderer* m_OwnerRenderer;

		Vector2 m_ColliPosOffset;
		Vector2 m_ColliScaleOffset;
		Vector2 m_Size;

		D2D1_MATRIX_3X2_F m_LocalMatrix;
		D2D1_MATRIX_3X2_F m_WorldMatrix;

	public:
		Collider(GameObject* owner);
		~Collider() override;

	public:
		void Initialize() override;
		void Render(D2DRender* renderer) override;

	public:
		virtual bool CheckCollision(Collider* other) abstract;

	public:
		void SetColliPosOffset(const Vector2& ColliOffset);
		void SetColliScaleOffset(const Vector2& ColliScale);

		Vector2 GetColliPosOffset() const { return m_ColliPosOffset; }
		Vector2 GetColliScaleOffset() const { return m_ColliScaleOffset; }

		Transform* GetOwnerTransform() const { return m_OwnerTransform; }
		D2D1_MATRIX_3X2_F GetMatrix() const { return m_WorldMatrix; }
		Vector2 GetSize() const { return m_Size; }
		void SetSize(Vector2 size) { m_Size = size; }

		void SetColliding(bool iscolliding);
		void SetCollisionState(CollisionState state);
		bool IsColliding() const;
		void ResetCollisionState();
	};
}
