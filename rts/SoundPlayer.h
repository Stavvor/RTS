#pragma once
class SoundPlayer
{
private:
	
public:
	SoundPlayer();
	~SoundPlayer();
	void update3DPos(const vec3& pos, const vec3& dir, vec3 doppler, vec3 upvector);


	irrklang::ISoundSource* terran1;
	irrklang::ISoundSource* gatling;


	void loadAllSounds();
	void playMusicirrklang(irrklang::ISoundSource* music, bool value);
	void playSound(irrklang::ISoundSource* sound);
	irrklang::ISound* play3DSound(irrklang::ISoundSource* sound, vec3 pos, float soundRange, irrklang::ISound* snd);
	irrklang::ISoundEngine* engine;

};

