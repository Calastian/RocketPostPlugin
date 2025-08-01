#include "pch.h"
#include "PostPlugin.h"


BAKKESMOD_PLUGIN(PostPlugin, "Post Plugin", "1.0", PERMISSION_ALL)

void PostPlugin::onLoad()
{
	// This is called when the plugin is loaded
	cvarManager->log("PostPlugin loaded");
	this->log("First Bakkesmod Plugin");
	this->loadHooks();

}

void PostPlugin::onUnload()
{
	// This is called when the plugin is unloaded
	cvarManager->log("PostPlugin unloaded");
}


void PostPlugin::loadHooks()
{
	this->gameWrapper = gameWrapper; // Store the game wrapper for later use
	if (gameWrapper)
	{
		// Register the game ended event
		gameWrapper->HookEvent("Function TAGame.GameEvent_Soccar_TA.EventGameEnded", [this](std::string eventName) {
			this->gameEndedEvent(eventName);
		});
		cvarManager->log("Hooks loaded successfully");
	}
	else
	{
		cvarManager->log("Failed to load hooks: GameWrapper is null");
	}
}


void PostPlugin::gameEndedEvent(std::string name)
{
	// This is called when the game ends
	cvarManager->log("Game ended: " + name);
	// You can add your custom logic here
}


void PostPlugin::log(std::string msg)
{
	cvarManager->log(msg); 
}


