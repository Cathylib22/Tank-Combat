// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTankGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTankGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
    void ActorDied(AActor* DeadActor);

    UFUNCTION(BlueprintImplementableEvent)
    void StartGame();  //unnecessary to implement it in C++, do it in blueprint.
    
    UFUNCTION(BlueprintImplementableEvent)
    void GameOver(bool bWonGame);
    
protected:
    virtual void BeginPlay() override;

private:
    class ATank* Tank;
	class AToonTanksPlayerController* ToonTanksPlayerController;

    float StartDelay = 3.f;
    void HandleGameStart();

    int32 TargetTowers = 0;
    int32 GetTargetTowerCount();

};
