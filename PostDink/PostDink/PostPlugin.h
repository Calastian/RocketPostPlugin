#pragma once
#include "bakkesmod/plugin/bakkesmodplugin.h"

#pragma comment(lib, "PostDink.lib")

class PostPlugin : public BakkesMod::Plugin::BakkesModPlugin
{
public:
	PostPlugin();
	virtual ~PostPlugin();
	virtual void onLoad() override;
	virtual void onUnload() override;

	void loadHooks();
	void gameEndedEvent(std::string name);



private:
	void log(std::string msg);
	GameWrapper* gameWrapper;
};

