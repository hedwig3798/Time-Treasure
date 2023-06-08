#pragma once
#include <fmod.hpp>
#include <iostream>
#include <conio.h>
#pragma comment(lib, "fmod_vc.lib")

#define SOUND_MAX 1.0f
#define SOUND_MIN 0.0f
#define SOUND_DEFAULT 0.5f
#define SOUND_WEIGHT 0.1f
enum SOUND_CHANNAL
{

	BGM,
	BGM1,
	EFFECT,
	END
};

enum SOUND
{
	//BACKGROUND_SOUND 1~5
	BACKGROUND_MAINTITLE,
	BACKGROUND_INGAME,
	BACKGROUND_ENDING,
	//EFFECT_SOUND
	COLLAPSE,

	//TRAP SOUND
	EFFECT_ARROW,
	EFFECT_FIRE,
	EFFECT_POISON,
	EFFECT_SPIKE_TRAP,
	//ACTION SOUND
	EFFECT_TIMETRAVEL,
	EFFECT_BUTTON_CHECK,
	EFFECT_BUTTON,
	//ENEMY SOUND 
	ENEMY_MOVE,
	ENEMY_DEAD,
	ENEMYGUARDIAN_HIT,
	ENEMYGUARDIAN_MOVE,
	//PLAYER SOUND
	PLAYER_MOVE,
	PLAYER_ATTACK,
	PLAYER_DEAD,
	PLAYER_ERROR,
	//STAGE 
	DEBUFF,
	DOOR,
	ROOM_CLEAR,
	ENDING,
	SOUND_END
};

class SoundManager
{



public:

	static SoundManager* instance;
	static SoundManager* GetInstance();
	void Init();									//�ʱ�ȭ	 
	void Loading();									//������ �ҷ�����
	void Play(SOUND _type, SOUND_CHANNAL _channal);	//���� ���
	void Pause(SOUND_CHANNAL _channal);				//���� �Ͻ�����
	void Resume(SOUND_CHANNAL _channal);			//���� �簳
	void Stop(SOUND_CHANNAL _channal);				//���� ����
	void Rlease();									//���� �޸� ����
	void ErrorCheck(FMOD_RESULT result);			//���� üũ
// 	void volumeup();
// 	void volumedown();
	void FinalRlease();								//����� �޸� ����
	~SoundManager();
private:
	FMOD::System* m_System;
	FMOD::Channel* m_channel[SOUND_CHANNAL::END];
	FMOD::Sound* m_sound[100];
	FMOD_RESULT result;
	float m_volume;
	FMOD_BOOL m_bool;
};