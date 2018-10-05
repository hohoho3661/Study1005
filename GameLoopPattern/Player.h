#pragma once

class Image;

class Player
{
	Image*	_siva;

	int		_nCount;
	int		_iIndex;

	int		_dirChange;

	POINT*	_pPos;

	int		indexBlend;
	int		nCount;
	int		colorTurnIndex;
public:		
	Player();
	virtual ~Player();	

	virtual void Update();
	virtual void Render(HDC hdc);

	//========== Ä«¸Þ¶ó ==============
		
	void SetPos(POINT* p) { _pPos = p; }
	POINT* GetPos() { return _pPos; }
};

