#pragma once
#include "Entity.h"
#include "EventHandler.h"

namespace McCol
{
	class GameObject;
	class D2DRender;

	class Scene : public Entity, public EventHandler
	{
	public:
		Scene(std::wstring_view sceneName);
		~Scene() override;

	protected:
		std::vector<std::list<GameObject*>> m_GameObjects;

	public:
		virtual void Enter() = 0;
		virtual void Exit() = 0;	// ��� Ŭ�������� Scene::Exit() ȣ��� m_GameObjects �� ������Ʈ ���� (���� ����)

		virtual void Update(const float& deltaTime);
		virtual void FixedUpdate(const float& deltaTime);
		virtual void LateUpdate(const float& deltaTime);
		virtual void Render(D2DRender* renderer);

		std::vector<std::list<GameObject*>>& GetContainer();
		static void EventCreateOBJ(GameObject* go);	// ���� ���� �̺�Ʈ ȣ�� (SceneSystem::DelayedCreate ����)
		static void EventDeleteOBJ(GameObject* go);	// ���� ���� �̺�Ʈ ȣ�� (SceneSystem::DelayedDelete ����)
	};
}


