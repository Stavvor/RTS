#include "stdafx.h"
#include "SoundPlayer.h"


SoundPlayer::SoundPlayer()
{
	engine = irrklang::createIrrKlangDevice();
}


SoundPlayer::~SoundPlayer()
{
	engine->drop();
	//delete engine;//TODO obczaic czy drop napewno dobrze czysci...
}

void SoundPlayer::update3DPos(const vec3& pos, const vec3& dir, vec3 doppler, vec3 upvector)
{	
	irrklang::vec3df position(pos.x,pos.y,pos.z);        
	irrklang::vec3df lookDirection(dir.x,dir.y,dir.z); 
	irrklang::vec3df velPerSecond(0, 0, 0);   
	irrklang::vec3df upVector(0, 1, 0);
	//TODO lapac exception albo inaczej updatowac...
	engine->setListenerPosition(position, lookDirection, velPerSecond, upVector);
}

void SoundPlayer::loadAllSounds()
{
	terran1 = engine->addSoundSourceFromFile("resources\\sound\\terran1.flac");
	gatling = engine->addSoundSourceFromFile("resources\\sound\\gatling.mp3");
	//gatling->setDefaultVolume(0.5f); //TODO dopasowac glosnosc

	//TODO dodawac dzwieki
}

void SoundPlayer::playMusicirrklang(irrklang::ISoundSource* music,bool value)
{
	if (1)//TODO MENU tryb gry bla bla bla
	{
		if (!engine)
		{
			cout << "Error: Could not create Sound Engine" << endl;
			return;
		}
		engine->play2D(music, value);
	}
}

void SoundPlayer::playSound(irrklang::ISoundSource* sound)
{
	//TODO rozny track dla menu i dla gry...
	engine->stopAllSounds();
	engine->play2D(sound);
}

irrklang::ISound* SoundPlayer::play3DSound(irrklang::ISoundSource* sound,vec3 pos, float soundRange, irrklang::ISound* snd)
{
	
	irrklang::vec3df position(pos.x, pos.y, pos.z);

	snd = engine->play3D(sound, position, false, true);

	if (snd)
	{
		snd->setMinDistance(30.0f); // a loud sound
		snd->setIsPaused(false); // unpause the sound
	}
	return snd;
}
