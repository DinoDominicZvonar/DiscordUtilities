#pragma once
#include "Discord/include/discord_register.h"
#include "Discord/include/discord_rpc.h"

#define DU DiscordUtilities

namespace DiscordUtilities 
{
	class Discord
	{
	public:
		Discord() = delete;
		~Discord() = delete;

		/// <summary>
		/// Initializes the Discord Rich Presance
		/// </summary>
		/// <param name="someApplicationID">This is the [APPLICATION ID] found under General Information on your Discord application</param>
		static void Initialize(const char* someApplicationID);

		/// <summary>
		/// Initializes the Discord Rich Presance using a Steam ID
		/// </summary>
		/// <param name="someApplicationID">This is the [APPLICATION ID] found under General Information on your Discord application</param>
		static void Initialize(const char* someApplicationID, int someAutoRegisterValue, const char* someSteamID);

		/// <summary>
		/// Updates the Discord Rich Presance Text
		/// </summary>
		/// <param name="someState">the user's current party status EXAMPLE: "Playing Campaign", "Playing Solo", "In a Group"</param>
		/// <param name="someDetails">what the player is currently doing EXAMPLE: "In Queue", "Exploring a Cave", "Unranked PvP"</param>
		static void UpdateRPC(const char* someState, const char* someDetails);

		/// <summary>
		/// Updates the Discord Rich Presance Text and Images
		/// </summary>
		/// <param name="someState">the user's current party status EXAMPLE: "Playing Campaign", "Playing Solo", "In a Group"</param>
		/// <param name="someDetails">what the player is currently doing EXAMPLE: "In Queue", "Exploring a Cave", "Unranked PvP"</param>
		/// <param name="someLargeImageKey">name of the uploaded image for the large profile artwork EXAMPLE: "default"</param>
		/// <param name="someSmallImageKey">name of the uploaded image for the small profile artwork EXAMPLE: "rouge"</param>
		static void UpdateRPC(const char* someState, const char* someDetails, const char* someLargeImageKey, const char* someSmallImageKey);

		/// <summary>
		/// Updates the Discord Rich Presance Text and Images
		/// </summary>
		/// <param name="someState">the user's current party status EXAMPLE: "Playing Campaign", "Playing Solo", "In a Group"</param>
		/// <param name="someDetails">what the player is currently doing EXAMPLE: "In Queue", "Exploring a Cave", "Unranked PvP"</param>
		/// <param name="someLargeImageKey">name of the uploaded image for the large profile artwork EXAMPLE: "default"</param>
		static void UpdateRPC(const char* someState, const char* someDetails, const char* someLargeImageKey);

		/// <summary>
		/// Updates the Discord Rich Presance Text and Images
		/// </summary>
		/// <param name="someState">the user's current party status EXAMPLE: "Playing Campaign", "Playing Solo", "In a Group"</param>
		/// <param name="someDetails">what the player is currently doing EXAMPLE: "In Queue", "Exploring a Cave", "Unranked PvP"</param>
		/// <param name="someLargeImageKey">name of the uploaded image for the large profile artwork EXAMPLE: "default"</param>
		/// <param name="someSmallImageKey">name of the uploaded image for the small profile artwork EXAMPLE: "rouge"</param>
		/// <param name="someLargeImageText">tooltip for the largeImageKey EXAMPLE: "Blade's Edge Arena", "Numbani", "Danger Zone"</param>
		/// <param name="someSmallImageText">tooltip for the smallImageKey EXAMPLE: "Rogue - Level 100"</param>
		static void UpdateRPC(const char* someState, const char* someDetails, const char* someLargeImageKey, const char* someSmallImageKey, const char* someLargeImageText, const char* someSmallImageText);

		static void ResetStopwatch();

		/// <summary>
		/// Sets a Discord Rich Presance countdown by adding an ammount of time to the current time
		/// </summary>
		static void SetCountDown(const unsigned int someDays, const unsigned int someHours, const unsigned int someMinutes, const unsigned int someSeconds);

	private:
		static DiscordEventHandlers myHandler;
		static DiscordRichPresence myDiscordPresence;
	};
}