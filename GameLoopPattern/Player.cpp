#include "stdafx.h"
#include "Player.h"



Player::Player()
{
	_siva = IMAGEMANAGER->findImage(TEXT("Player"));
	assert(_siva != NULL);

	_pPos = new POINT;
	_pPos->x = WINSIZEX/2;
	_pPos->y = WINSIZEY-100;

	indexBlend = 0;
	nCount = 10;
	colorTurnIndex = 1;
}


Player::~Player()
{
}

void Player::Update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{

		_pPos->x -= SIVASPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{

		_pPos->x += SIVASPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{

		_pPos->y -= SIVASPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{

		_pPos->y += SIVASPEED;
	}
	
	// 점점나오기
	if (indexBlend < 255)
	{
		indexBlend++;
	}
	
	// 반짝거리기
	//nCount++;
	//if (nCount % 2 == 1)
	//	indexBlend = 0;
	//else
	//	indexBlend = 254;
	

	// 점점나왔다가 점점사라지기	
	//if (nCount == 254 || nCount == 1)
	//	colorTurnIndex *= -1;

	//if (colorTurnIndex == 1)
	//	nCount++;
	//if (colorTurnIndex == -1)
	//	nCount--;

	//indexBlend = nCount;



	//_pPos->x = _siva->GetX();
	//_pPos->y = _siva->GetY();


}

void Player::Render(HDC hdc)
{
	// 베이스클래스에서                        ->                 CAMERA->getPosition()
	// 객체를 받아서 한번에 랜더

	//_siva->FrameRender(hdc,
#if defined(_CAMERA_TEST)
//	_pPos->x - CAMERA->getPosition()->x,
//		_pPos->y - CAMERA->getPosition()->y,
#else
//	_pPos->x,
//		_pPos->y,
#endif // #if defined(_CAMETA_TEST)
	//	_siva->GetFrameX(), _siva->GetFrameY());
	


	//======================================================================================================



	_siva->AlphaRender(hdc,
#if defined(_CAMERA_TEST)
		_pPos->x - CAMERA->getPosition()->x,
		_pPos->y - CAMERA->getPosition()->y,
#else
		_pPos->x,
		_pPos->y,
#endif // #if defined(_CAMETA_TEST)
		_siva->GetFrameX(), _siva->GetFrameY(), indexBlend);

}
