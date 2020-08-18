/* # Discord # */
#ifndef GAME_SERVER_DISCORD_BOT_H
#define GAME_SERVER_DISCORD_BOT_H

#include <aegis.hpp>

struct DiscordConfig
{
    std::string Token;
    std::string GuildID;
    std::string ChannelID;
};

class CDiscordBot
{
public:
    CDiscordBot(CGameContext *GameServer, DiscordConfig Config);
    void LogChat(int Team, std::string Nickname, std::string Message);
    void LogEnter(std::string Nickname);
    void LogExit(std::string Nickname);
private:
    aegis::core *m_Bot;
    aegis::channel *m_Channel;
};

#endif
/* # Discord # */