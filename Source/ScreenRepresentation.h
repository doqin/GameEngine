#pragma once
#include "GameObject.h"
#include "Sprite.h"
struct ScreenRepresentation{
	GameObject* entity;
	Sprite* entitySprite;
	ScreenRepresentation() {
		entity = nullptr;
		entitySprite = nullptr;
	}
	ScreenRepresentation(GameObject* entity, Sprite* entitySprite) {
		this->entity = entity;
		this->entitySprite = entitySprite;
	}
};