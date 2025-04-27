#include "pch.h"
#include "CScene.h"

CScene::CScene()
	:m_pPlayer(nullptr), m_pNext(nullptr)
{
}

CScene::~CScene()
{
	Release();
}

void CScene::Initialize()
{
}

void CScene::Update()
{
}

void CScene::Release()
{
	m_pPlayer = nullptr;
}

void CScene::Render()
{
}
