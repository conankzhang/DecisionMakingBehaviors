#include "CanEatCharacerTask.h"

#include "../../Entity/Flock.h"

//=======================================================================================================================
CCanEatCharacerTask::CCanEatCharacerTask(size_t InTaskId, CFlock* InCharacter) :
	CTask(InTaskId),
	Character(InCharacter),
	Monster(nullptr)
{

}

//=======================================================================================================================
CCanEatCharacerTask::~CCanEatCharacerTask()
{
}

//=======================================================================================================================
EStatus CCanEatCharacerTask::OnExecute(CTick* InTick)
{
	if (!Character || !Monster)
	{
		return EStatus::FAILURE;
	}

	float Distance = (Character->GetCenterOfMass() - Monster->GetCenterOfMass()).length();

	if (fabsf(Distance) < 100)
	{
		return EStatus::SUCCESS;
	}

	return EStatus::FAILURE;

}
