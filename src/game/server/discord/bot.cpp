/* # Discord # */
#include <game/server/gamecontext.h>

CGameContext *CGS;

CDiscordBot::CDiscordBot(CGameContext *GameServer, DiscordConfig Config)
{
    CGS = GameServer;
    m_Bot = new aegis::core(aegis::create_bot_t().log_level(spdlog::level::trace).token(Config.Token));

    m_Bot->wsdbg = true;

    m_Bot->set_on_ready([&](auto Ready)
    {
        m_Channel = m_Bot->find_guild(aegis::snowflake(Config.GuildID))->find_channel(aegis::snowflake(Config.ChannelID));
    });

    m_Bot->set_on_message_create([&](aegis::gateway::events::message_create Object)
    {
        std::string Content { Object.msg.get_content() };
        
        if(CGS && m_Channel && !Object.msg.is_bot())
            CGS->SendChatFromDiscord(Object.msg.author.username.c_str(), Content.c_str());
    });

    m_Bot->run();
}

void CDiscordBot::LogChat(int Team, std::string Nickname, std::string Message)
{
    if(!m_Channel || !m_Bot)
        return;

    if(Team == TEAM_RED)
        m_Channel->create_message("**[RED] " + Nickname + "**: " + Message);
    else if(Team == TEAM_BLUE)
        m_Channel->create_message("**[BLUE] " + Nickname + "**: " + Message);
    else if(Team == TEAM_SPECTATORS)
        m_Channel->create_message("**[SPEC] " + Nickname + "**: " + Message);
    else
        m_Channel->create_message("**" + Nickname + "**: " + Message);
}

void CDiscordBot::LogEnter(std::string Nickname)
{
    if(!m_Channel || !m_Bot)
        return;
    
    m_Channel->create_message("`##` **" + Nickname + "** has entered the game. `##`");
}

void CDiscordBot::LogExit(std::string Nickname)
{
    if(!m_Channel || !m_Bot)
        return;
    
    m_Channel->create_message("`##` **" + Nickname + "** has left the game. `##`");
}
/* # Discord # */
