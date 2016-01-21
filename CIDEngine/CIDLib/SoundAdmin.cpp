#include "SoundAdmin.h"

SoundAdmin::SoundAdmin()
{
}


SoundAdmin::~SoundAdmin()
{

}
void SoundAdmin::playBackgroundMusic(std::string path)
{
	std::string name;
	name = "open ";
	name += "Resource/";
	name += path;
	name += " type mpegvideo alias A";

	mciSendString(name.c_str(), NULL, NULL, NULL);

	mciSendString("play A notify repeat", NULL, NULL, NULL);
}

void SoundAdmin::playEffectMusic(std::string path)
{
	sndPlaySound(path.c_str(), SND_ASYNC);
}
