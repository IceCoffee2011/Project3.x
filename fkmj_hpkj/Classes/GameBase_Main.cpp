#include "GameBase.h"

#include "GameLib.h"
#include "ScenceManagerBase.h"
#include "GameManagerBase.h"


//������Ϸ
bool GameBase::SetupGameClient()
{
	return true;
}
//������Ϸ
void GameBase::ResetGameClient()
{
	return;
}
//�ر���Ϸ
void GameBase::CloseGameClient()
{
	ExitGame();
	return;
}