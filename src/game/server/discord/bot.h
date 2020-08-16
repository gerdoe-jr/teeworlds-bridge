/* # Discord # */
#ifndef GAME_SERVER_DISCORD_BOT_H
#define GAME_SERVER_DISCORD_BOT_H

#include <aegis.hpp>

class CDiscordBot
{
public:
    CDiscordBot(CGameContext *GameServer, std::string Token, std::string ChannelID);
    void LogChat(int Team, std::string Nickname, std::string Message);
    void LogEnter(std::string Nickname);
    void LogExit(std::string Nickname);
private:
    aegis::core *m_Bot;
    aegis::channel *m_Channel;
};

#endif
/* # Discord # */