#pragma once

#include "CID.h"

class SoundAdmin : public CSingleton<SoundAdmin>
{
private:

public:
	SoundAdmin();
	~SoundAdmin();

public:
	void playBackgroundMusic(std::string path);

	void playEffectMusic(std::string path);

};