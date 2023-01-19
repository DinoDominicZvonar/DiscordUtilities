#include "DiscordUtilities.h"
#include <cstring>
#include <time.h>

DiscordEventHandlers DiscordUtilities::Discord::myHandler;
DiscordRichPresence DiscordUtilities::Discord::myDiscordPresence;

void DiscordUtilities::Discord::Initialize(const char* someApplicationID)
{
	memset(&myHandler, 0, sizeof(myHandler));
	Discord_Initialize(someApplicationID, &myHandler, 1, NULL);
	memset(&myDiscordPresence, 0, sizeof(myDiscordPresence));
}

void DiscordUtilities::Discord::Initialize(const char* someApplicationID, int someAutoRegisterValue, const char* someSteamID)
{
	memset(&myHandler, 0, sizeof(myHandler));
	Discord_Initialize(someApplicationID, &myHandler, someAutoRegisterValue, someSteamID);
	memset(&myDiscordPresence, 0, sizeof(myDiscordPresence));
}

void DiscordUtilities::Discord::UpdateRPC(const char* someState, const char* someDetails)
{
	myDiscordPresence.details = someDetails;
	myDiscordPresence.state = someState;
	Discord_UpdatePresence(&myDiscordPresence);
}

void DiscordUtilities::Discord::UpdateRPC(const char* someState, const char* someDetails, const char* someLargeImageKey, const char* someSmallImageKey)
{
	myDiscordPresence.details = someDetails;
	myDiscordPresence.state = someState;
	myDiscordPresence.largeImageKey = someLargeImageKey;
	myDiscordPresence.smallImageKey = someSmallImageKey;
	Discord_UpdatePresence(&myDiscordPresence);
}

void DiscordUtilities::Discord::UpdateRPC(const char* someState, const char* someDetails, const char* someLargeImageKey)
{
	myDiscordPresence.details = someDetails;
	myDiscordPresence.state = someState;
	myDiscordPresence.largeImageKey = someLargeImageKey;
	Discord_UpdatePresence(&myDiscordPresence);
}

void DiscordUtilities::Discord::UpdateRPC(const char* someState, const char* someDetails, const char* someLargeImageKey, const char* someSmallImageKey, const char* someLargeImageText, const char* someSmallImageText)
{
	myDiscordPresence.details = someDetails;
	myDiscordPresence.state = someState;
	myDiscordPresence.largeImageKey = someLargeImageKey;
	myDiscordPresence.smallImageKey = someSmallImageKey;
	myDiscordPresence.largeImageText = someLargeImageText;
	myDiscordPresence.smallImageText = someSmallImageText;
	Discord_UpdatePresence(&myDiscordPresence);
}

void DiscordUtilities::Discord::ResetStopwatch()
{
	myDiscordPresence.startTimestamp = time(0);
	Discord_UpdatePresence(&myDiscordPresence);
}

void DiscordUtilities::Discord::SetCountDown(const unsigned int someDays, const unsigned int someHours, const unsigned int someMinutes, const unsigned int someSeconds)
{
	int64_t unixTimeToAdd{};

	unixTimeToAdd += (someDays * static_cast<unsigned int>(86400));
	unixTimeToAdd += (someHours * static_cast<unsigned int>(3600));
	unixTimeToAdd += (someMinutes * static_cast<unsigned int>(60));
	unixTimeToAdd += someSeconds;

	myDiscordPresence.startTimestamp = time(0);
	myDiscordPresence.endTimestamp = (time(0) + unixTimeToAdd);
	Discord_UpdatePresence(&myDiscordPresence);
}