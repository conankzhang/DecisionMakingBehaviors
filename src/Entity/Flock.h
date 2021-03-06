#pragma once

#include "../Movement/Behavior.h"

#include "ofColor.h"

#include <vector>
#include "../Actions/ActionManager.h"

class CBoid;
class CDecisionMakingBehavior;

//=======================================================================================================================
enum class EBehavior
{
	NONE,
	FOLLOW,
	WANDER,
};

//=======================================================================================================================
class CFlock
{
public:
	CFlock(int InFlockCount, const std::vector<SWeightedBehavior*>& InWeightedBehaviors, const ofColor& InColor, CDecisionMakingBehavior* InDecisionMakingBehavior, const ofVec2f& InInitialPosition);
	~CFlock();

	void Update(double DeltaTime);
	void Draw() const;

	const std::vector<CBoid *>* GetBoids() const { return &Boids; }
	const ofVec2f& GetCenterOfMass() const { return CenterOfMass; }

	void SetBehavior(EBehavior InBehavior);
	inline EBehavior GetBehavior() const { return Behavior; }

	void ResetPosition();

private:
	const ofColor& FlockColor;
	void UpdateCenterOfMass();
	SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid);

	ofVec2f CenterOfMass;
	ofVec2f InitialPosition;

	std::vector<CBoid *> Boids;
	const std::vector<SWeightedBehavior*>& WeightedBehaviors;

	CDecisionMakingBehavior* DecisionMakingBehavior;
	CActionManager ActionManager;

	EBehavior Behavior;
	bool bIsMonster;
};
