#ifndef GSE_GAME_REGISTER_H_
#define GSE_GAME_REGISTER_H_

#include <game_service/game_service/game_service_def.h>

GSE_NAMESPACE_BEGIN_DECL

class CGameRegister : public CSingleton< CGameRegister >
{
public:
    ///  ������Ϸ��Ϣ;
    void LoadGameInfo( void );
    ///  ������Ϸ��Ϣ;
    void UpdateGameInfo( CSString , sint32 );

    ///  ��Ϸ��Ϣ;
    SS_PROPERTY_QUOTE( RecordGameList , GameList , private );
};

#define GameRegister CGameRegister::getInstance()

GSE_NAMESPACE_END_DECL

#endif//GSE_GAME_REGISTER_H_